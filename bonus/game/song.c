/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   song.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:58:43 by averdon           #+#    #+#             */
/*   Updated: 2023/02/14 10:57:12 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <pthread.h>

void	*play_song(void *arg)
{
	system((char *)(arg));
	free(arg);
	return (NULL);
}

void	launch_song(t_game *game, int mode)
{
	char			*arg;
	t_double_list	*new_elt;
	pthread_t		thread;
	t_song			*song;

	arg = NULL;
	if (mode == SPRAY)
		arg = ft_strdup("paplay game/sound_spray.ogg");
	else if (mode == DOOR)
		arg = ft_strdup("paplay game/sound_door.ogg");
	if (!arg)
		return ;
	song = malloc(sizeof(t_song));
	if (!song)
		return ;
	pthread_create(&thread, NULL, play_song, arg);
	pthread_detach(thread);
	song->thread = thread;
	if (mode == SPRAY)
		song->type = SPRAY;
	else if (mode == DOOR)
		song->type = DOOR;
	song->start_time = calculate_time();
	new_elt = ft_double_lstnew(song);
	if (!new_elt)
	{
		pthread_cancel(thread);
		free(song);
		return ;
	}
	ft_double_lstadd_back(&game->lst_sound, new_elt);
}
