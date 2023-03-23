/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_animations_and_movement_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:52:08 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:58:22 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	start_gameboy(t_game *game, bool *first_time)
{
	t_song			*song;
	char			*temp[2];
	t_double_list	*buffer;

	buffer = game->lst_sound;
	while (buffer)
	{
		song = buffer->content;
		if (song->type == PLAY_GAMEBOY)
			break ;
		buffer = buffer->next;
	}
	if (!buffer)
		launch_song(game, PLAY_GAMEBOY);
	if (*first_time == true)
	{
		temp[0] = "./so_long";
		temp[1] = "bonus/so_long/maps/valid_map/maptest3.ber";
		main_so_long(2, temp, game);
		*first_time = false;
	}
	animation_and_movement(game->vars);
}

void	display_gameboy(t_game *game)
{
	draw_image(game, game->bar_img[6],
		WIDTH_SCREEN / 2 - 1014 / 2, HEIGHT_SCREEN - 869 - 85);
	anim_start_gameboy(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->screen_img->img, 0, 0);
}

void	launch_gameboy(t_game *game, bool *first_time)
{
	t_double_list	*buffer;
	t_double_list	*next;
	t_song			*song;

	if (*first_time == true)
		display_gameboy(game);
	buffer = game->lst_sound;
	while (buffer)
	{
		song = buffer->content;
		next = buffer->next;
		if (song->type == START_GAMEBOY)
		{
			if (calculate_time() - song->start_time > 5500)
				suppress_node_sound(game, buffer);
			else
				break ;
		}
		buffer = next;
	}
	if (!buffer)
		start_gameboy(game, first_time);
}

int	launch_movements(t_game *game)
{
	static bool		first_time;

	if (game->started_gameboy == false)
	{
		if (game->movements[0] == 1)
			key_hook(W, game);
		if (game->movements[1] == 1)
			key_hook(A, game);
		if (game->movements[2] == 1)
			key_hook(S, game);
		if (game->movements[3] == 1)
			key_hook(D, game);
		move_bar(game);
		move_camera(game);
		check_update(game);
		display_screen(game);
		first_time = true;
	}
	if (game->started_gameboy == true)
		launch_gameboy(game, &first_time);
	return (0);
}
