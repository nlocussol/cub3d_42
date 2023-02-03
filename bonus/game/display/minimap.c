/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:36:40 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/03 13:20:10 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_one_block(t_game *game, unsigned int color)
{
	int				x;
	int				y;
	unsigned int	color_screen;

	x = game->x_minimap;
	while (x < game->x_minimap + 16)
	{
		y = game->y_minimap;
		while (y < game->y_minimap + 16)
		{
			color_screen = calculate_color(x - game->x_minimap, y - game->y_minimap, game->screen_img);
			if (color != color_screen)
				my_mlx_pixel_put(game->screen_img, y, x, color);
			y++;
		}
		x++;
	}
}

void	put_assets(t_game *game, char *image)
{
	t_img			img;
	int				x;
	int				y;
	unsigned int	color;
	unsigned int	color_screen;

	x = game->x_minimap;
	img.img = mlx_xpm_file_to_image(game->mlx, image, &img.height, &img.width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	while (x < game->x_minimap + 16)
	{
		y = game->y_minimap;
		while (y < game->y_minimap + 16)
		{
			color = calculate_color(x - game->x_minimap, y - game->y_minimap, &img);
			color_screen = calculate_color(x - game->x_minimap, y - game->y_minimap, game->screen_img);
			if (color != color_screen)
				my_mlx_pixel_put(game->screen_img, y, x, color);
			y++;
		}
		x++;
	}
	mlx_destroy_image(game->mlx, img.img);
}

int	calculate_arrow(int	a, int b, int mode)
{
	if (mode == 1)
		return ((a - b) / 2);
	else
		return ((b - a + 16) / 2);
}

void	put_arrow(t_game *game, int	i_minimap, int	j_minimap, int mode)
{
	int	x;
	int	y;

	x = i_minimap;
	while (x < i_minimap + 16)
	{
		y = j_minimap + calculate_arrow(x, i_minimap, mode);
		while (y < j_minimap + 16 - calculate_arrow(x, i_minimap, mode))
		{
			if (game->y_minimap == j_minimap)
				my_mlx_pixel_put(game->screen_img, y, x, 0x00ffd8);
			else
				my_mlx_pixel_put(game->screen_img, x, y, 0x00ffd8);
			y++;
		}
		x++;
	}
}

void	put_cursor(t_game *game, int x, int y)
{
	static int	x_minimap;
	static int	y_minimap;

	if (!game)
	{
		x_minimap = x;
		y_minimap = y;
		return ;
	}
	if (game->player->orientation >= 45 && game->player->orientation <= 135)
	{
		game->x_minimap = x_minimap;
		game->y_minimap = y_minimap + 16;
		put_arrow(game, game->y_minimap, game->x_minimap, 1);
	}
	else if (game->player->orientation >= 135
		&& game->player->orientation <= 225)
	{
		game->x_minimap = x_minimap - 16;
		game->y_minimap = y_minimap;
		put_arrow(game, game->x_minimap, game->y_minimap, 0);
	}
	else if (game->player->orientation >= 225
		&& game->player->orientation <= 315)
	{
		game->x_minimap = x_minimap;
		game->y_minimap = y_minimap - 16;
		put_arrow(game, game->y_minimap, game->x_minimap, 0);
	}
	else
	{
		game->x_minimap = x_minimap + 16;
		game->y_minimap = y_minimap;
		put_arrow(game, game->x_minimap, game->y_minimap, 1);
	}
}

void	put_pixel_color(t_game *game, int x, int y)
{
	if (x == (int)(game->player->x / SIZE_BLOCK)
		&& y == (int)(game->player->y / SIZE_BLOCK))
		put_one_block(game, 0xFF0101);
	else if (game->map[x][y] == '1' || game->map[x][y] == '\0')
		put_assets(game, "assets/minimap/wall.xpm");
	else if (game->map[x][y] == '0')
		put_assets(game, "assets/minimap/floor.xpm");
	else if (ft_strchr("NSEW", game->map[x][y]))
		put_one_block(game, 0x00FF00);
	else if (ft_strchr("DdoO", game->map[x][y]))
		put_one_block(game, 0x0000FF);
	else
		put_one_block(game, 0);
}
void	open_minimap(t_game *game)
{
	int			x;
	int			y;
	int			value_x;
	int			value_y;

	if (WIDTH_SCREEN < (16 * 11 + 10) || HEIGHT_SCREEN < (16 * 11 + 10))
		return ;
	game->x_minimap = 10;
	x = (int)(game->player->x / SIZE_BLOCK) - 5;
	if (x < 0)
	{
		value_x = 6 - x;
		x = 0;
	}
	else
		value_x = 6;
	while (x < (int)(game->player->x / SIZE_BLOCK + value_x))
	{
		game->y_minimap = WIDTH_SCREEN - (16 * 11 + 10);
		y = (int)(game->player->y / SIZE_BLOCK) - 5;
		if (y < 0)
		{
			value_y = 6 - y;
			y = 0;
		}
		else
			value_y = 6;
		while (y < (int)(game->player->y / SIZE_BLOCK + value_y))
		{
			put_pixel_color(game, x, y);
			if (x == (int)(game->player->x / SIZE_BLOCK)
				&& y == (int)(game->player->y / SIZE_BLOCK))
				put_cursor(NULL, game->x_minimap, game->y_minimap);
			y++;
			game->y_minimap += 16;
		}
		x++;
		game->x_minimap += 16;
	}
	put_cursor(game, 0, 0);
}
