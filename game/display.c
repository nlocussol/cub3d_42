/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:58:13 by averdon           #+#    #+#             */
/*   Updated: 2023/01/23 18:07:40 by averdon          ###   ########.fr       */
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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_game *game, int x, int drawStart, int drawEnd, int	side, int stepX, int stepY)
{
	int	i;

	i = 0;
	while (i < drawStart)
	{
		my_mlx_pixel_put(game->screen_img, x, i, game->data->hex_c);
		i++;
	}
	while (drawStart < drawEnd)
	{
		if (side == 0)
		{
			if (stepX == 1)
				my_mlx_pixel_put(game->screen_img, x, drawStart, 0xFF0000);
			else
				my_mlx_pixel_put(game->screen_img, x, drawStart, 0x00FF00);
		}
		else if (side == 1)
		{
			if (stepY == 1)
				my_mlx_pixel_put(game->screen_img, x, drawStart, 0x0000FF);
			else
				my_mlx_pixel_put(game->screen_img, x, drawStart, 0xFF0091);
		}
		drawStart++;
	}
	while (drawEnd < HEIGHT_SCREEN)
	{
		my_mlx_pixel_put(game->screen_img, x, drawEnd, game->data->hex_f);
		drawEnd++;
	}
}

void	reload_display(t_game *game)
{
	double	posX = game->player->x / SIZE_BLOCK;
	double	posY = game->player->y / SIZE_BLOCK;
	double	dirX = cos(radian_value(game->player->orientation));
	double	dirY = sin(radian_value(game->player->orientation));
	double	planeX = cos(radian_value(game->player->orientation + 90));
	double	planeY = sin(radian_value(game->player->orientation + 90));
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
			drawEnd = HEIGHT_SCREEN - 1;
		
		draw_line(game, x, drawStart, drawEnd, side, stepX, stepY);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->screen_img->img, 0, 0);
}
