/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:43:08 by averdon           #+#    #+#             */
/*   Updated: 2023/02/02 09:50:45 by averdon          ###   ########.fr       */
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
