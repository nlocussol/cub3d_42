/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:00:58 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:57:47 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

double	abs_value(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

double	radian_value(double degree)
{
	return (degree * M_PI / 180);
}

long	calculate_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	calculate_player_orientation(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x / SIZE_BLOCK;
	y = game->player->y / SIZE_BLOCK;
	if (game->map[x][y] == 'E')
		game->player->orientation = 90;
	else if (game->map[x][y] == 'N')
		game->player->orientation = 180;
	else if (game->map[x][y] == 'W')
		game->player->orientation = 270;
	else if (game->map[x][y] == 'S')
		game->player->orientation = 0;
}
