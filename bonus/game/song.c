/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   song.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:58:43 by averdon           #+#    #+#             */
/*   Updated: 2023/02/10 17:40:45 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	launch_song(t_game *game, int mode)
{
	t_double_list	*new_elt;
	t_song			*song;

	song = malloc(sizeof(t_song));
	if (!song)
		return ;
	if (mode == SPRAY)
	{
		song->stream = popen("paplay game/sound_spray.ogg", "r");
		song->type = SPRAY;
	}
	else if (mode == DOOR)
	{
		song->stream = popen("paplay game/sound_door.ogg", "r");
		song->type = DOOR;
	}
	song->start_time = calculate_time();
	new_elt = ft_double_lstnew(song);
	if (!new_elt)
	{
		if (song->stream)
			pclose(song->stream);
		free(song);
		return ;
	}
	ft_double_lstadd_back(&game->lst_sound, new_elt);
}
