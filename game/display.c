/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:58:13 by averdon           #+#    #+#             */
/*   Updated: 2023/01/20 16:43:36 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

double	abs_value(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

double	radian_value(double degree)
{
	return (degree * M_PI / 180);
}

void	draw_line(t_game *game, int x, double drawStart, double drawEnd, int color)
{
	while (drawStart < drawEnd)
	{
		mlx_pixel_put(game->mlx, game->window, x, drawStart, color);
		drawStart++;
	}
}

void	reload_display(t_game *game)
{
	double	posX = game->player->x / SIZE_BLOCK;
	double	posY = game->player->y / SIZE_BLOCK;
	double	dirX = cos(radian_value(game->player->orientation));
	double	dirY = sin(radian_value(game->player->orientation));
	double	planeX = 0;
	double	planeY = 0.66;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	int		x;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		side;
	int		hit;
	int		drawStart;
	int		drawEnd;
	int		lineHeight;

	x = 0;
	while (x < WIDTH_SCREEN)
	{
		cameraX = 2 * x / (double)(WIDTH_SCREEN) - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		
		mapX = posX;
		mapY = posY;
		if (rayDirX == 0)
			deltaDistX = INFINITY;
		else
			deltaDistX = abs_value(1 / rayDirX);
		if (rayDirY == 0)
			deltaDistY = INFINITY;
		else
			deltaDistY = abs_value(1 / rayDirY);

		if	(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if	(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		
		hit = 0;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (game->map[mapX][mapY] != '0' && game->map[mapX][mapY] != 'N')
				hit = 1;
		}
		//printf("%d %d %c\n", mapX, mapY, game->map[mapX][mapY]);	
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);	
	
		//printf("%d %lf\n", side, perpWallDist);
		lineHeight = HEIGHT_SCREEN / perpWallDist;
		drawStart = -lineHeight / 2 + HEIGHT_SCREEN / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + HEIGHT_SCREEN / 2;
		if (drawEnd	>= HEIGHT_SCREEN)
			drawEnd= HEIGHT_SCREEN - 1;
		
		draw_line(game, x, drawStart, drawEnd, 0xFFFFFF);
		x++;
	}
}
