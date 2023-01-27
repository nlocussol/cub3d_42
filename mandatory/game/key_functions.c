/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:46:41 by averdon           #+#    #+#             */
/*   Updated: 2023/01/27 14:10:53 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	hit_map_border_forward_backward(t_game *game, int coeff,
		double function_x(double), double function_y(double))
{
	double	x;
	double	y;

	x = (function_x(radian_value(game->player->orientation)));
	x = x * coeff * game->player->speed;
	x = (game->player->x + x) / SIZE_BLOCK;
	y = (function_y(radian_value(game->player->orientation)));
	y = y * coeff * game->player->speed;
	y = (game->player->y + y) / SIZE_BLOCK;
	if (game->map[(int)x][(int)y] == '2')
		return (1);
	return (0);
}

int	hit_map_border_left_right(t_game *game, int coeff,
		double function_x(double), double function_y(double))
{
	double	x;
	double	y;

	x = (function_x(radian_value(game->player->orientation)));
	x = x * coeff * game->player->speed;
	x = (game->player->x - x) / SIZE_BLOCK;
	y = (function_y(radian_value(game->player->orientation)));
	y = y * coeff * game->player->speed;
	y = (game->player->y + y) / SIZE_BLOCK;
	if (game->map[(int)x][(int)y] == '2')
		return (1);
	return (0);
}

void	move_player(t_game	*game, int keycode)
{
	double	tmp;

	tmp = radian_value(game->player->orientation);
	if (keycode == W && !hit_map_border_forward_backward(game, 1, cos, sin))
	{
		game->player->x += game->player->speed * (cos(tmp));
		game->player->y += game->player->speed * (sin(tmp));
	}
	else if (keycode == S
		&& !hit_map_border_forward_backward(game, -1, cos, sin))
	{
		game->player->x -= game->player->speed * (cos(tmp));
		game->player->y -= game->player->speed * (sin(tmp));
	}
	else if (keycode == D && !hit_map_border_left_right(game, -1, sin, cos))
	{
		game->player->x += game->player->speed * (sin(tmp));
		game->player->y -= game->player->speed * (cos(tmp));
	}
	else if (keycode == A && !hit_map_border_left_right(game, 1, sin, cos))
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
	double	old_x;
	double	old_y;
	int		old_orientation;

	old_x = game->player->x;
	old_y = game->player->y;
	old_orientation = game->player->orientation;
	if (keycode == ECHAP)
		close_window(game);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(game, keycode);
	else if (keycode == LEFT_ARROW)
		turn_camera(game, 3);
	else if (keycode == RIGHT_ARROW)
		turn_camera(game, -3);
	if (old_x != game->player->x || old_y != game->player->y
		|| old_orientation != game->player->orientation)
		display_screen(game);
	return (0);
}
