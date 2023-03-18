/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:46:00 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:59:15 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

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
