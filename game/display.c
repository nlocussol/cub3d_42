/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:58:13 by averdon           #+#    #+#             */
/*   Updated: 2023/01/26 10:52:17 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	my_mlx_pixel_put(t_game *game, t_img *img, int x, int y, int color)
{
	char	*dst;
	(void)game;
	
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	
}

void	draw_line(t_game *game, int x, int drawStart, int drawEnd, int	side, int stepX, int stepY, double posX, double posY, double rayDirX, double rayDirY, double perpWallDist, int lineHeight)
{
	int	i;
	double WallX;
	double step;
	double	texPos;
	int	texX;
	int	texY;
	unsigned int color;

	if (side == 0)
		WallX = posY + perpWallDist * rayDirY;
	else
		WallX = posX + perpWallDist * rayDirX;
	WallX -= floor(WallX);
	texX = (int)(WallX * (double)(256));
	if ((side == 0 && rayDirX > 0) || (side == 1 && rayDirY < 0))
		texX = 256 - texX - 1;

	step = 1.0 * 256 / lineHeight;
	texPos = (drawStart - HEIGHT_SCREEN / 2 + lineHeight / 2) * step;
	i = 0;
	while (i < drawStart)
	{
		my_mlx_pixel_put(game, game->screen_img, x, i, game->hex_c);
		i++;
	}
	while (drawStart < drawEnd)
	{
		texY = (int)texPos & (256 - 1);
		texPos += step;
		if (side == 0)
		{
			if (stepX == 1)
				color = game->images[0][texY][texX];
			else
				color = game->images[1][texY][texX];
		}
		else if (side == 1)
		{
			if (stepY == 1)
				color = game->images[2][texY][texX];
			else
				color = game->images[3][texY][texX];
		}
		my_mlx_pixel_put(game, game->screen_img, x, drawStart, color);
		drawStart++;
	}
	while (drawEnd < HEIGHT_SCREEN)
	{
		my_mlx_pixel_put(game, game->screen_img, x, drawEnd, game->hex_f);
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
	int		i;

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
			if (!ft_strchr("0WESN ", game->map[mapX][mapY]))
				hit = 1;
		}
		if (game->map[mapX][mapY] == '1')
		{
			if (side == 0)
				perpWallDist = (sideDistX - deltaDistX);
			else
				perpWallDist = (sideDistY - deltaDistY);	
			if (perpWallDist == 0)
				perpWallDist = INFINITY;
			lineHeight = HEIGHT_SCREEN / perpWallDist;
			drawStart = -lineHeight / 2 + HEIGHT_SCREEN / 2;
			if (drawStart < 0)
				drawStart = 0;
			drawEnd = lineHeight / 2 + HEIGHT_SCREEN / 2;
			if (drawEnd	>= HEIGHT_SCREEN)
				drawEnd = HEIGHT_SCREEN - 1;
			draw_line(game, x, drawStart, drawEnd, side, stepX, stepY, posX, posY, rayDirX, rayDirY, perpWallDist, lineHeight);
		}
		else
		{
			i = 0;
			while (i < HEIGHT_SCREEN)
			{
				my_mlx_pixel_put(game, game->screen_img, x, i, 0);
				i++;
			}
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->screen_img->img, 0, 0);
}
