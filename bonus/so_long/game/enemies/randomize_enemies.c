/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize_enemies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:56 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 11:23:19 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	place_enemies(t_vars *vars, t_double_list	**point_enemies)
{
	t_double_list	*buffer_place_enemies;
	t_double_list	*buffer_map;
	int				y;

	buffer_place_enemies = *point_enemies;
	buffer_map = vars->map;
	y = 0;
	while (buffer_place_enemies)
	{
		find_line(&y, &buffer_map, &buffer_place_enemies);
		if (buffer_map->previous && buffer_map->next)
			write_enemy(&buffer_place_enemies, &buffer_map);
		buffer_place_enemies = buffer_place_enemies->next;
	}
	return (0);
}	

void	calculate_x_and_y(int *x, int *y, t_double_list **map, t_point *point)
{
	while (*x < point->x)
	{
		*map = (*map)->next;
		(*x)++;
	}
	while (*y < point->y)
		(*y)++;
}

void	calculate_position_enemy(t_double_list *buffer,
		t_double_list **positions_enemies, t_double_list *map)
{
	t_point			*point;
	int				i;
	int				x;
	int				y;
	t_double_list	*new_elt;

	i = 0;
	while (i < 3)
	{
		point = ft_calloc(1, sizeof(t_point));
		map = (t_double_list *)((t_tilemap *)(buffer->content))->map;
		point->x = rand() % 10;
		point->y = rand() % 10;
		x = 0;
		y = 0;
		calculate_x_and_y(&x, &y, &map, point);
		point->x = point->x + ((t_tilemap *)(buffer->content))->x * 10;
		point->y = point->y + ((t_tilemap *)(buffer->content))->y * 10;
		new_elt = ft_double_lstnew(point);
		ft_double_lstadd_back(positions_enemies, new_elt);
		i++;
	}
}

void	randomize_enemies(t_vars *vars)
{
	t_double_list	*buffer;
	t_double_list	*buffer_2;
	t_double_list	*positions_enemies;

	srand(time(NULL));
	buffer = vars->map_chunk;
	positions_enemies = NULL;
	while (buffer)
	{
		calculate_position_enemy(buffer, &positions_enemies, NULL);
		buffer = buffer->next;
	}
	place_enemies(vars, &positions_enemies);
	buffer_2 = vars->map_chunk;
	while (vars->map_chunk)
	{
		ft_double_lstclear(&((t_tilemap *)(vars->map_chunk->content))->map,
			del);
		vars->map_chunk = vars->map_chunk->next;
	}
	ft_double_lstclear(&buffer_2, del);
	vars->map_chunk = divise_map(vars);
	ft_double_lstclear(&positions_enemies, del);
}
