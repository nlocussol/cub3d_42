/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:21:26 by averdon           #+#    #+#             */
/*   Updated: 2023/01/27 10:57:15 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	interact(t_game *game)
{
	t_raycast	raycast;

	raycast.pos_x = game->player->x / SIZE_BLOCK;
	raycast.pos_y = game->player->y / SIZE_BLOCK;
	raycast.dir_x = cos(radian_value(game->player->orientation));
	raycast.dir_y = sin(radian_value(game->player->orientation));
	raycast.plane_x = cos(radian_value(game->player->orientation + 90));
	raycast.plane_y = sin(radian_value(game->player->orientation + 90));
	calculate_delta_and_dist(WIDTH_SCREEN / 2, &raycast);
	detect_wall(game, &raycast);
	if (game->map[raycast.map_x][raycast.map_y] == 'D')
	{
		calculate_dist_perp_wall(&raycast);
		if ((int)raycast.dist_perp_wall <= 1)
			game->map[raycast.map_x][raycast.map_y] = 'd';
	}
	else if (game->map[raycast.map_x][raycast.map_y] == 'd')
	{
		calculate_dist_perp_wall(&raycast);
		if ((int)raycast.dist_perp_wall <= 1)
			game->map[raycast.map_x][raycast.map_y] = 'D';
	}
}
