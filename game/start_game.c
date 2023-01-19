/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:02:35 by averdon           #+#    #+#             */
/*   Updated: 2023/01/19 10:46:28 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int	close_window(t_game *game)
{
	(void)game;
	ft_fdprintf(1, "Exit Program\n");
	exit (0);
}

int	key_hook(int keycode, t_game *game)
{
	(void)game;
	if (keycode == ECHAP)
		close_window(game);
	else if (keycode == W || keycode == UP_ARROW)
		ft_fdprintf(1, "go forward\n");
	else if (keycode == A || keycode == LEFT_ARROW)
		ft_fdprintf(1, "turn left\n");
	else if (keycode == S || keycode == DOWN_ARROW)
		ft_fdprintf(1, "go backward\n");
	else if (keycode == D || keycode == RIGHT_ARROW)
		ft_fdprintf(1, "turn right\n");
	printf("player x : %d,%d | player y : %d,%d\n",
			game->player->x / SIZE_BLOCK, game->player->x % SIZE_BLOCK * 100 / SIZE_BLOCK,
			game->player->y / SIZE_BLOCK, game->player->y % SIZE_BLOCK * 100 / SIZE_BLOCK);
	return (0);
}

void	initialize_game(t_game	*game, t_data *data)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH_SCREEN, LENGTH_SCREEN, TITLE);
	game->map = data->map;
	/* need to change by data value */
	game->player->x = 3 * SIZE_BLOCK + SIZE_BLOCK / 2;
	game->player->y = 2 * SIZE_BLOCK + SIZE_BLOCK / 2;
	game->player->orientation = 'N';
	/*                              */
}

void	start_game(t_data *data)
{
	t_game	game;

	initialize_game(&game, data);
	mlx_hook(game.window, KeyPress, KeyPressMask, key_hook, &game);
	mlx_hook(game.window, DestroyNotify, StructureNotifyMask, close_window, &game);
	mlx_loop(game.mlx);
}
