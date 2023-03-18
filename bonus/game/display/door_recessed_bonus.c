/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_recessed_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:30:04 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:59:16 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	copy_raycast(t_raycast *raycast, t_raycast *raycast_copy)
{
	raycast_copy->pos_x = raycast->pos_x;
	raycast_copy->pos_y = raycast->pos_y;
	raycast_copy->dir_x = raycast->dir_x;
	raycast_copy->dir_y = raycast->dir_y;
	raycast_copy->plane_x = raycast->plane_x;
	raycast_copy->plane_y = raycast->plane_y;
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
	raycast_copy->draw_start = raycast->draw_start;
	raycast_copy->draw_end = raycast->draw_end;
	raycast_copy->line_height = raycast->line_height;
}

bool	wall_should_appear_not_door(t_game *game, t_raycast *raycast, long time)
{
	double	percentage_time;
	double	wall_x;

	if (raycast->side == 0)
		wall_x = raycast->pos_y + raycast->dist_perp_wall * raycast->ray_dir_y;
	else
		wall_x = raycast->pos_x + raycast->dist_perp_wall * raycast->ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	if (find_square_anim(game, raycast->map_x, raycast->map_y))
		percentage_time = (double)(time - find_square_anim(game, raycast->map_x,
					raycast->map_y)->time_anim_start) / 2000;
	else
		percentage_time = (double)0;
	if ((game->map[raycast->map_x][raycast->map_y] == 'O'
		&& find_square_anim(game, raycast->map_x, raycast->map_y)
		&& wall_x < percentage_time)
	|| (game->map[raycast->map_x][raycast->map_y] == 'o'
		&& find_square_anim(game, raycast->map_x, raycast->map_y)
		&& wall_x < (double)(1 - percentage_time)))
		return (true);
	else
		return (false);
}

bool	rayon_should_be_redisplay(t_raycast *raycast,
		t_raycast *raycast_copy, double wall_x, int mode)
{
	if (mode == 1)
	{
		if (raycast_copy->side != raycast->side
			&& ((raycast_copy->side == 0
					&& raycast_copy->map_y == raycast->map_y)
				|| (raycast_copy->side == 1
					&& raycast_copy->map_x == raycast->map_x)))
			return (true);
	}
	else if (mode == 2)
	{
		if ((raycast->side == 0
				&& ((raycast->step_x == 1 && wall_x < 0.5)
					|| (raycast->step_x == -1 && wall_x > 0.5)))
			|| (raycast->side == 1
				&& ((raycast->step_y == 1 && wall_x < 0.5)
					|| (raycast->step_y == -1 && wall_x > 0.5))))
			return (true);
	}
	return (false);
}

void	calculate_draw_end(t_game *game, t_raycast *raycast_copy)
{
	raycast_copy->line_height = HEIGHT_SCREEN;
	raycast_copy->line_height /= raycast_copy->dist_perp_wall;
	raycast_copy->draw_end = raycast_copy->line_height / 2;
	raycast_copy->draw_end += game->mouse_height;
	if (raycast_copy->draw_end >= HEIGHT_SCREEN)
		raycast_copy->draw_end = HEIGHT_SCREEN - 1;
}

bool	door_should_be_recessed(t_game *game, int x,
		t_raycast *raycast)
{
	t_raycast		raycast_copy;
	double			wall_x;

	copy_raycast(raycast, &raycast_copy);
	detect_wall(game, &raycast_copy);
	if (rayon_should_be_redisplay(raycast, &raycast_copy, 0, 1))
	{
		calculate_dist_perp_wall(game, &raycast_copy);
		calculate_draw_end(game, &raycast_copy);
		if (raycast_copy.draw_end > raycast->draw_end)
		{
			display_rayon(game, x, &raycast_copy);
			return (true);
		}
		else if (raycast_copy.draw_end == raycast->draw_end)
		{
			wall_x = calculate_wall_x(game, &raycast_copy, 0);
			if (rayon_should_be_redisplay(raycast, &raycast_copy, wall_x, 2))
			{
				display_rayon(game, x, &raycast_copy);
				return (true);
			}
		}
	}
	return (false);
}
