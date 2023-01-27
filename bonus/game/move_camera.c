/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:35:02 by averdon           #+#    #+#             */
/*   Updated: 2023/01/27 13:56:39 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	move_camera(void *arg)
{
	t_game		*game;
	static int	old_x;
	int			x;
	int			y;
	int			movement;

	game = (t_game *)arg;
	mlx_mouse_get_pos(game->mlx, game->window, &x, &y);
	movement = (old_x - x) / CAMERA_SPEED_REVERSE;
	game->player->orientation = (game->player->orientation + movement) % 360;
	if (game->player->orientation < 0)
		game->player->orientation = 360 + game->player->orientation;
	display_screen(game);
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
	return (0);
}
