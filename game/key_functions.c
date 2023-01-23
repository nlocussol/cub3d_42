/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:46:41 by averdon           #+#    #+#             */
/*   Updated: 2023/01/23 18:23:18 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_player(t_game	*game, int keycode)
{
	if (keycode == W)
	{
		game->player->x += 10 * (cos(radian_value(game->player->orientation)));
		game->player->y += 10 * (sin(radian_value(game->player->orientation)));
	}
	else if (keycode == S)
	{
		game->player->x -= 10 * (cos(radian_value(game->player->orientation)));
		game->player->y -= 10 * (sin(radian_value(game->player->orientation)));
	}
	else if (keycode == D)
	{
		game->player->x -= 10 * (sin(radian_value(game->player->orientation)));
		game->player->y += 10 * (cos(radian_value(game->player->orientation)));
	}
	else if (keycode == A)
	{
		game->player->x += 10 * (sin(radian_value(game->player->orientation)));
		game->player->y -= 10 * (cos(radian_value(game->player->orientation)));
	}
}

void	turn_camera(t_game	*game, int move)
{
	game->player->orientation = (game->player->orientation + move) % 360;
	if (game->player->orientation < 0)
		game->player->orientation = 359;
}
