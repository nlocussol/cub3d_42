/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   song_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:58:43 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:57:00 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	suppress_node_sound(t_game *game, t_double_list *buffer)
{
	if (buffer->previous)
		buffer->previous->next = buffer->next;
	else
		game->lst_sound = buffer->next;
	if (buffer->next)
		buffer->next->previous = buffer->previous;
	if (!buffer->previous && !buffer->next)
		game->lst_sound = NULL;
	ft_double_lstdelone(buffer, del);
}

void	play_song(t_game *game, void *arg)
{
	char	*temp[3];

	temp[0] = "paplay";
	temp[1] = arg;
	temp[2] = NULL;
	execve("/usr/bin/paplay", temp, game->env);
}

char	*select_song(int mode)
{
	char	*arg;

	arg = NULL;
	if (mode == SPRAY)
		arg = ft_strdup("bonus/assets/songs/sound_spray.ogg");
	else if (mode == DOOR)
		arg = ft_strdup("bonus/assets/songs/sound_door.ogg");
	else if (mode == START_GAMEBOY)
		arg = ft_strdup("bonus/assets/songs/sound_start_gameboy.ogg");
	else if (mode == PLAY_GAMEBOY)
		arg = ft_strdup("bonus/assets/songs/sound_playing_gameboy.ogg");
	else if (mode == DANCING_CHEESE)
		arg = ft_strdup("bonus/assets/songs/sound_dancing_cheese.ogg");
	else if (mode == ATMOSPHERE)
		arg = ft_strdup("bonus/assets/songs/sound_atmosphere.ogg");
	return (arg);
}

void	save_song(t_game *game, int mode, int pid)
{
	t_song			*song;
	t_double_list	*new_elt;

	song = malloc(sizeof(t_song));
	if (!song)
		return ;
	song->pid = pid;
	song->type = mode;
	song->start_time = calculate_time();
	new_elt = ft_double_lstnew(song);
	if (!new_elt)
	{
		free(song);
		return ;
	}
	ft_double_lstadd_back(&game->lst_sound, new_elt);
}

void	launch_song(t_game *game, int mode)
{
	int				pid;
	char			*arg;

	pid = fork();
	if (pid == 0)
	{
		arg = select_song(mode);
		if (!arg)
			return ;
		play_song(game, arg);
		exit(0);
	}
	else if (pid > 0)
		save_song(game, mode, pid);
}
