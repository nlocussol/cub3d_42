/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:21:26 by averdon           #+#    #+#             */
/*   Updated: 2023/02/02 09:42:03 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "game.h"

void	interact(t_game *game)
{
	t_anim			new_anim;
	t_double_list	*new_elt;
	t_raycast		raycast;

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
		new_anim.x = raycast.map_x;
		new_anim.y = raycast.map_y;
		new_anim.time_anim_start = calculate_time();
		new_elt = ft_double_lstnew(&new_anim);
		ft_double_lstadd_back(&game->lst_anim, new_elt);
		game->map[raycast.map_x][raycast.map_y] = 'O';
	}
	else if (game->map[raycast.map_x][raycast.map_y] == 'd')
	{
		new_anim.x = raycast.map_x;
		new_anim.y = raycast.map_y;
		new_anim.time_anim_start = calculate_time();
		new_elt = ft_double_lstnew(&new_anim);
		ft_double_lstadd_back(&game->lst_anim, new_elt);
		game->map[raycast.map_x][raycast.map_y] = 'o';
	}
	/*
	else if (game->map[raycast.map_x][raycast.map_y] == '1')
		add_graffiti(game);
	*/
}
