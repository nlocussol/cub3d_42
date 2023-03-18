/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_good_walls_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:21:10 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:55:49 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	display_good_wall_3(t_vars *vars, t_double_list *map, int x, int y)
{
	if (check_right_bot_corner(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[4],
			x * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			y * SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[8],
			x * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			y * SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
}

void	display_good_wall_2(t_vars *vars, t_double_list *map, int x, int y)
{
	if (check_left_bot_corner(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[5],
			x * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			y * SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
	else if (check_right_side(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[2],
			x * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			y * SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
	else if (check_bot_side(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[1],
			x * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			y * SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
	else if (check_right_top_corner(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[2],
			x * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			y * SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
	else
		display_good_wall_3(vars, map, x, y);
}

void	display_good_wall(t_vars *vars, t_double_list *map, int x, int y)
{
	if (check_crate(vars, x, y))
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[13],
			x * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			y * SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
	else if (check_left_side(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[3],
			x * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			y * SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
	else if (check_top_side(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[1],
			x * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			y * SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
	else if (check_left_top_corner(map, x) == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[3],
			x * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			y * SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
	else
		display_good_wall_2(vars, map, x, y);
}
