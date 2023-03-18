/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movements_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:18:28 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:54:53 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	enemy_go_down(int y, int i, t_vars *vars, t_double_list *buffer)
{
	if (y + 1 == vars->player->y / SIZE_BLOCK_SL
		&& i == vars->player->x / SIZE_BLOCK_SL)
	{
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			X_LEFT_UP_CORNER_GAME + i % 10 * SIZE_BLOCK_SL,
			Y_LEFT_UP_CORNER_GAME + y % 10 * SIZE_BLOCK_SL);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[9 + vars->frame_enemy],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
		enemy_kill_player(vars);
	}
	else if (buffer->next && ((char *)(buffer->next->content))[i] == '0'
		&& !vars->game_finish)
	{
		((char *)(buffer->next->content))[i] = 'M';
		((char *)(buffer->content))[i] = '0';
		update_map_chunk(vars);
		display_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player->sprite[vars->player->frame + vars->player->side],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	}
}

void	enemy_go_left(int y, int i, t_vars *vars, t_double_list *buffer)
{
	if (y == vars->player->y / SIZE_BLOCK_SL
		&& i + 1 == vars->player->x / SIZE_BLOCK_SL)
	{
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			X_LEFT_UP_CORNER_GAME + i % 10 * SIZE_BLOCK_SL,
			Y_LEFT_UP_CORNER_GAME + y % 10 * SIZE_BLOCK_SL);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[9 + vars->frame_enemy],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
		enemy_kill_player(vars);
	}
	else if (((char *)(buffer->content))[i + 1] == '0'
		&& !vars->game_finish)
	{
		((char *)(buffer->content))[i + 1] = 'M';
		((char *)(buffer->content))[i] = '0';
		update_map_chunk(vars);
		display_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player->sprite[vars->player->frame + vars->player->side],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	}
}

void	enemy_go_up(int y, int i, t_vars *vars, t_double_list *buffer)
{
	if (y - 1 == vars->player->y / SIZE_BLOCK_SL
		&& i == vars->player->x / SIZE_BLOCK_SL)
	{
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			X_LEFT_UP_CORNER_GAME + i % 10 * SIZE_BLOCK_SL,
			Y_LEFT_UP_CORNER_GAME + y % 10 * SIZE_BLOCK_SL);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[9 + vars->frame_enemy],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
		enemy_kill_player(vars);
	}
	else if (buffer->previous && !vars->game_finish
		&& ((char *)(buffer->previous->content))[i] == '0')
	{
		((char *)(buffer->previous->content))[i] = 'M';
		((char *)(buffer->content))[i] = '0';
		update_map_chunk(vars);
		display_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player->sprite[vars->player->frame + vars->player->side],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	}
}

void	enemy_go_right(int y, int i, t_vars *vars, t_double_list *buffer)
{
	if (y == vars->player->y / SIZE_BLOCK_SL
		&& i - 1 == vars->player->x / SIZE_BLOCK_SL)
	{
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			X_LEFT_UP_CORNER_GAME + i % 10 * SIZE_BLOCK_SL,
			Y_LEFT_UP_CORNER_GAME + y % 10 * SIZE_BLOCK_SL);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[9 + vars->frame_enemy],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
		enemy_kill_player(vars);
	}
	else if (((char *)(buffer->content))[i - 1] == '0'
		&& !vars->game_finish)
	{
		((char *)(buffer->content))[i - 1] = 'M';
		((char *)(buffer->content))[i] = '0';
		update_map_chunk(vars);
		display_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player->sprite[vars->player->frame + vars->player->side],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	}
}
