/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_case_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:55:08 by nlocusso          #+#    #+#             */
/*   Updated: 2023/03/14 13:58:31 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_one_case(t_game *game, int x_tmp, int y_tmp, int color)
{
	int	x;
	int	y;

	x = x_tmp;
	while (x < x_tmp + 128)
	{
		y = y_tmp;
		while (y < y_tmp + 128)
		{
			if ((x >= x_tmp && x < x_tmp + 5) || (y >= y_tmp && y < y_tmp + 5)
				|| (y > y_tmp + 123 && y < y_tmp + 128)
				|| (x > x_tmp + 123 && x < x_tmp + 128))
				my_mlx_pixel_put(game->screen_img, y, x, color);
			y++;
		}
		x++;
	}
}

void	put_big_case(t_game *game, int x_tmp, int y_tmp, int color)
{
	int	x;
	int	y;

	x = x_tmp;
	while (x < x_tmp + 136)
	{
		y = y_tmp;
		while (y < y_tmp + 134)
		{
			if ((x >= x_tmp && x < x_tmp + 5) || (y >= y_tmp && y < y_tmp + 5)
				|| (y > y_tmp + 127 && y < y_tmp + 134)
				|| (x > x_tmp + 131 && x < x_tmp + 136))
				my_mlx_pixel_put(game->screen_img, y, x, color);
			y++;
		}
		x++;
	}
}
