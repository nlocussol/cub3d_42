/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:23:29 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:52:15 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long_bonus.h"

void	check_components(int memory, t_components *components,
		t_double_list **map)
{
	if (!memory || components->start != 1
		|| components->exit != 1 || components->collectibles == 0)
	{
		free(components);
		ft_double_lstclear(map, del);
		exit(0);
	}
	free(components);
}

void	calculate_components(int *memory, t_components *components,
		t_double_list **map)
{
	char			*str;
	int				i;
	t_double_list	*buffer;

	buffer = *map;
	while (buffer && memory)
	{
		str = (char *)buffer->content;
		i = 0;
		while (str[i])
		{
			if (str[i] == 'P')
				components->start++;
			else if (str[i] == 'E')
				components->exit++;
			else if (str[i] == 'C')
				components->collectibles++;
			else if (str[i] != '0' && str[i] != '1')
				*memory = 0;
			i++;
		}
		buffer = buffer->next;
	}
}

void	check_valid_map(t_double_list **map)
{
	t_components	*components;
	int				memory;

	components = ft_calloc(1, sizeof(t_components));
	components->start = 0;
	components->exit = 0;
	components->collectibles = 0;
	memory = 1;
	calculate_components(&memory, components, map);
	check_components(memory, components, map);
}
