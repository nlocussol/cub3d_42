/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_display_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:27:50 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:59:20 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	calculate_dist_perp_wall(t_game *game, t_raycast *raycast)
{
	if (raycast->side == 0)
	{
		raycast->dist_perp_wall = raycast->side_dist_x;
		if (ft_strchr("DoO", game->map[raycast->map_x][raycast->map_y]))
			raycast->dist_perp_wall += raycast->delta_dist_x * 0.5;
		raycast->dist_perp_wall -= raycast->delta_dist_x;
	}
	else
	{
		raycast->dist_perp_wall = raycast->side_dist_y;
		if (ft_strchr("DoO", game->map[raycast->map_x][raycast->map_y]))
			raycast->dist_perp_wall += raycast->delta_dist_y * 0.5;
		raycast->dist_perp_wall -= raycast->delta_dist_y;
	}
	if (raycast->dist_perp_wall == 0)
		raycast->dist_perp_wall = INFINITY;
}

void	calculate_delta_and_dist_next(t_raycast *raycast)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = raycast->pos_x - raycast->map_x;
		raycast->side_dist_x *= raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = raycast->map_x + 1.0 - raycast->pos_x;
		raycast->side_dist_x *= raycast->delta_dist_x;
	}
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = raycast->pos_y - raycast->map_y;
		raycast->side_dist_y *= raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = raycast->map_y + 1.0 - raycast->pos_y;
		raycast->side_dist_y *= raycast->delta_dist_y;
	}
}

void	calculate_delta_and_dist(int x, t_raycast *raycast)
{
	double	camera_x;

	camera_x = 2 * x / (double)(WIDTH_SCREEN) - 1;
	raycast->ray_dir_x = raycast->dir_x + raycast->plane_x * camera_x;
	raycast->ray_dir_y = raycast->dir_y + raycast->plane_y * camera_x;
	raycast->map_x = raycast->pos_x;
	raycast->map_y = raycast->pos_y;
	if (raycast->ray_dir_x == 0)
		raycast->delta_dist_x = INFINITY;
	else
		raycast->delta_dist_x = abs_value(1 / raycast->ray_dir_x);
	if (raycast->ray_dir_y == 0)
		raycast->delta_dist_y = INFINITY;
	else
		raycast->delta_dist_y = abs_value(1 / raycast->ray_dir_y);
	calculate_delta_and_dist_next(raycast);
}

double	calculate_wall_x(t_game *game, t_raycast *raycast, int mode)
{
	double	wall_x;
	double	percentage_time;
	long	time;

	time = calculate_time();
	if (mode && find_square_anim(game, raycast->map_x, raycast->map_y))
	{
		percentage_time = (double)(time - find_square_anim(game, raycast->map_x,
					raycast->map_y)->time_anim_start);
		percentage_time = percentage_time / 2000;
	}
	else
	percentage_time = (double)0;
	if (ft_strchr("o", game->map[raycast->map_x][raycast->map_y]))
		percentage_time = (double)(1 - percentage_time);
	if (raycast->side == 0)
		wall_x = raycast->pos_y + raycast->dist_perp_wall * raycast->ray_dir_y;
	else
		wall_x = raycast->pos_x + raycast->dist_perp_wall * raycast->ray_dir_x;
	wall_x = wall_x - percentage_time;
	wall_x = wall_x - floor(wall_x);
	return (wall_x);
}
