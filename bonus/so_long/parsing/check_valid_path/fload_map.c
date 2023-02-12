/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fload_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:40:05 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 11:11:02 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	reload_fload_map(t_double_list *map, t_double_list *head_map,
		int x, int y)
{
	if (((char *)(map->content))[x] == 'E'
	|| ((char *)(map->content))[x] == '3')
	{
		((char *)(map->content))[x] = '3';
		return ;
	}
	((char *)(map->content))[x] = '1';
	if (((char *)(map->content))[x - 1] == '0'
			|| ((char *)(map->content))[x - 1] == 'E')
		fload_map(head_map, x - 1, y);
	if (((char *)(map->content))[x + 1] == '0'
			|| ((char *)(map->content))[x + 1] == 'E')
		fload_map(head_map, x + 1, y);
	if (map->previous
		&& (((char *)(map->previous->content))[x] == '0'
			|| ((char *)(map->previous->content))[x] == 'E'))
		fload_map(head_map, x, y - 1);
	if (map-> next && (((char *)(map->next->content))[x] == '0'
			|| ((char *)(map->next->content))[x] == 'E'))
		fload_map(head_map, x, y + 1);
}

void	advance_map_and_y(int *y, int start_y, t_double_list **map)
{
	while (*map)
	{
		if (*y == start_y)
			break ;
		(*y)++;
		*map = (*map)->next;
	}
}

void	fload_map(t_double_list *map, int start_x, int start_y)
{
	int				y;
	int				x;
	t_double_list	*head_map;

	y = 0;
	head_map = map;
	advance_map_and_y(&y, start_y, &map);
	while (map)
	{
		x = 0;
		while (((char *)map->content)[x])
		{
			if (x == start_x && y == start_y)
			{
				reload_fload_map(map, head_map, x, y);
				break ;
			}
			x++;
		}
		y++;
		map = map->next;
	}
}
