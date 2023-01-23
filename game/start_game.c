/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:02:35 by averdon           #+#    #+#             */
/*   Updated: 2023/01/23 19:27:21 by averdon          ###   ########.fr       */
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
		turn_camera(game, -1);
	else if (keycode == RIGHT_ARROW)
		turn_camera(game, 1);
	mlx_clear_window(game->mlx, game->window);
	reload_display(game);
	return (0);
}

void	find_player_place(t_game *game, int *x, int *y)
{
	*x = 0;
	while (game->map[*x])
	{
		*y = 0;
		while (game->map[*x][*y])
		{
			if (ft_strchr("NSEW", game->map[*x][*y]))
				return ;
			(*y)++;
		}
		(*x)++;
	}
}

void	calculate_player_orientation(t_game *game)
{
	if (game->map[(int)game->player->x / SIZE_BLOCK][(int)game->player->y / SIZE_BLOCK] == 'E')
		game->player->orientation = 0;
	else if (game->map[(int)game->player->x / SIZE_BLOCK][(int)game->player->y / SIZE_BLOCK] == 'N')
		game->player->orientation = 90;
	else if (game->map[(int)game->player->x / SIZE_BLOCK][(int)game->player->y / SIZE_BLOCK] == 'W')
		game->player->orientation = 180;
	else if (game->map[(int)game->player->x / SIZE_BLOCK][(int)game->player->y / SIZE_BLOCK] == 'S')
		game->player->orientation = 270;
}

void	initialize_game(t_game	*game, t_data *data)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH_SCREEN, HEIGHT_SCREEN, TITLE);
	game->map = data->map;
	find_player_place(game, &x, &y);
	game->player->x = (double)x * SIZE_BLOCK + SIZE_BLOCK / 2;
	game->player->y = (double)y * SIZE_BLOCK + SIZE_BLOCK / 2;
	calculate_player_orientation(game);
	game->player->direction = game->map[x][y];
	game->screen_img = malloc(sizeof(t_img));
	game->screen_img->img = mlx_new_image(game->mlx, WIDTH_SCREEN, HEIGHT_SCREEN);
	game->screen_img->addr = mlx_get_data_addr(game->screen_img->img, &game->screen_img->bits_per_pixel, &game->screen_img->line_length, &game->screen_img->endian);
	game->data = data;
}

void	start_game(t_data *data)
{
	t_game	game;

	initialize_game(&game, data);
	parse_image(&game);
	reload_display(&game);
	mlx_hook(game.window, KeyPress, KeyPressMask, key_hook, &game);
	mlx_hook(game.window, DestroyNotify, StructureNotifyMask, close_window, &game);
	mlx_loop(game.mlx);
}
