/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize_enemies_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:23:39 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 11:24:20 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	find_line(int *y, t_double_list **buffer_map,
		t_double_list **buffer_place_enemies)
{
	while ((*buffer_map)->next
		&& ((t_point *)(*buffer_place_enemies)->content)->y > *y)
	{
		*buffer_map = (*buffer_map)->next;
		(*y)++;
	}
	while ((*buffer_map)->previous
		&& ((t_point *)(*buffer_place_enemies)->content)->y < *y)
	{
		*buffer_map = (*buffer_map)->previous;
		(*y)--;
	}
}

void	write_enemy(t_double_list **buffer_place_enemies,
		t_double_list **buffer_map)
{
	char			*str;
	int				x;

	str = (char *)(*buffer_map)->content;
	x = 0;
	while (str[x])
	{
		if (((t_point *)(*buffer_place_enemies)->content)->x == x
			&& str[x] == '0')
			str[x] = 'M';
		x++;
	}
}
