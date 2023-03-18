/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:36:40 by nlocusso          #+#    #+#             */
/*   Updated: 2023/03/18 12:59:14 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	put_arrow(t_game *game, int i_minimap, int j_minimap, int mode)
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

void	put_pixel_color(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		put_assets(game, game->minimap_img[1]);
	else if (ft_strchr("NSEW0", game->map[x][y]))
		put_assets(game, game->minimap_img[0]);
	else if (ft_strchr("D", game->map[x][y]))
		put_assets(game, game->minimap_img[2]);
	else if (ft_strchr("doO", game->map[x][y]))
		put_assets(game, game->minimap_img[3]);
	if (x == (int)(game->player->x / SIZE_BLOCK)
		&& y == (int)(game->player->y / SIZE_BLOCK))
		put_one_block(game, 0xF70707);
}

int	set_value(double player, int *game, int *y)
{
	int	value_y;

	*game = 20;
	*y = (int)(player / SIZE_BLOCK) - 5;
	if (*y < 0)
	{
		value_y = 6 - *y;
		*y = 0;
	}
	else
		value_y = 6;
	return (value_y);
}

void	open_minimap(t_game *game)
{
	int			x;
	int			y;
	int			value_x;
	int			value_y;

	value_x = set_value(game->player->x, &game->x_minimap, &x);
	while (x < (int)(game->player->x / SIZE_BLOCK + value_x) && game->map[x])
	{
		value_y = set_value(game->player->y, &game->y_minimap, &y);
		while (y < (int)(game->player->y / SIZE_BLOCK + value_y)
			&& game->map[x][y])
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

void	move_bar(t_game *game)
{
	if (game->bar_index == 1)
		game->minimap = 1;
	else
		game->minimap = 0;
}
