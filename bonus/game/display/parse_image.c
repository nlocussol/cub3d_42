/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:22:15 by averdon           #+#    #+#             */
/*   Updated: 2023/02/15 16:43:45 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
	return ((opacity << 24) + (r << 16) + (g << 8) + b);
}

unsigned int	**convert_image(int length, int width, t_img img)
{
	int				y;
	int				x;
	unsigned int	**image;

	image = ft_calloc(length + 1, sizeof(unsigned int *));
	y = 0;
	while (y < length)
	{
		x = 0;
		image[y] = ft_calloc(width + 1, sizeof(unsigned int));
		while (x < width)
		{
			image[y][x] = calculate_color(x, y, &img);
			x++;
		}
		y++;
	}
	return (image);
}

void	parse_one_group_image(t_game *game, unsigned int ***game_tab,
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
		img.addr = (unsigned char *)mlx_get_data_addr(img.img,
				&img.bits_per_pixel, &img.line_length, &img.endian);
		game_tab[i] = convert_image(length, width, img);
		mlx_destroy_image(game->mlx, img.img);
		i++;
	}
}

void	parse_image_next(t_game *game)
{
	char	*name_minimap[4];
	char	*name_game_bar[7];
	char	*name_arm_img[5];
	char	*anim_gameboy[10];

	name_minimap[0] = "assets/minimap/floor.xpm";
	name_minimap[1] = "assets/minimap/wall.xpm";
	name_minimap[2] = "assets/minimap/door.xpm";
	name_minimap[3] = "assets/minimap/door_open.xpm";
	parse_one_group_image(game, game->minimap_img, name_minimap, 4);
	name_game_bar[0] = "assets/game_bar/map1.xpm";
	name_game_bar[1] = "assets/game_bar/map2.xpm";
	name_game_bar[2] = "assets/game_bar/spraypaint.xpm";
	name_game_bar[3] = "assets/game_bar/card.xpm";
	name_game_bar[4] = "assets/game_bar/gameboy.xpm";
	name_game_bar[5] = "assets/game_bar/sponge.xpm";
	name_game_bar[6] = "assets/gameboy_screen.xpm";
	parse_one_group_image(game, game->bar_img, name_game_bar, 7);
	name_arm_img[0] = "assets/arm_img/mine_arm.xpm";
	name_arm_img[1] = "assets/arm_img/card_arm.xpm";
	name_arm_img[2] = "assets/arm_img/gameboy_arm.xpm";
	name_arm_img[3] = "assets/arm_img/spray_arm.xpm";
	name_arm_img[4] = "assets/arm_img/sponge_arm.xpm";
	parse_one_group_image(game, game->arm_img, name_arm_img, 5);
	anim_gameboy[0] = "assets/gameboy_intro/f0.xpm";
	anim_gameboy[1] = "assets/gameboy_intro/f1.xpm";
	anim_gameboy[2] = "assets/gameboy_intro/f2.xpm";
	anim_gameboy[3] = "assets/gameboy_intro/f3.xpm";
	anim_gameboy[4] = "assets/gameboy_intro/f4.xpm";
	anim_gameboy[5] = "assets/gameboy_intro/f5.xpm";
	anim_gameboy[6] = "assets/gameboy_intro/f6.xpm";
	anim_gameboy[7] = "assets/gameboy_intro/f7.xpm";
	anim_gameboy[8] = "assets/gameboy_intro/f8.xpm";
	anim_gameboy[9] = "assets/gameboy_intro/f9.xpm";
	parse_one_group_image(game, game->anim_gameboy, anim_gameboy, 10);
}

void	parse_image(t_game *game)
{
	char	*name_sprite[11];

	name_sprite[0] = game->text_so;
	name_sprite[1] = game->text_no;
	name_sprite[2] = game->text_ea;
	name_sprite[3] = game->text_we;
	name_sprite[4] = game->text_do;
	name_sprite[5] = "assets/knight_0.xpm";
	name_sprite[6] = "assets/knight_1.xpm";
	name_sprite[7] = "assets/knight_2.xpm";
	name_sprite[8] = "assets/knight_3.xpm";
	name_sprite[9] = "assets/knight_4.xpm";
	name_sprite[10] = "assets/knight_5.xpm";
	parse_one_group_image(game, game->images, name_sprite, 11);
	parse_image_next(game);
}
