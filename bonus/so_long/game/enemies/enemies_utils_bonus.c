/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:20:48 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:54:53 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	enemy_kill_player(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->array_ptr_sprite[27],
		85 + X_LEFT_UP_CORNER_GAME,
		70 + Y_LEFT_UP_CORNER_GAME);
	vars->game_finish = 1;
}

void	update_map_chunk(t_vars *vars)
{
	t_double_list	*buffer_2;

	buffer_2 = vars->map_chunk;
	while (vars->map_chunk)
	{
		ft_double_lstclear(&((t_tilemap *)(vars->map_chunk->content))->map,
			del);
		vars->map_chunk = vars->map_chunk->next;
	}
	ft_double_lstclear(&buffer_2, del);
	vars->map_chunk = divise_map(vars);
}

void	advance_buffer_and_y(t_double_list **buffer, int *y)
{
	while ((*buffer)->next)
	{
		*buffer = (*buffer)->next;
		(*y)++;
	}
}
