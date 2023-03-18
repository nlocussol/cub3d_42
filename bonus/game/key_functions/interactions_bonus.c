/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:21:26 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:58:22 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

t_double_list	*create_graff(t_raycast *raycast)
{
	t_graff			*new_graff;
	t_double_list	*new_elt;

	new_graff = malloc(sizeof(t_graff));
	if (!new_graff)
		return (NULL);
	new_graff->x = raycast->map_x;
	new_graff->y = raycast->map_y;
	if (raycast->side == 0 && raycast->step_x == 1)
		new_graff->direction = 'S';
	if (raycast->side == 0 && raycast->step_x == -1)
		new_graff->direction = 'N';
	else if (raycast->side == 1 && raycast->step_y == 1)
		new_graff->direction = 'E';
	else if (raycast->side == 1 && raycast->step_y == -1)
		new_graff->direction = 'O';
	new_graff->frame = 0;
	new_graff->last_frame_changed = calculate_time() + 2500;
	new_graff->time_start = calculate_time();
	new_elt = ft_double_lstnew(new_graff);
	if (!new_elt)
		free(new_graff);
	if (!new_elt)
		return (NULL);
	return (new_elt);
}

void	open_or_close_door(t_game *game, t_raycast *raycast, int mode)
{
	t_anim			*new_anim;
	t_double_list	*new_elt;

	if (find_square_anim(game, raycast->map_x, raycast->map_y))
		suppress_node_anim(game, raycast->map_x, raycast->map_y);
	new_anim = malloc(sizeof(t_anim));
	if (!new_anim)
		return ;
	launch_song(game, DOOR);
	new_anim->x = raycast->map_x;
	new_anim->y = raycast->map_y;
	new_anim->time_anim_start = calculate_time();
	new_elt = ft_double_lstnew(new_anim);
	ft_double_lstadd_back(&game->lst_anim, new_elt);
	if (mode == OPEN)
		game->map[raycast->map_x][raycast->map_y] = 'O';
	else if (mode == CLOSE)
		game->map[raycast->map_x][raycast->map_y] = 'o';
}

void	choose_interaction_next(t_game *game, t_raycast *raycast)
{
	if (game->bar_index == SPONGE
		&& ft_strchr("1D", game->map[raycast->map_x][raycast->map_y])
		&& find_square_graff(game, raycast))
	{
		suppress_node_graff(game, raycast);
		game->nb_graff += 1;
	}
}

void	choose_interaction(t_game *game, t_raycast *raycast)
{
	t_double_list	*new_elt;

	if (game->bar_index == KEYCARD
		&& game->map[raycast->map_x][raycast->map_y] == 'D')
		open_or_close_door(game, raycast, OPEN);
	else if (game->bar_index == KEYCARD
		&& game->map[raycast->map_x][raycast->map_y] == 'd')
		open_or_close_door(game, raycast, CLOSE);
	else if (game->bar_index == BOMB_SPRAY
		&& ft_strchr("1D", game->map[raycast->map_x][raycast->map_y])
		&& game->nb_graff != 0 && !find_square_graff(game, raycast))
	{
		launch_song(game, SPRAY);
		new_elt = create_graff(raycast);
		if (new_elt)
		{
			ft_double_lstadd_back(&game->lst_graff, new_elt);
			game->nb_graff -= 1;
		}
	}
	else
		choose_interaction_next(game, raycast);
}

void	interact(t_game *game, int *mouse_pos_x, int *mouse_pos_y)
{
	t_raycast		raycast;

	raycast.pos_x = game->player->x / SIZE_BLOCK;
	raycast.pos_y = game->player->y / SIZE_BLOCK;
	raycast.dir_x = cos(radian_value(game->player->orientation));
	raycast.dir_y = sin(radian_value(game->player->orientation));
	raycast.plane_x = cos(radian_value(game->player->orientation + 90));
	raycast.plane_y = sin(radian_value(game->player->orientation + 90));
	calculate_delta_and_dist(WIDTH_SCREEN / 2, &raycast);
	detect_wall(game, &raycast);
	calculate_dist_perp_wall(game, &raycast);
	if (game->bar_index == GAMEBOY)
	{
		mlx_mouse_get_pos(game->mlx, game->window,
			mouse_pos_x, mouse_pos_y);
		game->started_gameboy = true;
		launch_song(game, START_GAMEBOY);
		anim_start_gameboy(NULL);
	}
	if (raycast.dist_perp_wall > (double)1)
		return ;
	else
		choose_interaction(game, &raycast);
}
