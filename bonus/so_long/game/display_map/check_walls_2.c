/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:20:58 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 11:38:28 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_left_side(t_double_list *map, int x)
{
	if (x < 9 && ((char *)(map->content))[x + 1] != '1')
		return (1);
	return (0);
}

int	check_right_side(t_double_list *map, int x)
{
	if (x > 0 && ((char *)(map->content))[x - 1] != '1')
		return (1);
	return (0);
}

int	check_top_side(t_double_list *map, int x)
{
	if (x < 9 && map->next
		&& ((char *)(map->content))[x + 1] == '1'
		&& ((char *)(map->next->content))[x] != '1')
		return (1);
	else if (x > 0 && map->next
		&& ((char *)(map->content))[x - 1] == '1'
		&& ((char *)(map->next->content))[x] != '1')
		return (1);
	return (0);
}

int	check_bot_side(t_double_list *map, int x)
{
	if (x < 9 && map->previous
		&& ((char *)(map->content))[x + 1] == '1'
		&& ((char *)(map->previous->content))[x] != '1')
		return (1);
	else if (x > 0 && map->previous
		&& ((char *)(map->content))[x - 1] == '1'
		&& ((char *)(map->previous->content))[x] != '1')
		return (1);
	return (0);
}

int	check_top_right_corner(t_double_list *map, int x)
{
	if (x > 0 && map->next
		&& ((char *)(map->content))[x - 1] == '1'
		&& ((char *)(map->next->content))[x] != '1')
		return (1);
	return (0);
}
