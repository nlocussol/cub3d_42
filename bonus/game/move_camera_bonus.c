/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:35:02 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:56:59 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	turn_camera(t_game	*game, int move)
{
	game->player->orientation = (game->player->orientation + move) % 360;
	if (game->player->orientation < 0)
		game->player->orientation = 360 + game->player->orientation;
}

void	move_left_right(t_game *game, int x, int y)
{
	static int	old_x = 0;
	int			movement;

	movement = (old_x - x) / CAMERA_SPEED_REVERSE;
	game->player->orientation = (game->player->orientation + movement) % 360;
	if (game->player->orientation < 0)
		game->player->orientation = 360 + game->player->orientation;
	if (x <= 0)
	{
		x = WIDTH_SCREEN - 2;
		mlx_mouse_move(game->mlx, game->window, x, y);
	}
	else if (x >= WIDTH_SCREEN - 1)
	{
		x = 1;
		mlx_mouse_move(game->mlx, game->window, x, y);
	}
	old_x = x;
}

void	move_up_down(t_game *game, int x, int y)
{
	static int	old_y = HEIGHT_SCREEN / 2;
	int			movement;

	movement = ((old_y - y) / CAMERA_SPEED_REVERSE) * 5;
	game->mouse_height = (game->mouse_height + movement);
	if (y <= 10)
	{
		y = HEIGHT_SCREEN * 9 / 10 - 2;
		mlx_mouse_move(game->mlx, game->window, x, y);
	}
	else if (y >= HEIGHT_SCREEN * 9 / 10)
	{
		y = 11;
		mlx_mouse_move(game->mlx, game->window, x, y);
	}
	old_y = y;
}

int	move_camera(void *arg)
{
	t_game		*game;
	int			x;
	int			y;

	game = (t_game *)arg;
	mlx_mouse_get_pos(game->mlx, game->window, &x, &y);
	move_left_right(game, x, y);
	move_up_down(game, x, y);
	return (0);
}
