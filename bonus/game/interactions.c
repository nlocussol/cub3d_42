/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:21:26 by averdon           #+#    #+#             */
/*   Updated: 2023/01/31 15:07:08 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "game.h"

void	interact(t_game *game)
{
	t_raycast	raycast;
	long		time_start_anim;
	long		actual_time;

	raycast.pos_x = game->player->x / SIZE_BLOCK;
	raycast.pos_y = game->player->y / SIZE_BLOCK;
	raycast.dir_x = cos(radian_value(game->player->orientation));
	raycast.dir_y = sin(radian_value(game->player->orientation));
	raycast.plane_x = cos(radian_value(game->player->orientation + 90));
	raycast.plane_y = sin(radian_value(game->player->orientation + 90));
	calculate_delta_and_dist(WIDTH_SCREEN / 2, &raycast);
	detect_wall(game, &raycast);
	calculate_dist_perp_wall(&raycast);
	if (raycast.dist_perp_wall > (double)1)
		return ;
	if (game->map[raycast.map_x][raycast.map_y] == 'D')
	{
		time_start_anim = calculate_time();
		actual_time = time_start_anim;
		int	x = 0;
		int i;
		while (actual_time - time_start_anim < 2000)
		{
			actual_time = calculate_time();
			while (x < WIDTH_SCREEN)
			{
				i = 0;
				while (i < HEIGHT_SCREEN)
				{
					//mlx_pixel_put(game->mlx, game->window, x, i, 0);
					my_mlx_pixel_put(game->screen_img, x, i, 0);
					i++;
				}
				x++;
			}
			mlx_put_image_to_window(game->mlx, game->window,
				game->screen_img->img, 0, 0);
			//display_screen(game, actual_time - time_start_anim);
			printf("%ld interact\n", actual_time - game->time_start);
			usleep(1000);
		}
		game->map[raycast.map_x][raycast.map_y] = 'd';
	}
	else if (game->map[raycast.map_x][raycast.map_y] == 'd')
	{
		game->map[raycast.map_x][raycast.map_y] = 'D';
	}
	/*
	else if (game->map[raycast.map_x][raycast.map_y] == '1')
		add_graffiti(game);
	*/
}
