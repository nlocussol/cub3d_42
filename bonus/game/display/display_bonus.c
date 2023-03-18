/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:58:13 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:59:17 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	detect_wall(t_game *game, t_raycast *raycast)
{
	bool	hit;

	hit = false;
	while (hit != true)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (!ft_strchr("0WESN ", game->map[raycast->map_x][raycast->map_y]))
			hit = true;
	}
}

bool	replace_animated_door(t_game *game, int x, t_raycast *raycast)
{
	if (game->map[raycast->map_x][raycast->map_y] == 'O'
		&& find_square_anim(game, raycast->map_x, raycast->map_y)
		&& calculate_time() - find_square_anim(game, raycast->map_x,
			raycast->map_y)->time_anim_start >= 2000)
	{
		suppress_node_anim(game, raycast->map_x, raycast->map_y);
		game->map[raycast->map_x][raycast->map_y] = 'd';
		display_rayon(game, x, raycast);
		return (true);
	}
	else if (game->map[raycast->map_x][raycast->map_y] == 'o'
		&& find_square_anim(game, raycast->map_x, raycast->map_y)
		&& calculate_time() - find_square_anim(game, raycast->map_x,
			raycast->map_y)->time_anim_start >= 2000)
	{
		suppress_node_anim(game, raycast->map_x, raycast->map_y);
		game->map[raycast->map_x][raycast->map_y] = 'D';
		display_rayon(game, x, raycast);
		return (true);
	}
	else
		return (false);
}

void	rayon_hit_wall_or_door(t_game *game, int x,
		t_raycast *raycast)
{
	calculate_dist_perp_wall(game, raycast);
	if (ft_strchr("oO", game->map[raycast->map_x][raycast->map_y]))
	{
		if (wall_should_appear_not_door(game, raycast, calculate_time()))
		{
			detect_wall(game, raycast);
			display_rayon(game, x, raycast);
			return ;
		}
	}
	raycast->line_height = HEIGHT_SCREEN / raycast->dist_perp_wall;
	raycast->draw_start = -raycast->line_height / 2 + game->mouse_height;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	else if (raycast->draw_start >= HEIGHT_SCREEN)
		raycast->draw_start = HEIGHT_SCREEN - 1;
	raycast->draw_end = raycast->line_height / 2 + game->mouse_height;
	if (raycast->draw_end < 0)
		raycast->draw_end = 0;
	else if (raycast->draw_end >= HEIGHT_SCREEN)
		raycast->draw_end = HEIGHT_SCREEN - 1;
	if (!ft_strchr("DoO", game->map[raycast->map_x][raycast->map_y])
			|| !door_should_be_recessed(game, x, raycast))
		draw_line(game, x, raycast);
}

void	display_rayon(t_game *game, int x, t_raycast *raycast)
{
	int				i;

	if (ft_strchr("1DOo", game->map[raycast->map_x][raycast->map_y])
		&& !replace_animated_door(game, x, raycast))
		rayon_hit_wall_or_door(game, x, raycast);
	else if (ft_strchr("d", game->map[raycast->map_x][raycast->map_y]))
	{
		detect_wall(game, raycast);
		display_rayon(game, x, raycast);
	}
	else
	{
		i = 0;
		while (i < HEIGHT_SCREEN)
		{
			my_mlx_pixel_put(game->screen_img, x, i, 0);
			i++;
		}
	}
}

void	display_screen(t_game *game)
{
	t_raycast	raycast;
	int			x;

	raycast.pos_x = game->player->x / SIZE_BLOCK;
	raycast.pos_y = game->player->y / SIZE_BLOCK;
	raycast.dir_x = cos(radian_value(game->player->orientation));
	raycast.dir_y = sin(radian_value(game->player->orientation));
	raycast.plane_x = cos(radian_value(game->player->orientation + 90));
	raycast.plane_y = sin(radian_value(game->player->orientation + 90));
	x = 0;
	while (x < WIDTH_SCREEN)
	{
		calculate_delta_and_dist(x, &raycast);
		detect_wall(game, &raycast);
		display_rayon(game, WIDTH_SCREEN - x - 1, &raycast);
		x++;
	}
	game_bar(game);
	if (game->minimap == 1)
		open_minimap(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->screen_img->img, 0, 0);
	nb_game_bar(game);
}
