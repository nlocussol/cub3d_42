/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_key_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:14:38 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:54:16 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	key_up(t_vars *vars, char actual_place)
{
	vars->player->nb_move++;
	if (actual_place == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[7],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	vars->player->y -= SIZE_BLOCK_SL;
	return (0);
}

int	key_down(t_vars *vars, char actual_place)
{
	vars->player->nb_move++;
	if (actual_place == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[7],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	vars->player->y += SIZE_BLOCK_SL;
	return (0);
}

int	key_left(t_vars *vars, char actual_place)
{
	vars->player->nb_move++;
	if (actual_place == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[7],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	vars->player->x -= SIZE_BLOCK_SL;
	vars->player->side = 6;
	return (0);
}

int	key_right(t_vars *vars, char actual_place)
{
	vars->player->nb_move++;
	if (actual_place == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[7],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	vars->player->x += SIZE_BLOCK_SL;
	vars->player->side = 0;
	return (0);
}
