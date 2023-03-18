/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:25:55 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:54:15 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	close_window_so_long(t_vars *vars)
{
	destroy_and_free_so_long(vars);
	exit(0);
}

int	check_key_next_next_next(int keycode, t_vars *vars,
		t_double_list *buffer, int x)
{
	if (keycode == 'd' || keycode == ARROW_RIGHT)
	{
		if (((char *)(buffer->content))[x + 1] == '1'
			|| (((char *)(buffer->content))[x + 1] == 'E'
				&& vars->player->nb_collectibles != vars->nb_collectibles))
			return (1);
		else if (((char *)(buffer->content))[x + 1] == 'M')
		{
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[0],
				vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
				vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[27], 95 + X_LEFT_UP_CORNER_GAME,
				70 + Y_LEFT_UP_CORNER_GAME);
			vars->game_finish = 1;
			return (0);
		}
		key_right(vars, ((char *)(buffer->content))[x]);
	}
	else if (keycode == ECHAP)
		return (check_echap(vars));
	return (0);
}

int	check_key_next_next(int keycode, t_vars *vars, t_double_list *buffer, int x)
{
	if (keycode == 'a' || keycode == ARROW_LEFT)
	{
		if (((char *)(buffer->content))[x - 1] == '1'
			|| (((char *)(buffer->content))[x - 1] == 'E'
				&& vars->player->nb_collectibles != vars->nb_collectibles))
			return (1);
		else if (((char *)(buffer->content))[x - 1] == 'M')
		{
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[0],
				vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
				vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[27], 95 + X_LEFT_UP_CORNER_GAME,
				70 + Y_LEFT_UP_CORNER_GAME);
			vars->game_finish = 1;
			return (0);
		}
		key_left(vars, ((char *)(buffer->content))[x]);
		return (0);
	}
	else
		return (check_key_next_next_next(keycode, vars, buffer, x));
}

int	check_key_next(int keycode, t_vars *vars, t_double_list *buffer, int x)
{
	if (keycode == 's' || keycode == ARROW_DOWN)
	{
		if (((char *)(buffer->next->content))[x] == '1'
			|| (((char *)(buffer->next->content))[x] == 'E'
				&& vars->player->nb_collectibles != vars->nb_collectibles))
			return (1);
		else if (((char *)(buffer->next->content))[x] == 'M')
		{
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[0],
				vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
				vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[27], 95 + X_LEFT_UP_CORNER_GAME,
				70 + Y_LEFT_UP_CORNER_GAME);
			vars->game_finish = 1;
			return (0);
		}
		key_down(vars, ((char *)(buffer->content))[x]);
		return (0);
	}
	else
		return (check_key_next_next(keycode, vars, buffer, x));
}

int	check_key(int keycode, t_vars *vars, t_double_list *buffer, int x)
{
	if (keycode == 'w' || keycode == ARROW_UP)
	{
		if (((char *)(buffer->previous->content))[x] == '1'
			|| (((char *)(buffer->previous->content))[x] == 'E'
				&& vars->player->nb_collectibles != vars->nb_collectibles))
			return (1);
		else if (((char *)(buffer->previous->content))[x] == 'M')
		{
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[0],
				vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
				vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[27], 95 + X_LEFT_UP_CORNER_GAME,
				70 + Y_LEFT_UP_CORNER_GAME);
			vars->game_finish = 1;
			return (0);
		}
		key_up(vars, ((char *)(buffer->content))[x]);
		return (0);
	}
	else
		return (check_key_next(keycode, vars, buffer, x));
}
