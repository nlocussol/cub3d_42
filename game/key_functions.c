/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:46:41 by averdon           #+#    #+#             */
/*   Updated: 2023/01/19 22:33:52 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_player(t_game	*game, int move)
{
	game->player->x += move * abs_value(cos(game->player->orientation * M_PI / 180));
	game->player->y += move * abs_value(sin(game->player->orientation * M_PI / 180));
}

void	turn_camera(t_game	*game, int move)
{
	game->player->orientation = (game->player->orientation + move) % 360;
	if (game->player->orientation < 0)
		game->player->orientation = 359;
}
