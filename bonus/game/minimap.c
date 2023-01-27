/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:36:40 by nlocusso          #+#    #+#             */
/*   Updated: 2023/01/27 16:32:52 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_one_block(t_game *game, int color)
{
	int	x;
	int	y;

	x = game->x_map;
	while (x < game->x_map + 16)
	{
		y = game->y_map;
		while (y < game->y_map + 16)
		{
			my_mlx_pixel_put(game->screen_img, y, x, color);
			y++;
		}
		x++;
	}
}

void	put_pixel_color(t_game *game, int x, int y)
{
	if (x == (int)(game->player->x / SIZE_BLOCK)
		&& y == (int)(game->player->y / SIZE_BLOCK))
		put_one_block(game, 0xFF0101);
	else if (game->map[x][y] == '1' || game->map[x][y] == '\0')
		put_one_block(game, 0);
	else if (game->map[x][y] == '0')
		put_one_block(game, 0xFFFFFF);
	else if (ft_strchr("NSEW", game->map[x][y]))
		put_one_block(game, 0x00FF00);
	else if (ft_strchr("Dd", game->map[x][y]))
		put_one_block(game, 0x0000FF);
	else
		put_one_block(game, 0);
}

void	open_minimap(t_game *game)
{
	int	x;
	int	y;
	int	value_x;
	int	value_y;

	if (WIDTH_SCREEN < (16 * 11 + 10) || HEIGHT_SCREEN < (16 * 11 + 10))
		return ;
	game->x_map = 10;
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
		game->y_map = WIDTH_SCREEN - (16 * 11 + 10);
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
			y++;
			game->y_map += 16;
		}
		x++;
		game->x_map += 16;
	}
}
