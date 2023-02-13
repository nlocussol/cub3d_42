/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:56:44 by averdon           #+#    #+#             */
/*   Updated: 2023/02/13 13:57:23 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	calculate_columns(t_double_list *map)
{
	int	columns;

	columns = 0;
	while (((char *)(map->content))[columns])
			columns++;
	return (columns);
}

int	calculate_rows(t_double_list *map)
{
	int				rows;
	t_double_list	*buffer;

	rows = 0;
	buffer = map;
	while (buffer)
	{
		buffer = buffer->next;
		rows++;
	}
	return (rows);
}

int	calculate_collectibles(t_double_list **map)
{
	t_double_list	*buffer;
	int				i;
	int				nb_collectibles;

	buffer = *map;
	nb_collectibles = 0;
	while (buffer)
	{
		i = 0;
		while (((char *)(buffer->content))[i])
		{
			if (((char *)(buffer->content))[i] == 'C')
				nb_collectibles++;
			i++;
		}
		buffer = buffer->next;
	}
	return (nb_collectibles);
}
