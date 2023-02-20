/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parseing_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:29:58 by averdon           #+#    #+#             */
/*   Updated: 2023/02/20 16:30:18 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	parse_image_next_next_next(t_game *game)
{
	char	*name_arm_img[5];

	name_arm_img[0] = "assets/arm_img/mine_arm.xpm";
	name_arm_img[1] = "assets/arm_img/card_arm.xpm";
	name_arm_img[2] = "assets/arm_img/gameboy_arm.xpm";
	name_arm_img[3] = "assets/arm_img/spray_arm.xpm";
	name_arm_img[4] = "assets/arm_img/sponge_arm.xpm";
	if (!parse_one_group_image(game, game->arm_img, name_arm_img, 5))
	{
		free_group(game, 5);
		return (false);
	}
	else
		return (true);
}

bool	parse_image_next_next(t_game *game)
{
	char	*anim_gameboy[10];

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
	if (!parse_one_group_image(game, game->anim_gameboy, anim_gameboy, 10))
	{
		free_group(game, 4);
		return (false);
	}
	return (parse_image_next_next_next(game));
}

bool	parse_image_next(t_game *game)
{
	char	*name_game_bar[7];
	char	*name_minimap[4];

	name_game_bar[0] = "assets/game_bar/map1.xpm";
	name_game_bar[1] = "assets/game_bar/map2.xpm";
	name_game_bar[2] = "assets/game_bar/spraypaint.xpm";
	name_game_bar[3] = "assets/game_bar/card.xpm";
	name_game_bar[4] = "assets/game_bar/gameboy.xpm";
	name_game_bar[5] = "assets/game_bar/sponge.xpm";
	name_game_bar[6] = "assets/gameboy_screen.xpm";
	if (!parse_one_group_image(game, game->bar_img, name_game_bar, 7))
	{
		free_group(game, 2);
		return (false);
	}
	name_minimap[0] = "assets/minimap/floor.xpm";
	name_minimap[1] = "assets/minimap/wall.xpm";
	name_minimap[2] = "assets/minimap/door.xpm";
	name_minimap[3] = "assets/minimap/door_open.xpm";
	if (!parse_one_group_image(game, game->minimap_img, name_minimap, 4))
	{
		free_group(game, 3);
		return (false);
	}
	return (parse_image_next_next(game));
}

bool	parse_image(t_game *game)
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
	if (!parse_one_group_image(game, game->images, name_sprite, 11))
	{
		free_group(game, 1);
		return (false);
	}
	return (parse_image_next(game));
}
