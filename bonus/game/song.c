/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   song.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:58:43 by averdon           #+#    #+#             */
/*   Updated: 2023/02/14 13:00:57 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "game.h"

void	play_song(t_game *game, void *arg)
{
	char	*arg2[3];

	arg2[0] = "paplay";
	arg2[1] = arg;
	arg2[2] = NULL;
	execve("/usr/bin/paplay", arg2, game->env);
}

void	launch_song(t_game *game, int mode)
{
	int				pid;
	t_song			*song;
	t_double_list	*new_elt;
	char			*arg;

	pid = fork();
	if (pid == 0)
	{
		arg = NULL;
		if (mode == SPRAY)
			arg = ft_strdup("game/sound_spray.ogg");
		else if (mode == DOOR)
			arg = ft_strdup("game/sound_door.ogg");
		if (!arg)
			return ;
		play_song(game, arg);
		exit(0);
	}
	else
	{
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
}
