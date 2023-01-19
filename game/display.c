/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:58:13 by averdon           #+#    #+#             */
/*   Updated: 2023/01/19 23:32:24 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	abs_value(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	draw_line(t_game *game, double distance, double adjustement)
{
	double	pixels;

	pixels = HEIGHT_SCREEN / distance;
	printf("nb pixel %lf | place %lf\n", pixels, game->player->orientation + adjustement);
	while (pixels > 0)
	{
		mlx_pixel_put(game->mlx, game->window, adjustement, pixels, 0xFFFFFF);
		pixels--;
	}
}

double	launch_rayon(t_game *game, double adjustement)
{
	double	pt_x;
	double	pt_y;
	double	distance;

	pt_x = game->player->x;
	pt_y = game->player->y;
	/*
	printf("\n\nradian : %lf | cos : %lf | sin :%lf", game->player->orientation * M_PI / 180, 
			cos(game->player->orientation * M_PI / 180), sin(game->player->orientation * M_PI / 180));
	*/
	while (game->map[(int)(pt_y / SIZE_BLOCK)][(int)(pt_x / SIZE_BLOCK)] == '0'
		|| game->map[(int)(pt_y / SIZE_BLOCK)][(int)(pt_x / SIZE_BLOCK)] == 'N')
	{	
		pt_x = pt_x + abs_value(cos((game->player->orientation + adjustement) * M_PI / 180));
		pt_y = pt_y + abs_value(sin((game->player->orientation + adjustement) * M_PI / 180));
	}
	/*
	printf("\n\nabs pt_x %lf | pt_x : %lf\nabs pt_y %lf| pt_y : %lf\nplayer_x %lf | player_y %lf",
		pt_x / SIZE_BLOCK,
		pt_x / SIZE_BLOCK + (int)(pt_x * 100) % SIZE_BLOCK,
		pt_y / SIZE_BLOCK,
		pt_y / SIZE_BLOCK + (int)(pt_y * 100) % SIZE_BLOCK,
		game->player->x / SIZE_BLOCK + (int)(game->player->x * 100) % SIZE_BLOCK,
		game->player->y / SIZE_BLOCK + (int)(game->player->y * 100) % SIZE_BLOCK);
	*/
	//printf("%lf\n", pt_y / 64);
	distance = sqrt(pow(pt_x - game->player->x, 2) + pow(pt_y - game->player->y, 2)) / SIZE_BLOCK - 1;
	return (distance);
}

void	reload_display(t_game *game)
{
	double	distance;
	double	i;

	i = 0;
	printf("%d\n", game->player->orientation);
	while (i <= WIDTH_SCREEN) 
	{
		printf("%lf\n", i / 10);
		distance = launch_rayon(game, i);
		draw_line(game, distance, i);
		i++;
	}
}
