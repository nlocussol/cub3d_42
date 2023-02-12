/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:31:01 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 23:28:32 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_enemies_left_and_down(t_vars *vars, int *movements)
{
	int				i;
	int				y;
	t_double_list	*buffer;

	buffer = vars->map;
	y = 0;
	advance_buffer_and_y(&buffer, &y);
	while (buffer)
	{
		i = ft_strlen((char *)(buffer->content)) - 1;
		while (i >= 0)
		{
			if (((char *)(buffer->content))[i] == 'M')
			{
				if (movements[2] < 2)
					enemy_go_down(y, i, vars, buffer);
				else if (movements[3] < 2)
					enemy_go_left(y, i, vars, buffer);
			}
			i--;
		}
		buffer = buffer->previous;
		y--;
	}
}

void	update_movements(int movements[4])
{
	if (movements[0] < 2)
		movements[0]++;
	else if (movements[1] < 2)
		movements[1]++;
	else if (movements[2] < 2)
		movements[2]++;
	else if (movements[3] < 2)
		movements[3]++;
	if (movements[3] == 2)
	{
		movements[0] = 0;
		movements[1] = 0;
		movements[2] = 0;
		movements[3] = 0;
	}
}

int	find_monsters(t_double_list *buffer, t_vars *vars, int movements[4], int y)
{
	int				i;

	i = 0;
	while (((char *)(buffer->content))[i])
	{
		if (((char *)(buffer->content))[i] == 'M')
		{
			if (movements[0] < 2)
				enemy_go_up(y, i, vars, buffer);
			else if (movements[1] < 2)
				enemy_go_right(y, i, vars, buffer);
			else if (movements[2] < 2 || movements[3] < 2)
			{
				move_enemies_left_and_down(vars, movements);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	launch_find_monsters(t_vars *vars, int movements[4])
{
	t_double_list	*buffer;
	int				y;
	int				value_return;

	buffer = vars->map;
	y = 0;
	while (buffer)
	{
		value_return = find_monsters(buffer, vars, movements, y);
		if (value_return)
			break ;
		buffer = buffer->next;
		y++;
	}
}

int	enemies_movement(t_vars *vars)
{
	static int		movements[4];
	static int		count;

	if (vars->game_finish)
		return (0);
	count += 1000;
	if (count < 500000)
		return (0);
	count = 0;
	vars->frame_enemy++;
	if (vars->frame_enemy == 4)
		vars->frame_enemy = 0;
	launch_find_monsters(vars, movements);
	update_movements(movements);
	return (0);
}
