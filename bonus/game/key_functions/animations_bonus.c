/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:50:25 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:58:26 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

bool	must_delete_song(t_game *game, long time, t_song *song)
{
	if ((song->type == SPRAY && time - song->start_time > 2500)
		|| (song->type == DOOR && time - song->start_time > 3500)
		|| (song->type == ATMOSPHERE && time - song->start_time > 313000)
		|| (song->type == DANCING_CHEESE && time - song->start_time > 252000)
		|| (song->type == PLAY_GAMEBOY
			&& (time - song->start_time > 252000
				|| game->started_gameboy == false))
		|| (song->type == START_GAMEBOY && time - song->start_time > 235000))
		return (true);
	else
		return (false);
}

void	check_anim(t_game *game, long time)
{
	t_double_list	*buffer;
	t_double_list	*next;
	t_anim			*anim;

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
			suppress_node_anim(game, anim->x, anim->y);
		}
		buffer = next;
	}
}

void	check_graff(t_game *game, long time)
{
	t_double_list	*buffer;
	t_graff			*graff;

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
}

void	check_song(t_game *game, long time)
{
	t_double_list	*buffer;
	t_double_list	*next;
	t_song			*song;

	buffer = game->lst_sound;
	while (buffer)
	{
		song = buffer->content;
		next = buffer->next;
		if (must_delete_song(game, time, song))
		{
			if (song->type == PLAY_GAMEBOY && game->started_gameboy == false)
				kill(song->pid, SIGKILL);
			suppress_node_sound(game, buffer);
		}
		buffer = next;
	}
}

void	check_update(t_game *game)
{
	long			time;

	time = calculate_time();
	check_anim(game, time);
	check_graff(game, time);
	check_song(game, time);
	update_song(game);
}
