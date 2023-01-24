/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:22:15 by averdon           #+#    #+#             */
/*   Updated: 2023/01/24 13:46:45 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_image(t_game *game)
{
	t_img		*img;
	int			width;
	int			length;
	int			y;
	int			x;
	unsigned int color;
	unsigned int **image;
	
	img = ft_calloc(1, sizeof(t_img));
	img->img = mlx_xpm_file_to_image(game->mlx, "textures/pikachu.xpm", &width, &length);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	image = ft_calloc(256, sizeof(unsigned int *));
	y = 0;
	while (y < length)
	{
		x = 0;
		image[y] = ft_calloc(256, sizeof(unsigned int));
		while (x < width)
		{
			color = img->addr[y * img->line_length + x * (img->bits_per_pixel / 8)];
			image[y][x] = color;
			x++;
		}
		y++;
	}
}
