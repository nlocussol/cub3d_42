/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:21:26 by averdon           #+#    #+#             */
/*   Updated: 2023/02/02 14:38:18 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_anim *find_square(t_game *game, int x, int y)
{
	t_double_list	*buffer;

	buffer = game->lst_anim;
	while (buffer)
	{
		if (((t_anim *)(buffer->content))->x == x
			&& ((t_anim *)(buffer->content))->y == y)
			return (buffer->content);
		buffer = buffer->next;
	}
	return (NULL);
}

void	suppress_node(t_game *game, int x, int y)
{
	t_double_list	*buffer;

	buffer = game->lst_anim;
	while (buffer)
	{
		if (((t_anim *)(buffer->content))->x == x
			&& ((t_anim *)(buffer->content))->y == y)
		{
			if (buffer->previous)
				buffer->previous->next = buffer->next;
			else
				game->lst_anim = buffer->next;
			if (buffer->next)
				buffer->next->previous = buffer->previous;
			if (!buffer->previous && !buffer->next)
				game->lst_anim = NULL;
		}
		buffer = buffer->next;
	}
}
void	interact(t_game *game)
{
	t_anim			*new_anim;
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
		if (find_square(game, raycast.map_x, raycast.map_y))
			suppress_node(game, raycast.map_x, raycast.map_y);
		new_anim = malloc(sizeof(t_anim));
		new_anim->x = raycast.map_x;
		new_anim->y = raycast.map_y;
		new_anim->time_anim_start = calculate_time();
		new_elt = ft_double_lstnew(new_anim);
		ft_double_lstadd_back(&game->lst_anim, new_elt);
		game->map[raycast.map_x][raycast.map_y] = 'O';
	}
	else if (game->map[raycast.map_x][raycast.map_y] == 'd')
	{
		if (find_square(game, raycast.map_x, raycast.map_y))
			suppress_node(game, raycast.map_x, raycast.map_y);
		new_anim = malloc(sizeof(t_anim));
		new_anim->x = raycast.map_x;
		new_anim->y = raycast.map_y;
		new_anim->time_anim_start = calculate_time();
		new_elt = ft_double_lstnew(new_anim);
		ft_double_lstadd_back(&game->lst_anim, new_elt);
		game->map[raycast.map_x][raycast.map_y] = 'o';
	}
	/*
	else if (game->map[raycast.map_x][raycast.map_y] == '1')
		add_graffiti(game);
	*/
}
