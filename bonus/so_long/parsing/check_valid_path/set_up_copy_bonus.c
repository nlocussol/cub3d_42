/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_copy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:36:43 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:53:04 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	modify_map_clean(t_double_list *map_clean, t_double_list **map)
{
	t_double_list	*buffer;
	int				i;
	char			*s1;
	char			*s2;

	buffer = *map;
	while (buffer)
	{
		i = 0;
		s1 = (char *)buffer->content;
		s2 = (char *)map_clean->content;
		while (s1[i])
		{
			if (s1[i] == '1')
				s2[i] = '2';
			else if (s1[i] == 'E')
				s2[i] = 'E';
			i++;
		}
		buffer = buffer->next;
		map_clean = map_clean->next;
	}
}

int	create_list_copy_next(int size_list, int length_line,
		t_double_list **map_clean)
{
	int				i;
	char			*str;
	t_double_list	*new_elt;

	i = 0;
	while (i < size_list)
	{
		str = ft_calloc(1, length_line + 1);
		if (!str)
			return (1);
		ft_memset(str, '0', length_line);
		new_elt = ft_double_lstnew(str);
		ft_double_lstadd_back(map_clean, new_elt);
		if (!new_elt)
			return (1);
		i++;
	}
	return (0);
}

t_double_list	*create_list_copy(t_double_list **initial_list)
{
	t_double_list	*map_clean;
	int				size_list;
	int				length_line;
	int				value_return;

	length_line = ft_strlen((*initial_list)->content);
	size_list = ft_double_lstsize(*initial_list);
	length_line = ft_strlen((char *)(*initial_list)->content);
	map_clean = NULL;
	value_return = create_list_copy_next(size_list, length_line, &map_clean);
	if (value_return == 1)
	{
		ft_double_lstclear(&map_clean, del);
		ft_double_lstclear(initial_list, del);
		exit(0);
	}
	return (map_clean);
}
