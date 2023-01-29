/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:46:41 by averdon           #+#    #+#             */
/*   Updated: 2023/01/28 19:22:33 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "game.h"

int	hit_wall_forward_backward(t_game *game, int coeff,
		double function_x(double), double function_y(double))
{
	double	x;
	double	y;

	x = (function_x(radian_value(game->player->orientation)));
	x = coeff * (x * game->player->speed);
	x = (game->player->x + x) / SIZE_BLOCK;
	y = (function_y(radian_value(game->player->orientation)));
	y = coeff * (y * game->player->speed);
	y = (game->player->y + y) / SIZE_BLOCK;
	if (ft_strchr("1D", game->map[(int)x][(int)y]))
		return (1);
	return (0);
}

int	hit_wall_left_right(t_game *game, int coeff,
		double function_x(double), double function_y(double))
{
	double	x;
	double	y;

	x = (function_x(radian_value(game->player->orientation)));
	x = coeff * x * game->player->speed;
	x = (game->player->x - x) / SIZE_BLOCK;
	y = (function_y(radian_value(game->player->orientation)));
	y = coeff * y * game->player->speed;
	y = (game->player->y + y) / SIZE_BLOCK;
	if (ft_strchr("1D", game->map[(int)x][(int)y]))
		return (1);
	return (0);
}

void	move_player(t_game	*game, int keycode)
{
	double	tmp;

	tmp = radian_value(game->player->orientation);
	if (keycode == W && !hit_wall_forward_backward(game, 1, cos, sin))
	{
		game->player->x += game->player->speed * (cos(tmp));
		game->player->y += game->player->speed * (sin(tmp));
	}
	else if (keycode == S
		&& !hit_wall_forward_backward(game, -1, cos, sin))
	{
		game->player->x -= game->player->speed * (cos(tmp));
		game->player->y -= game->player->speed * (sin(tmp));
	}
	else if (keycode == D && !hit_wall_left_right(game, -1, sin, cos))
	{
		game->player->x += game->player->speed * (sin(tmp));
		game->player->y -= game->player->speed * (cos(tmp));
	}
	else if (keycode == A && !hit_wall_left_right(game, 1, sin, cos))
	{
		game->player->x -= game->player->speed * (sin(tmp));
		game->player->y += game->player->speed * (cos(tmp));
	}
}

void	turn_camera(t_game	*game, int move)
{
	game->player->orientation = (game->player->orientation + move) % 360;
	if (game->player->orientation < 0)
		game->player->orientation = 360 + game->player->orientation;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ECHAP)
		close_window(game);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(game, keycode);
	else if (keycode == LEFT_ARROW)
		turn_camera(game, 3);
	else if (keycode == RIGHT_ARROW)
		turn_camera(game, -3);
	else if (keycode == TAB)
	{
		if (game->minimap == 0)
			game->minimap = 1;
		else
			game->minimap = 0;
	}
	else if (keycode == E)
		interact(game);
	return (0);
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == W)
		game->movements[0] = 1;
	else if (keycode == A)
		game->movements[1] = 1;
	else if (keycode == S)
		game->movements[2] = 1;
	else if (keycode == D)
		game->movements[3] = 1;
	else
		key_hook(keycode, game);
	return (0);
}

int	key_released(int keycode, t_game *game)
{
	if (keycode == W)
		game->movements[0] = 0;
	else if (keycode == A)
		game->movements[1] = 0;
	else if (keycode == S)
		game->movements[2] = 0;
	else if (keycode == D)
		game->movements[3] = 0;
	return (0);
}

int	launch_movements(t_game *game)
{
	if (game->movements[0] == 1)
		key_hook(W, game);
	if (game->movements[1] == 1)
		key_hook(A, game);
	if (game->movements[2] == 1)
		key_hook(S, game);
	if (game->movements[3] == 1)
		key_hook(D, game);
	move_camera(game);
	return (0);
}
