/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   song.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:58:43 by averdon           #+#    #+#             */
/*   Updated: 2023/02/09 16:30:03 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	launch_song(int mode)
{
	if (mode == SPRAY)
		pclose(popen("paplay game/sound_spray.ogg", "r"));
	else if (mode == DOOR)
		pclose(popen("paplay game/sound_door.ogg", "r"));
}
