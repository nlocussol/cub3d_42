/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:58:13 by averdon           #+#    #+#             */
/*   Updated: 2023/01/29 22:46:03 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "display.h"

void	detect_wall(t_game *game, t_raycast *raycast)
{
	raycast->hit = 0;
	while (raycast->hit == 0)
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
			raycast->hit = 1;
	}
}

void	copy_raycast(t_raycast *raycast, t_raycast *raycast_copy)
{
	raycast_copy->pos_x = raycast->pos_x;
	raycast_copy->pos_y = raycast->pos_y;
	raycast_copy->dir_x = raycast->dir_x;
	raycast_copy->dir_y = raycast->dir_y;
	raycast_copy->plane_x = raycast->plane_x;
	raycast_copy->plane_y = raycast->plane_y;
	raycast_copy->camera_x = raycast->camera_x;
	raycast_copy->ray_dir_x = raycast->ray_dir_x;
	raycast_copy->ray_dir_y = raycast->ray_dir_y;
	raycast_copy->delta_dist_x = raycast->delta_dist_x;
	raycast_copy->delta_dist_y = raycast->delta_dist_y;
	raycast_copy->side_dist_x = raycast->side_dist_x;
	raycast_copy->side_dist_y = raycast->side_dist_y;
	raycast_copy->dist_perp_wall = raycast->dist_perp_wall;
	raycast_copy->map_x = raycast->map_x;
	raycast_copy->map_y = raycast->map_y;
	raycast_copy->step_x = raycast->step_x;
	raycast_copy->step_y = raycast->step_y;
	raycast_copy->side = raycast->side;
	raycast_copy->hit = raycast->hit;
	raycast_copy->draw_start = raycast->draw_start;
	raycast_copy->draw_end = raycast->draw_end;
	raycast_copy->line_height = raycast->line_height;
}

void	display_rayon(t_game *game, int x, t_raycast *raycast)
{
	int			i;
	int			last_draw_end;
	t_raycast	raycast_copy;

	if (ft_strchr("1D", game->map[raycast->map_x][raycast->map_y]))
	{
		calculate_dist_perp_wall(raycast);
		if (game->map[raycast->map_x][raycast->map_y] == 'D')
		{
			raycast->dist_perp_wall += 0.5;
		}
		raycast->line_height = HEIGHT_SCREEN / raycast->dist_perp_wall;
		raycast->draw_start = -raycast->line_height / 2 + game->mouse_height;
		if (raycast->draw_start < 0)
			raycast->draw_start = 0;
		raycast->draw_end = raycast->line_height / 2 + game->mouse_height;
		if (raycast->draw_end >= HEIGHT_SCREEN)
			raycast->draw_end = HEIGHT_SCREEN - 1;
		last_draw_end = raycast->draw_end;
		draw_line(game, x, raycast);
		if (game->map[raycast->map_x][raycast->map_y] == 'D')
		{
			copy_raycast(raycast, &raycast_copy);
			detect_wall(game, &raycast_copy);
			if (raycast_copy.side != raycast->side)	
			{
				calculate_dist_perp_wall(&raycast_copy);
				raycast_copy.line_height = HEIGHT_SCREEN / raycast_copy.dist_perp_wall;
				raycast_copy.draw_end = raycast_copy.line_height / 2 + game->mouse_height;
				if (raycast_copy.draw_end >= HEIGHT_SCREEN)
					raycast_copy.draw_end = HEIGHT_SCREEN - 1;
				if (raycast_copy.draw_end > last_draw_end)
					display_rayon(game, x, &raycast_copy);
			}
		}
	}
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
		display_rayon(game, WIDTH_SCREEN - x, &raycast);
		x++;
	}
	game_bar(game);
	if (game->minimap == 1)
		open_minimap(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->screen_img->img, 0, 0);
	nb_game_bar(game);
}
