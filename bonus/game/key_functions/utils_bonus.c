/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:51:50 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:58:20 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

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

void	anim_start_gameboy(t_game *game)
{
	static long	time_start;
	long		time;
	int			frame;

	if (game == NULL)
	{
		time_start = calculate_time();
		return ;
	}
	time = calculate_time();
	frame = (time - time_start) / 550;
	if (frame > 9)
		return ;
	draw_image(game, game->anim_gameboy[frame], 710, 377);
}
