/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:46:41 by averdon           #+#    #+#             */
/*   Updated: 2023/01/26 13:26:18 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	hit_map_border_forward_backward(t_game *game, int coeff,
		double function_x(double), double function_y(double))
{
	int	x;
	int	y;

	x = coeff * 10 * (function_x(radian_value(game->player->orientation)));
	x = (game->player->x + x) / SIZE_BLOCK;
	y = coeff * 10 * (function_y(radian_value(game->player->orientation)));
	y = (game->player->y + y) / SIZE_BLOCK;
	if (game->map[x][y] == '2')
		return (1);
	return (0);
}

int	hit_map_border_left_right(t_game *game, int coeff,
		double function_x(double), double function_y(double))
{
	if (game->map[(int)(game->player->x - coeff * 10 * (function_x(radian_value(game->player->orientation)))) / SIZE_BLOCK][(int)(game->player->y + coeff * 10 * (function_y(radian_value(game->player->orientation)))) / SIZE_BLOCK] == '2')
		return (1);
	return (0);
}

void	move_player(t_game	*game, int keycode)
{
	if (keycode == W)
	{
		if (!hit_map_border_forward_backward(game, 1, cos, sin))
		{
			game->player->x += 10 * (cos(radian_value(game->player->orientation)));
			game->player->y += 10 * (sin(radian_value(game->player->orientation)));
		}
	}
	else if (keycode == S)
	{
		if (!hit_map_border_forward_backward(game, -1, cos, sin))
		{
			game->player->x -= 10 * (cos(radian_value(game->player->orientation)));
			game->player->y -= 10 * (sin(radian_value(game->player->orientation)));
		}
	}
	else if (keycode == D)
	{
		if (!hit_map_border_left_right(game, 1, sin, cos))
		{
			game->player->x -= 10 * (sin(radian_value(game->player->orientation)));
			game->player->y += 10 * (cos(radian_value(game->player->orientation)));
		}
	}
	else if (keycode == A)
	{
		if (!hit_map_border_left_right(game, -1, sin, cos))
		{
			game->player->x += 10 * (sin(radian_value(game->player->orientation)));
			game->player->y -= 10 * (cos(radian_value(game->player->orientation)));
		}
	}
}

void	turn_camera(t_game	*game, int move)
{
	game->player->orientation = (game->player->orientation + move) % 360;
	if (game->player->orientation < 0)
		game->player->orientation = 360 + game->player->orientation;
}
