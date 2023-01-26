/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:02:35 by averdon           #+#    #+#             */
/*   Updated: 2023/01/26 16:26:23 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_game(t_data *data)
{
	t_game	game;

	initialize_game(&game, data);
	parse_image(&game);
	display_screen(&game);
	mlx_hook(game.window, KeyPress, KeyPressMask, key_hook, &game);
	mlx_hook(game.window, DestroyNotify, StructureNotifyMask,
		close_window, &game);
	mlx_loop(game.mlx);
}
