/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:02:35 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:57:04 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	start_game(t_data *data, char **env)
{
	t_game	game;

	initialize_game(&game, data);
	game.env = env;
	if (!parse_image(&game))
	{
		free_all(&game);
		ft_fdprintf(2, "malloc failed\n");
		exit(1);
	}
	launch_song(&game, ATMOSPHERE);
	mlx_mouse_move(game.mlx, game.window, 0, HEIGHT_SCREEN / 2);
	mlx_mouse_hide(game.mlx, game.window);
	mlx_loop_hook(game.mlx, launch_movements, &game);
	mlx_hook(game.window, ButtonPress, ButtonPressMask, mouse_hook, &game);
	mlx_hook(game.window, KeyRelease, KeyReleaseMask, key_released, &game);
	mlx_hook(game.window, KeyPress, KeyPressMask, key_pressed, &game);
	mlx_hook(game.window, DestroyNotify, StructureNotifyMask,
		close_window, &game);
	mlx_loop(game.mlx);
}
