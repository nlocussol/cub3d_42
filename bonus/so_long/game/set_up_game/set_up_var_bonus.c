/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_var_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:05:09 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 13:02:41 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	initialize_var(t_vars *vars, t_double_list *map, int argc, char **argv)
{
	t_point			*start;

	vars->map = map;
	vars->nb_columns = calculate_columns(vars->map);
	vars->nb_rows = calculate_rows(vars->map);
	vars->map_chunk = divise_map(vars);
	vars->player = ft_calloc(1, sizeof(t_player_so_long));
	set_up_array_ptr_player(vars);
	start = find_start(&vars->map);
	vars->player->x = start->x * SIZE_BLOCK_SL;
	vars->player->y = start->y * SIZE_BLOCK_SL;
	vars->player->old_point = ft_calloc(1, sizeof(t_point));
	vars->player->nb_collectibles = 0;
	vars->player->nb_move = 0;
	vars->player->frame = 0;
	vars->player->side = 0;
	vars->game_finish = 0;
	vars->argc = argc;
	vars->argv = argv;
	free(start);
	set_up_array_ptr_tile(vars);
	vars->nb_collectibles = calculate_collectibles(&vars->map);
	vars->frame_enemy = 0;
}
