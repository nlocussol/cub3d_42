/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:02:35 by averdon           #+#    #+#             */
/*   Updated: 2023/01/26 11:21:35 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	destroy_images(t_game *game)
{
	int	i;

	i = 0;
	(void)game;
	while (i < 4)
	{
		//mlx_destroy_image(game->mlx, game->images[i]);
		i++;
	}
}

void	free_all(t_game *game)
{
	mlx_loop_end(game->mlx);
	free(game->player);
	free(game->screen_img);
	free(game->text_no);
	free(game->text_so);
	free(game->text_we);
	free(game->text_ea);
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_tab(game->map);
	free(game->mlx);
}

int	close_window(t_game *game)
{
	ft_fdprintf(1, "Exit Program\n");
	free_all(game);
	exit (0);
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
	else if (keycode == W ||keycode == A ||keycode == S ||keycode == D)
		move_player(game, keycode);
	else if (keycode == LEFT_ARROW)
		turn_camera(game, -3);
	else if (keycode == RIGHT_ARROW)
		turn_camera(game, 3);
	if (old_x != game->player->x || old_y != game->player->y
		|| old_orientation != game->player->orientation)
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
		game->player->orientation = 90;
	else if (game->map[(int)game->player->x / SIZE_BLOCK][(int)game->player->y / SIZE_BLOCK] == 'N')
		game->player->orientation = 180;
	else if (game->map[(int)game->player->x / SIZE_BLOCK][(int)game->player->y / SIZE_BLOCK] == 'W')
		game->player->orientation = 270;
	else if (game->map[(int)game->player->x / SIZE_BLOCK][(int)game->player->y / SIZE_BLOCK] == 'S')
		game->player->orientation = 0;
}

void	initialize_game(t_game	*game, t_data *data)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH_SCREEN, HEIGHT_SCREEN, TITLE);
	game->map = data->map;
	create_border(game);
	game->text_ea = data->text_ea;
	game->text_no = data->text_no;
	game->text_so = data->text_so;
	game->text_we = data->text_we;
	game->hex_c = data->hex_c;
	game->hex_f = data->hex_f;
	find_player_place(game, &x, &y);
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return ;
	game->player->x = (double)x * SIZE_BLOCK + SIZE_BLOCK / 2;
	game->player->y = (double)y * SIZE_BLOCK + SIZE_BLOCK / 2;
	calculate_player_orientation(game);
	game->player->direction = game->map[x][y];
	game->screen_img = ft_calloc(1, sizeof(t_img));
	game->screen_img->img = mlx_new_image(game->mlx, WIDTH_SCREEN, HEIGHT_SCREEN);
	game->screen_img->addr = mlx_get_data_addr(game->screen_img->img, &game->screen_img->bits_per_pixel, &game->screen_img->line_length, &game->screen_img->endian);
	free_tab(data->text_c);
	free_tab(data->text_f);
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
