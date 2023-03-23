/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:22:15 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 13:06:56 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

unsigned int	calculate_color(int x, int y, t_img *img)
{
	int	r;
	int	g;
	int	b;
	int	opacity;
	int	pixel;

	pixel = y * img->line_length + x * (img->bits_per_pixel / 8);
	opacity = img->addr[pixel + 3];
	r = img->addr[pixel + 2];
	g = img->addr[pixel + 1];
	b = img->addr[pixel];
	return ((opacity << 24) | (r << 16) | (g << 8) | b);
}

unsigned int	**convert_image(int length, int width, t_img img)
{
	int				y;
	int				x;
	unsigned int	**image;

	image = ft_calloc(length + 1, sizeof(unsigned int *));
	if (!image)
		return (NULL);
	y = 0;
	while (y < length)
	{
		x = 0;
		image[y] = ft_calloc(width + 1, sizeof(unsigned int));
		if (!image[y])
		{
			free_previous_malloc(&image, y);
			return (NULL);
		}
		while (x < width)
		{
			image[y][x] = calculate_color(x, y, &img);
			x++;
		}
		y++;
	}
	return (image);
}

bool	parse_one_group_image(t_game *game, unsigned int ***game_tab,
		char **name_img_tab, int length_tab)
{
	int		i;
	t_img	img;
	int		width;
	int		length;

	i = 0;
	while (i < length_tab)
	{
		img.img = mlx_xpm_file_to_image(game->mlx, name_img_tab[i],
				&width, &length);
		if (!img.img)
			return (false);
		img.addr = (unsigned char *)mlx_get_data_addr(img.img,
				&img.bits_per_pixel, &img.line_length, &img.endian);
		game_tab[i] = convert_image(length, width, img);
		mlx_destroy_image(game->mlx, img.img);
		if (!game_tab[i])
			return (false);
		i++;
	}
	return (true);
}
