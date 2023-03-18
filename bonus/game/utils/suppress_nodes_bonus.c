/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suppress_nodes_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:01:13 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:57:34 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

t_anim	*find_square_anim(t_game *game, int x, int y)
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

void	suppress_node_anim(t_game *game, int x, int y)
{
	t_double_list	*buffer;
	t_double_list	*next;

	buffer = game->lst_anim;
	while (buffer)
	{
		next = buffer->next;
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
			ft_double_lstdelone(buffer, del);
		}
		buffer = next;
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

t_graff	*find_square_graff(t_game *game, t_raycast *raycast)
{
	t_double_list	*buffer;

	buffer = game->lst_graff;
	while (buffer)
	{
		if (((t_graff *)(buffer->content))->x == raycast->map_x
		&& ((t_graff *)(buffer->content))->y == raycast->map_y
		&& good_side(raycast, ((t_graff *)(buffer->content))->direction))
			return (buffer->content);
		buffer = buffer->next;
	}
	return (NULL);
}

void	suppress_node_graff(t_game *game, t_raycast *raycast)
{
	t_double_list	*buffer;
	t_double_list	*next;

	buffer = game->lst_graff;
	while (buffer)
	{
		next = buffer->next;
		if (((t_graff *)(buffer->content))->x == raycast->map_x
		&& ((t_graff *)(buffer->content))->y == raycast->map_y
		&& good_side(raycast, ((t_graff *)(buffer->content))->direction))
		{
			if (buffer->previous)
				buffer->previous->next = buffer->next;
			else
				game->lst_graff = buffer->next;
			if (buffer->next)
				buffer->next->previous = buffer->previous;
			if (!buffer->previous && !buffer->next)
				game->lst_graff = NULL;
			ft_double_lstdelone(buffer, del);
		}
		buffer = next;
	}
}
