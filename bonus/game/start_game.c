/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:02:35 by averdon           #+#    #+#             */
/*   Updated: 2023/01/28 16:45:25 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_game(t_data *data)
{
	t_game	game;

	initialize_game(&game, data);
	parse_image(&game);
	mlx_mouse_move(game.mlx, game.window, 0, HEIGHT_SCREEN / 2);
	display_screen(&game);
	mlx_mouse_hide(game.mlx, game.window);
	mlx_loop_hook(game.mlx, launch_movements, &game);
	mlx_hook(game.window, KeyRelease, KeyReleaseMask, key_released, &game);
	mlx_hook(game.window, KeyPress, KeyPressMask, key_pressed, &game);
	mlx_hook(game.window, DestroyNotify, StructureNotifyMask,
		close_window, &game);
	mlx_loop(game.mlx);
}
