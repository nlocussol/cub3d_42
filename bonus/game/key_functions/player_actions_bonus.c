/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:21:57 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:58:21 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	input_enter_echap(int keycode, t_game *game,
		int mouse_pos_x, int mouse_pos_y)
{
	char			*temp[2];

	if (keycode == ECHAP)
	{
		game->started_gameboy = false;
		destroy_and_free_so_long(game->vars);
		mlx_mouse_move(game->mlx, game->window, mouse_pos_x, mouse_pos_y);
	}
	else if (keycode == ENTER && game->vars->game_finish)
	{
		temp[0] = "./so_long";
		temp[1] = "bonus/so_long/maps/valid_map/maptest3.ber";
		destroy_and_free_so_long(game->vars);
		main_so_long(2, temp, game);
	}
}

void	input_gameboy(int keycode, t_game *game,
		int mouse_pos_x, int mouse_pos_y)
{
	t_double_list	*buffer;
	t_double_list	*next;
	t_song			*song;

	buffer = game->lst_sound;
	while (buffer)
	{
		song = buffer->content;
		next = buffer->next;
		if (song->type == START_GAMEBOY)
			break ;
		buffer = next;
	}
	if (buffer)
		return ;
	if (keycode == ECHAP || keycode == ENTER)
		input_enter_echap(keycode, game, mouse_pos_x, mouse_pos_y);
	else
		key_hook_so_long(keycode, game->vars);
}

int	key_hook(int keycode, t_game *game)
{
	static int		mouse_pos_x;
	static int		mouse_pos_y;

	if (game->started_gameboy == false)
	{
		if (keycode == ECHAP)
			close_window(game);
		if (keycode == W || keycode == A || keycode == S || keycode == D)
			move_player(game, keycode);
		else if (keycode == LEFT_ARROW)
			turn_camera(game, 3);
		else if (keycode == RIGHT_ARROW)
			turn_camera(game, -3);
		else if (keycode == E)
			interact(game, &mouse_pos_x, &mouse_pos_y);
	}
	else
		input_gameboy(keycode, game, mouse_pos_x, mouse_pos_y);
	return (0);
}
