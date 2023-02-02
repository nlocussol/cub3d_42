/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:43:08 by averdon           #+#    #+#             */
/*   Updated: 2023/02/02 11:02:21 by averdon          ###   ########.fr       */
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
			if (buffer->next)
				buffer->next->previous = buffer->previous;
			if (!buffer->previous && !buffer->next)
				game->lst_anim = NULL;
			break ;
		}
		buffer = buffer->next;
	}
}
