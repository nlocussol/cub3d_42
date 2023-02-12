/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divise_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:31:21 by averdon           #+#    #+#             */
/*   Updated: 2022/11/18 00:09:00 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	add_new_line(t_double_list *buffer, int x, t_tilemap *tile)
{
	t_double_list	*new_elt;
	int				i;
	char			*str;

	i = 0;
	str = ft_calloc(11, sizeof(char));
	str[10] = '\0';
	while (i < 10 && ((char *)(buffer->content))[i + x * 10])
	{
		str[i] = ((char *)(buffer->content))[i + x * 10];
		if (str[i] == 'P')
			str[i] = '0';
		i++;
	}
	while (i < 10)
	{
		str[i] = '1';
		i++;
	}
	new_elt = ft_double_lstnew(str);
	ft_double_lstadd_back(&(tile->map), new_elt);
}

void	add_new_chunk(t_double_list **map_cut, t_tilemap **tile, int *y, int x)
{
	t_double_list	*new_elt;

	(*tile)->x = x;
	(*tile)->y = *y;
	(*y)++;
	new_elt = ft_double_lstnew(*tile);
	ft_double_lstadd_back(map_cut, new_elt);
	(*tile) = ft_calloc(1, sizeof(t_tilemap));
	(*tile)->map = NULL;
}

void	complete_new_chunk(t_tilemap **tile, int k)
{
	int				i;
	t_double_list	*new_elt;
	char			*str;

	while (k % 10 != 0)
	{
		i = 0;
		str = ft_calloc(11, sizeof(char));
		str[10] = '\0';
		while (i < 10)
		{
			str[i] = '1';
			i++;
		}
		new_elt = ft_double_lstnew(str);
		ft_double_lstadd_back(&((*tile)->map), new_elt);
		k++;
	}
}

void	create_chunk(t_vars *vars, t_tilemap **tile,
		t_double_list **map_cut, int *x)
{
	int				y;
	int				j;
	int				k;
	t_double_list	*buffer;

	buffer = vars->map;
	j = 0;
	y = 0;
	k = 0;
	while (buffer)
	{
		add_new_line(buffer, *x, *tile);
		j++;
		if (j % 10 == 0)
			add_new_chunk(map_cut, tile, &y, *x);
		buffer = buffer->next;
		k++;
	}
	if (k % 10 != 0)
	{
		complete_new_chunk(tile, k);
		add_new_chunk(map_cut, tile, &y, *x);
	}
}

t_double_list	*divise_map(t_vars *vars)
{
	t_double_list	*map_cut;
	t_tilemap		*tile;
	int				x;

	x = 0;
	map_cut = NULL;
	tile = ft_calloc(1, sizeof(t_tilemap));
	tile->map = NULL;
	while (x < (vars->nb_columns / 10) + (vars->nb_columns % 10 > 0))
	{
		create_chunk(vars, &tile, &map_cut, &x);
		x++;
	}
	free(tile);
	return (map_cut);
}
