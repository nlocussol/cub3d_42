/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:21:26 by averdon           #+#    #+#             */
/*   Updated: 2023/01/31 15:43:20 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	interact(t_game *game)
{
	t_raycast	raycast;
	long		time_start_anim;
	long		actual_time;

	raycast.pos_x = game->player->x / SIZE_BLOCK;
	raycast.pos_y = game->player->y / SIZE_BLOCK;
	raycast.dir_x = cos(radian_value(game->player->orientation));
	raycast.dir_y = sin(radian_value(game->player->orientation));
	raycast.plane_x = cos(radian_value(game->player->orientation + 90));
	raycast.plane_y = sin(radian_value(game->player->orientation + 90));
	calculate_delta_and_dist(WIDTH_SCREEN / 2, &raycast);
	detect_wall(game, &raycast);
	calculate_dist_perp_wall(&raycast);
	if (raycast.dist_perp_wall > (double)1)
		return ;
	if (game->map[raycast.map_x][raycast.map_y] == 'D')
	{
		game->anim_start = true;
		time_start_anim = calculate_time();
		actual_time = time_start_anim;
		while (actual_time - time_start_anim < 2000)
		{
			actual_time = calculate_time();
			display_screen(game, 1);
		}
		game->map[raycast.map_x][raycast.map_y] = 'd';
		game->anim_start = false;
	}
	else if (game->map[raycast.map_x][raycast.map_y] == 'd')
	{
		game->map[raycast.map_x][raycast.map_y] = 'D';
	}
	/*
	else if (game->map[raycast.map_x][raycast.map_y] == '1')
		add_graffiti(game);
	*/
}
