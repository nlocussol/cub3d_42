/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:02:35 by averdon           #+#    #+#             */
/*   Updated: 2023/01/20 16:37:44 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "game.h"

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
	else if (keycode == W ||keycode == A ||keycode == S ||keycode == D)
		move_player(game, keycode);
	else if (keycode == LEFT_ARROW)
		turn_camera(game, 1);
	else if (keycode == RIGHT_ARROW)
		turn_camera(game, -1);
	mlx_clear_window(game->mlx, game->window);
	reload_display(game);
	/*printf("\nplayer x : %lf | player y : %lf\nplayer over a %c\nplayer \
orientation degree: %d | player orientation radiant %lf\n",
			game->player->x, game->player->y,
			game->map[(int)game->player->y / SIZE_BLOCK][(int)game->player->x / SIZE_BLOCK],
			game->player->orientation, game->player->orientation * M_PI / 180);*/
	return (0);
}

void	initialize_game(t_game	*game, t_data *data)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH_SCREEN, HEIGHT_SCREEN, TITLE);
	game->map = data->map;
	/* need to change by data value */
	game->player->x = (double)5 * SIZE_BLOCK + SIZE_BLOCK / 2;
	game->player->y = (double)5 * SIZE_BLOCK + SIZE_BLOCK / 2;
	game->player->orientation = 180;
	game->player->direction = 'N';
	/*                              */
}

void	start_game(t_data *data)
{
	t_game	game;

	initialize_game(&game, data);
	reload_display(&game);
	mlx_hook(game.window, KeyPress, KeyPressMask, key_hook, &game);
	mlx_hook(game.window, DestroyNotify, StructureNotifyMask, close_window, &game);
	mlx_loop(game.mlx);
}
