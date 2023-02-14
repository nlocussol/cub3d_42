/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:46:41 by averdon           #+#    #+#             */
/*   Updated: 2023/02/14 13:00:07 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "display/display.h"
#include "game.h"

int	mouse_hook(int mouse, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (mouse == MOUSE_UP)
	{
		game->bar_index--;
		if (game->bar_index < 1)
			game->bar_index = 8;
	}
	else if (mouse == MOUSE_DOWN)
	{
		game->bar_index++;
		if (game->bar_index > 8)
			game->bar_index = 1;
	}
	return (0);
}

int	hit_wall_forward_backward(t_game *game, int coeff,
		double function_x(double), double function_y(double))
{
	double	x;
	double	y;

	x = (function_x(radian_value(game->player->orientation)));
	x = coeff * (x * game->player->speed);
	x = (game->player->x + x) / SIZE_BLOCK;
	y = (function_y(radian_value(game->player->orientation)));
	y = coeff * (y * game->player->speed);
	y = (game->player->y + y) / SIZE_BLOCK;
	if (ft_strchr("1DOo", game->map[(int)x][(int)y]))
		return (1);
	return (0);
}

int	hit_wall_left_right(t_game *game, int coeff,
		double function_x(double), double function_y(double))
{
	double	x;
	double	y;

	x = (function_x(radian_value(game->player->orientation)));
	x = coeff * x * game->player->speed;
	x = (game->player->x - x) / SIZE_BLOCK;
	y = (function_y(radian_value(game->player->orientation)));
	y = coeff * y * game->player->speed;
	y = (game->player->y + y) / SIZE_BLOCK;
	if (ft_strchr("1DOo", game->map[(int)x][(int)y]))
		return (1);
	return (0);
}

void	move_bar(t_game *game)
{
	if (game->bar_index == 1)
		game->minimap = 1;
	else
		game->minimap = 0;
}

void	move_player(t_game	*game, int keycode)
{
	double	tmp;

	tmp = radian_value(game->player->orientation);
	if (keycode == W && !hit_wall_forward_backward(game, 1, cos, sin))
	{
		game->player->x += game->player->speed * (cos(tmp));
		game->player->y += game->player->speed * (sin(tmp));
	}
	else if (keycode == S
		&& !hit_wall_forward_backward(game, -1, cos, sin))
	{
		game->player->x -= game->player->speed * (cos(tmp));
		game->player->y -= game->player->speed * (sin(tmp));
	}
	else if (keycode == D && !hit_wall_left_right(game, -1, sin, cos))
	{
		game->player->x += game->player->speed * (sin(tmp));
		game->player->y -= game->player->speed * (cos(tmp));
	}
	else if (keycode == A && !hit_wall_left_right(game, 1, sin, cos))
	{
		game->player->x -= game->player->speed * (sin(tmp));
		game->player->y += game->player->speed * (cos(tmp));
	}
}

void	turn_camera(t_game	*game, int move)
{
	game->player->orientation = (game->player->orientation + move) % 360;
	if (game->player->orientation < 0)
		game->player->orientation = 360 + game->player->orientation;
}

int	key_hook(int keycode, t_game *game)
{
	static int		mouse_pos_x;
	static int		mouse_pos_y;
	t_double_list	*next;
	t_song			*song;

	if (game->started_gameboy == false)
	{
		if (keycode == ECHAP)
		{
			while (game->lst_sound)
			{
				song = game->lst_sound->content;
				kill(song->pid, SIGKILL);
				next = game->lst_sound->next;
				ft_double_lstdelone(game->lst_sound, del);
				game->lst_sound = next;
			}
			close_window(game);
		}
		if (keycode == W || keycode == A || keycode == S || keycode == D)
			move_player(game, keycode);
		else if (keycode == LEFT_ARROW)
			turn_camera(game, 3);
		else if (keycode == RIGHT_ARROW)
			turn_camera(game, -3);
		else if (keycode == E)
		{
			interact(game);
			if (game->bar_index == GAMEBOY)
				mlx_mouse_get_pos(game->mlx, game->window, &mouse_pos_x, &mouse_pos_y);
		}
	}
	else
	{
		if (keycode == ECHAP)
		{
			game->started_gameboy = false;
			destroy_and_free_so_long(game->vars);
			mlx_mouse_move(game->mlx, game->window, mouse_pos_x, mouse_pos_y);
		}
		else if (keycode == ENTER && game->vars->game_finish)
		{
			char *temp[2];
			temp[0] = "./so_long";
			temp[1] = "so_long/maps/valid_map/maptest3.ber";
			main_so_long(2, temp, game);
		}
		else
			key_hook_so_long(keycode, game->vars);
	}
	return (0);
}

int	key_pressed(int keycode, t_game *game)
{
	if (game->started_gameboy == false)
	{
		if (keycode >= 49 && keycode <= 57)
			game->bar_index = keycode - 48;
		if (keycode == W)
			game->movements[0] = 1;
		else if (keycode == A)
			game->movements[1] = 1;
		else if (keycode == S)
			game->movements[2] = 1;
		else if (keycode == D)
			game->movements[3] = 1;
		else
			key_hook(keycode, game);
	}
	else
		key_hook(keycode, game);
	return (0);
}

int	key_released(int keycode, t_game *game)
{
	if (keycode == W)
		game->movements[0] = 0;
	else if (keycode == A)
		game->movements[1] = 0;
	else if (keycode == S)
		game->movements[2] = 0;
	else if (keycode == D)
		game->movements[3] = 0;
	return (0);
}

long	calculate_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	check_anim(t_game *game)
{
	t_double_list	*buffer;
	t_double_list	*next;
	t_song			*song;
	t_anim			*anim;
	t_graff			*graff;
	long			time;

	time = calculate_time();
	buffer = game->lst_anim;
	while (buffer)
	{
		anim = buffer->content;
		next = buffer->next;
		if (ft_strchr("oO", game->map[anim->x][anim->y])
			&& time - anim->time_anim_start >= 2000)
		{
			if (game->map[anim->x][anim->y] == 'o')
				game->map[anim->x][anim->y] = 'D';
			else
				game->map[anim->x][anim->y] = 'd';
			suppress_node(game, anim->x, anim->y);
		}
		buffer = next;
	}
	buffer = game->lst_graff;
	while (buffer)
	{
		graff = buffer->content;
		if (time - graff->last_frame_changed >= 100)
		{
			graff->frame += 1;
			if (graff->frame == 6)
				graff->frame = 0;
			graff->last_frame_changed = time;
		}
		buffer = buffer->next;
	}
	buffer = game->lst_sound;
	while (buffer)
	{
		song = buffer->content;
		next = buffer->next;
		if ((song->type == SPRAY && time - song->start_time > 1 * 2500)
			|| (song->type == DOOR && time - song->start_time > 1 * 3500))
			suppress_node_3(game, buffer);
		else
		{
		}
		buffer = next;
	}
}

void	draw_image(t_game *game, unsigned int **img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (img[i])
	{
		j = 0;
		while (img[i][j])
		{
			if ((int)img[i][j] >= 0)
				my_mlx_pixel_put(game->screen_img, j + x, i + y, img[i][j]);
			j++;
		}
		i++;
	}
}

int	launch_movements(t_game *game)
{
	static bool	first_time;
	char		*temp[2];

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
		display_screen(game);
		check_anim(game);
		first_time = true;
	}
	if (game->started_gameboy == true)
	{
		if (first_time == true)
		{
			draw_image(game, game->bar_img[6], WIDTH_SCREEN / 2 - 1014 / 2, HEIGHT_SCREEN - 869 - 85);
			mlx_put_image_to_window(game->mlx, game->window, game->screen_img->img, 0, 0);
			temp[0] = "./so_long";
			temp[1] = "so_long/maps/valid_map/maptest3.ber";
			main_so_long(2, temp, game);
			first_time = false;
		}
		animation_and_movement(game->vars);
	}
	return (0);
}
