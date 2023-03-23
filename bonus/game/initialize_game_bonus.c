/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:25:45 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:56:58 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "game_bonus.h"

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
	game->player->speed = 7;
	game->movements[0] = 0;
	game->movements[1] = 0;
	game->movements[2] = 0;
	game->movements[3] = 0;
}

void	initialize_tab_image(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 12)
		game->images[i] = NULL;
	i = -1;
	while (++i < 5)
		game->minimap_img[i] = NULL;
	i = -1;
	while (++i < 8)
		game->bar_img[i] = NULL;
	i = -1;
	while (++i < 6)
		game->arm_img[i] = NULL;
	i = -1;
	while (++i < 11)
		game->anim_gameboy[i] = NULL;
}

void	initialize_texture(t_game *game, t_data *data)
{
	game->text_ea = data->text_ea;
	game->text_no = data->text_no;
	game->text_so = data->text_so;
	game->text_we = data->text_we;
	game->text_do = data->text_door;
	game->hex_c = data->hex_c;
	game->hex_f = data->hex_f;
	free_tab(data->text_c);
	free_tab(data->text_f);
	initialize_tab_image(game);
}

void	initialize_game(t_game	*game, t_data *data)
{
	unsigned char	*temp;

	game->mlx = mlx_init();
	game->minimap = 0;
	game->window = mlx_new_window(game->mlx,
			WIDTH_SCREEN, HEIGHT_SCREEN, TITLE);
	game->map = data->map;
	initialize_texture(game, data);
	initialize_player(game);
	game->screen_img = ft_calloc(1, sizeof(t_img));
	game->screen_img->img = mlx_new_image(game->mlx,
			WIDTH_SCREEN, HEIGHT_SCREEN);
	temp = (unsigned char *)mlx_get_data_addr(game->screen_img->img,
			&game->screen_img->bits_per_pixel, &game->screen_img->line_length,
			&game->screen_img->endian);
	game->screen_img->addr = temp;
	game->mouse_height = HEIGHT_SCREEN / 2;
	game->lst_anim = NULL;
	game->lst_graff = NULL;
	game->lst_sound = NULL;
	game->time_start = calculate_time();
	game->nb_graff = 3;
	game->bar_index = 1;
	game->started_gameboy = false;
}
