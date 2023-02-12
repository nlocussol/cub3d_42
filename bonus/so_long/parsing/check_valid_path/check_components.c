/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:48:20 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 11:10:49 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_in_line(t_double_list *buffer_map, t_double_list *buffer_components)
{
	char			*str;
	int				x;

	str = (char *)buffer_map->content;
	x = 0;
	while (str[x])
	{
		if (((t_point *)buffer_components->content)->x == x)
		{
			if (str[x] != '1' && str[x] != '3')
				return (1);
		}
		x++;
	}
	return (0);
}

int	verify_components_accessibility(t_double_list **map_clean,
		t_double_list	**components)
{
	t_double_list	*buffer_components;
	t_double_list	*buffer_map;
	int				y;

	buffer_components = *components;
	buffer_map = *map_clean;
	y = 0;
	while (buffer_components)
	{
		while (((t_point *)buffer_components->content)->y > y)
		{
			buffer_map = buffer_map->next;
			y++;
		}
		while (((t_point *)buffer_components->content)->y < y)
		{
			buffer_map = buffer_map->previous;
			y--;
		}
		if (check_in_line(buffer_map, buffer_components) == 1)
			return (1);
		buffer_components = buffer_components->next;
	}
	return (0);
}	

void	add_new_point(int x, int y, t_double_list **components)
{
	t_point			*new_point;
	t_double_list	*new_elt;

	new_point = ft_calloc(1, sizeof(new_point));
	if (!new_point)
		exit(0);
	new_point->x = x;
	new_point->y = y;
	new_elt = ft_double_lstnew(new_point);
	ft_double_lstadd_back(components, new_elt);
}

void	search_components(t_double_list **map, t_double_list **components)
{
	t_double_list	*buffer;
	int				x;
	int				y;

	buffer = *map;
	y = 0;
	while (buffer)
	{
		x = 0;
		while (((char *)(buffer->content))[x])
		{
			if (((char *)(buffer->content))[x] == 'E'
				|| ((char *)(buffer->content))[x] == 'C')
				add_new_point(x, y, components);
			x++;
		}
		y++;
		buffer = buffer->next;
	}
}
