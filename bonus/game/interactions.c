/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:21:26 by averdon           #+#    #+#             */
/*   Updated: 2023/02/03 17:37:37 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_anim	*find_square(t_game *game, int x, int y)
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

int	good_side(t_raycast *raycast, char direction)
{
	if ((raycast->side == 0
			&& ((raycast->step_x == 1 && direction == 'S')
				|| (raycast->step_x == -1 && direction == 'N')))
		|| (raycast->side == 1
			&& ((raycast->step_y == 1 && direction == 'E')
				|| (raycast->step_y == -1 && direction == 'O'))))
		return (1);
	return (0);
}

t_graff	*find_square_2(t_game *game, t_raycast *raycast)
{
	t_double_list	*buffer;

	buffer = game->lst_graff;
	while (buffer)
	{
		if (good_side(raycast, ((t_graff *)(buffer->content))->direction)
		&& ((t_graff *)(buffer->content))->x == raycast->map_x
		&& ((t_graff *)(buffer->content))->y == raycast->map_y)
			return (buffer->content);
		buffer = buffer->next;
	}
	return (NULL);
}

void	suppress_node_2(t_game *game, t_raycast *raycast)
{
	t_double_list	*buffer;

	buffer = game->lst_graff;
	while (buffer)
	{
		if (good_side(raycast, ((t_graff *)(buffer->content))->direction)
		&& ((t_graff *)(buffer->content))->x == raycast->map_x
		&& ((t_graff *)(buffer->content))->y == raycast->map_y)
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

void	interact(t_game *game, int keycode)
{
	t_anim			*new_anim;
	t_graff			*new_graff;
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
	calculate_dist_perp_wall(game, &raycast);
	if (raycast.dist_perp_wall > (double)1)
		return ;
	if (keycode == E && game->map[raycast.map_x][raycast.map_y] == 'D')
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
	else if (keycode == E && game->map[raycast.map_x][raycast.map_y] == 'd')
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
	else if (keycode == G && ft_strchr("1D", game->map[raycast.map_x][raycast.map_y]))
	{
		if (find_square_2(game, &raycast) || game->nb_graff == 0)
			return ;
		new_graff = malloc(sizeof(t_graff));
		new_graff->x = raycast.map_x;
		new_graff->y = raycast.map_y;
		if (raycast.side == 0)
		{
			if (raycast.step_x == 1)
				new_graff->direction = 'S';
			else
				new_graff->direction = 'N';
		}
		else if (raycast.side == 1)
		{
			if (raycast.step_y == 1)
				new_graff->direction = 'E';
			else
				new_graff->direction = 'O';
		}
		new_graff->frame = 0;
		new_elt = ft_double_lstnew(new_graff);
		ft_double_lstadd_back(&game->lst_graff, new_elt);
		game->nb_graff -= 1;
	}
	else if (keycode == H && ft_strchr("1D", game->map[raycast.map_x][raycast.map_y]))
	{
		if (!find_square_2(game, &raycast))
			return ;
		suppress_node_2(game, &raycast);
		game->nb_graff += 1;
	}
}
