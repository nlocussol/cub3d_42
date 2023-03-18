/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:23:52 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:53:08 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../so_long_bonus.h"

t_point	*find_start(t_double_list	**map)
{
	t_double_list	*buffer;
	t_point			*start;
	char			*str;

	start = ft_calloc(1, sizeof(t_list));
	if (!start)
		return (NULL);
	start->y = 0;
	buffer = *map;
	while (buffer)
	{
		str = (char *)buffer->content;
		start->x = 0;
		while (str[start->x])
		{
			if (str[start->x] == 'P')
				return (start);
			start->x++;
		}
		start->y++;
		buffer = buffer->next;
	}
	return (NULL);
}

void	check_valid_path(t_double_list	**map)
{
	t_point			*start;
	t_double_list	*map_clean;
	t_double_list	*head_map_clean;
	t_double_list	*components;
	int				value_return;

	start = find_start(map);
	head_map_clean = create_list_copy(map);
	map_clean = head_map_clean;
	modify_map_clean(map_clean, map);
	map_clean = head_map_clean;
	fload_map(map_clean, start->x, start->y);
	components = ft_double_lstnew(start);
	search_components(map, &components);
	map_clean = head_map_clean;
	value_return = verify_components_accessibility(&map_clean, &components);
	ft_double_lstclear(&components, del);
	ft_double_lstclear(&head_map_clean, del);
	if (value_return)
	{
		ft_double_lstclear(map, del);
		exit(0);
	}
}
