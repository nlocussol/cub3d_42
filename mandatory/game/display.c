/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:58:13 by averdon           #+#    #+#             */
/*   Updated: 2023/01/27 13:57:22 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	display_rayon(t_game *game, int x, t_raycast *raycast)
{
	int	i;

	if (game->map[raycast->map_x][raycast->map_y] == '1')
	{
		calculate_dist_perp_wall(raycast);
		raycast->line_height = HEIGHT_SCREEN / raycast->dist_perp_wall;
		raycast->draw_start = -raycast->line_height / 2 + HEIGHT_SCREEN / 2;
		if (raycast->draw_start < 0)
			raycast->draw_start = 0;
		raycast->draw_end = raycast->line_height / 2 + HEIGHT_SCREEN / 2;
		if (raycast->draw_end >= HEIGHT_SCREEN)
			raycast->draw_end = HEIGHT_SCREEN - 1;
		draw_line(game, x, raycast);
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

	x = 0;
	raycast.pos_x = game->player->x / SIZE_BLOCK;
	raycast.pos_y = game->player->y / SIZE_BLOCK;
	raycast.dir_x = cos(radian_value(game->player->orientation));
	raycast.dir_y = sin(radian_value(game->player->orientation));
	raycast.plane_x = cos(radian_value(game->player->orientation + 90));
	raycast.plane_y = sin(radian_value(game->player->orientation + 90));
	while (x < WIDTH_SCREEN)
	{
		calculate_delta_and_dist(x, &raycast);
		detect_wall(game, &raycast);
		display_rayon(game, WIDTH_SCREEN - x, &raycast);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->screen_img->img, 0, 0);
}
