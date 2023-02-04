/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:22:15 by averdon           #+#    #+#             */
/*   Updated: 2023/02/04 16:33:00 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

unsigned int	calculate_color(int x, int y, t_img *img)
{
	int				r;
	int				g;
	int				b;
	int				opacity;

	opacity = img->addr[y * img->line_length + x * (img->bits_per_pixel / 8) + 3];
	r = img->addr[y * img->line_length + x * (img->bits_per_pixel / 8) + 2];
	g = img->addr[y * img->line_length + x * (img->bits_per_pixel / 8) + 1];
	b = img->addr[y * img->line_length + x * (img->bits_per_pixel / 8)];
	return ((opacity << 24) + (r << 16) + (g << 8) + b);
}

unsigned int	**convert_image(int length, int width, t_img img)
{
	int				y;
	int				x;
	unsigned int				**image;

	image = ft_calloc(256 + 1, sizeof(int *));
	y = 0;
	while (y < length)
	{
		x = 0;
		image[y] = ft_calloc(256 + 1, sizeof(int));
		while (x < width)
		{
			image[y][x] = calculate_color(x, y, &img);
			x++;
		}
		y++;
	}
	return (image);
}

void	parse_image(t_game *game)
{
	char			*name_sprite[6];
	char			*name_minimap[4];
	char			*name_game_bar[3];
	int				i;
	t_img			img;
	int				width;
	int				length;

	name_sprite[0] = game->text_so;
	name_sprite[1] = game->text_no;
	name_sprite[2] = game->text_ea;
	name_sprite[3] = game->text_we;
	name_sprite[4] = game->text_do;
	name_sprite[5] = "assets/circle-xxl.xpm";
	i = 0;
	while (i < 6)
	{
		img.img = mlx_xpm_file_to_image(game->mlx, name_sprite[i],
				&width, &length);
		img.addr = mlx_get_data_addr(img.img,
				&img.bits_per_pixel, &img.line_length, &img.endian);
		game->images[i] = convert_image(length, width, img);
		mlx_destroy_image(game->mlx, img.img);
		i++;
	}
	name_minimap[0] = "assets/minimap/floor.xpm";
	name_minimap[1] = "assets/minimap/wall.xpm";
	name_minimap[2] = "assets/minimap/door.xpm";
	name_minimap[3] = "assets/minimap/door_open.xpm";
	i = 0;
	while (i < 4)
	{
		img.img = mlx_xpm_file_to_image(game->mlx, name_minimap[i],
				&width, &length);
		img.addr = mlx_get_data_addr(img.img,
				&img.bits_per_pixel, &img.line_length, &img.endian);
		game->minimap_img[i] = convert_image(length, width, img);
		mlx_destroy_image(game->mlx, img.img);
		i++;
	}
	name_game_bar[0] = "assets/game_bar/map1.xpm";
	name_game_bar[1] = "assets/game_bar/map2.xpm";
	name_game_bar[2] = "assets/game_bar/spraypaint.xpm";
	i = 0;
	while (i < 3)
	{
		img.img = mlx_xpm_file_to_image(game->mlx, name_game_bar[i],
				&width, &length);
		img.addr = mlx_get_data_addr(img.img,
				&img.bits_per_pixel, &img.line_length, &img.endian);
		game->bar_img[i] = convert_image(length, width, img);
		mlx_destroy_image(game->mlx, img.img);
		i++;
	}
}
