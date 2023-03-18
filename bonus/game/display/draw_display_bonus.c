/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_display_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:29:09 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:59:16 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	unsigned char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	find_texture_wall(t_game *game, t_raycast *raycast,
		int tex_x, int tex_y)
{
	int	color;

	color = 0;
	if (raycast->side == 0)
	{
		if (raycast->step_x == 1)
			color = game->images[0][tex_y][tex_x];
		else
			color = game->images[1][tex_y][tex_x];
	}
	else if (raycast->side == 1)
	{
		if (raycast->step_y == 1)
			color = game->images[2][tex_y][tex_x];
		else
			color = game->images[3][tex_y][tex_x];
	}
	return (color);
}

unsigned int	color_to_draw(t_game *game, t_raycast *raycast,
		int tex_x, int tex_y)
{
	static long	time;
	t_graff		*graff;
	int			color;
	int			frame;

	if (game == NULL)
	{
		time = calculate_time();
		return (0);
	}
	color = 0;
	graff = find_square_graff(game, raycast);
	if (graff && time - graff->time_start >= 2500)
	{
		frame = 5 + graff->frame;
		color = game->images[frame][tex_y][tex_x];
		if (color >= 0)
			return (color);
	}
	if (game->map[raycast->map_x][raycast->map_y] == '1')
		color = find_texture_wall(game, raycast, tex_x, tex_y);
	else
		color = game->images[4][tex_y][tex_x];
	return (color);
}

void	draw_wall(t_game *game, t_raycast *raycast, int x, double wall_x)
{
	double			tex_pos;
	double			step;
	int				tex_x;
	int				tex_y;
	unsigned int	color;

	step = 1.0 * 256 / raycast->line_height;
	tex_x = (int)(wall_x * (double)(256));
	if ((raycast->side == 0 && raycast->ray_dir_x > 0)
		|| (raycast->side == 1 && raycast->ray_dir_y < 0))
		tex_x = 256 - tex_x - 1;
	tex_pos = raycast->draw_start - game->mouse_height;
	tex_pos += raycast->line_height / 2;
	tex_pos *= step;
	color_to_draw(NULL, NULL, 0, 0);
	while (raycast->draw_start < raycast->draw_end)
	{
		tex_y = (int)tex_pos % (256 - 1);
		tex_pos += step;
		color = color_to_draw(game, raycast, tex_x, tex_y);
		my_mlx_pixel_put(game->screen_img, x, raycast->draw_start, color);
		raycast->draw_start++;
	}
}

void	draw_line(t_game *game, int x, t_raycast *raycast)
{
	int		i;

	i = 0;
	while (i < raycast->draw_start)
	{
		my_mlx_pixel_put(game->screen_img, x, i, game->hex_c);
		i++;
	}
	draw_wall(game, raycast, x, calculate_wall_x(game, raycast, 1));
	while (raycast->draw_end < HEIGHT_SCREEN)
	{
		my_mlx_pixel_put(game->screen_img, x, raycast->draw_end, game->hex_f);
		raycast->draw_end++;
	}
}
