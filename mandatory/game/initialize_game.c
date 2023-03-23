/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:25:45 by averdon           #+#    #+#             */
/*   Updated: 2023/01/26 16:26:19 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	int	x;
	int	y;

	x = game->player->x / SIZE_BLOCK;
	y = game->player->y / SIZE_BLOCK;
	if (game->map[x][y] == 'E')
		game->player->orientation = 90;
	else if (game->map[x][y] == 'N')
		game->player->orientation = 180;
	else if (game->map[x][y] == 'W')
		game->player->orientation = 270;
	else if (game->map[x][y] == 'S')
		game->player->orientation = 0;
}

void	initialize_player(t_game *game)
{
	int	x;
	int	y;

	find_player_place(game, &x, &y);
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return ;
	game->player->x = (double)x * SIZE_BLOCK + SIZE_BLOCK / 2;
	game->player->y = (double)y * SIZE_BLOCK + SIZE_BLOCK / 2;
	calculate_player_orientation(game);
	game->player->direction = game->map[x][y];
	game->player->speed = 10;
}

void	initialize_game(t_game	*game, t_data *data)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			WIDTH_SCREEN, HEIGHT_SCREEN, TITLE);
	game->map = data->map;
	create_border(game);
	game->text_ea = data->text_ea;
	game->text_no = data->text_no;
	game->text_so = data->text_so;
	game->text_we = data->text_we;
	game->hex_c = data->hex_c;
	game->hex_f = data->hex_f;
	game->images[0] = NULL;
	game->images[1] = NULL;
	game->images[2] = NULL;
	game->images[3] = NULL;
	initialize_player(game);
	game->screen_img = ft_calloc(1, sizeof(t_img));
	game->screen_img->img = mlx_new_image(game->mlx,
			WIDTH_SCREEN, HEIGHT_SCREEN);
	game->screen_img->addr = mlx_get_data_addr(game->screen_img->img,
			&game->screen_img->bits_per_pixel, &game->screen_img->line_length,
			&game->screen_img->endian);
	free_tab(data->text_c);
	free_tab(data->text_f);
}
