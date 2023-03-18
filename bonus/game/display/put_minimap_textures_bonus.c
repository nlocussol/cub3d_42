/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minimap_textures_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:40:17 by nlocusso          #+#    #+#             */
/*   Updated: 2023/03/18 13:02:07 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	put_one_block(t_game *game, unsigned int color)
{
	int				x;
	int				y;

	x = game->x_minimap;
	while (x < game->x_minimap + 16)
	{
		y = game->y_minimap;
		while (y < game->y_minimap + 16)
		{
			my_mlx_pixel_put(game->screen_img, y, x, color);
			y++;
		}
		x++;
	}
}

void	put_assets(t_game *game, unsigned int **color)
{
	int				x;
	int				y;

	x = game->x_minimap;
	while (x < game->x_minimap + 16)
	{
		y = game->y_minimap;
		while (y < game->y_minimap + 16)
		{
			my_mlx_pixel_put(game->screen_img, y, x,
				color[x - game->x_minimap][y - game->y_minimap]);
			y++;
		}
		x++;
	}
}

int	calculate_arrow(int a, int b, int mode)
{
	if (mode == 1)
		return ((a - b) / 2);
	else
		return ((b - a + 16) / 2);
}

void	put_cursor_bis(t_game *game, int x_minimap, int y_minimap)
{
	if (game->player->orientation >= 135
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
	else
		put_cursor_bis(game, x_minimap, y_minimap);
}
