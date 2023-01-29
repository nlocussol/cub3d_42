/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:35:02 by averdon           #+#    #+#             */
/*   Updated: 2023/01/29 11:32:34 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	move_camera(void *arg)
{
	t_game		*game;
	static int	old_x;
	//static int	old_y;
	int			x;
	int			y;
	int			movement;

	game = (t_game *)arg;
	mlx_mouse_get_pos(game->mlx, game->window, &x, &y);
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
	/*
	movement = (old_y - y) / CAMERA_SPEED_REVERSE;
	game->mouse_height = (game->mouse_height + movement);
	if (game->mouse_height < 0)
		game->mouse_height = 360 + game->mouse_height;
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
	*/
	display_screen(game);
	return (0);
}
