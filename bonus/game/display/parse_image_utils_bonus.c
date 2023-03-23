/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_image_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:38:52 by averdon           #+#    #+#             */
/*   Updated: 2023/02/20 16:32:42 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	free_previous_malloc(unsigned int ***image, int y)
{
	int	x;

	x = 0;
	while (x <= y)
	{
		free((*image)[x]);
		(*image)[x] = NULL;
		x++;
	}
	free(*image);
	*image = NULL;
}

void	free_one_image(unsigned int ***tab[5], int nb_group_image, int j)
{
	int	k;

	k = 0;
	while (tab[nb_group_image - 1][j][k])
	{
		free(tab[nb_group_image - 1][j][k]);
		tab[nb_group_image - 1][j][k] = NULL;
		k++;
	}
	free(tab[nb_group_image - 1][j]);
	tab[nb_group_image - 1][j] = NULL;
}

void	free_group(t_game *game, int nb_group_image)
{
	unsigned int	***tab[5];
	int				j;

	tab[0] = game->images;
	tab[1] = game->bar_img;
	tab[2] = game->minimap_img;
	tab[3] = game->anim_gameboy;
	tab[4] = game->arm_img;
	while (nb_group_image > 0)
	{
		if (tab[nb_group_image - 1])
		{
			j = 0;
			while (tab[nb_group_image - 1][j])
			{
				j++;
			}
		}
		nb_group_image--;
	}
}
