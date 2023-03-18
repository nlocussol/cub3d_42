/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:32:33 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:55:48 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	display_minimap(t_vars *vars)
{
	t_double_list	*buffer;
	t_tilemap		*tile;
	int				sprite;
	int				coord_x;
	int				coord_y;

	buffer = vars->map_chunk;
	coord_x = (SIZE_BLOCK_SL + 1) * 10 + X_LEFT_UP_CORNER_GAME;
	coord_y = SIZE_BLOCK_SL / 2 * 10 + Y_LEFT_UP_CORNER_GAME;
	while (buffer)
	{
		tile = buffer->content;
		if ((tile->x == vars->player->x / (SIZE_BLOCK_SL * 10))
			&& (tile->y == vars->player->y / (SIZE_BLOCK_SL * 10)))
			sprite = 25;
		else
			sprite = 24;
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[sprite],
			tile->x * SIZE_BLOCK_SL / 2 + coord_x,
			tile->y * SIZE_BLOCK_SL / 2 + coord_y);
		buffer = buffer->next;
	}
}

void	display_background(t_vars *vars)
{
	int				x;
	int				y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 5)
		{
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[8],
				X_LEFT_UP_CORNER_GAME + SIZE_BLOCK_SL * 10 + x * SIZE_BLOCK_SL,
				Y_LEFT_UP_CORNER_GAME + y * SIZE_BLOCK_SL);
			x++;
		}
		y++;
	}
	display_minimap(vars);
}

void	display_good_tiles_2(t_vars *vars, t_double_list *map, int x, int y)
{
	if (((char *)(map->content))[x] == 'E')
	{
		if (vars->player->nb_collectibles != vars->nb_collectibles)
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[13],
				X_LEFT_UP_CORNER_GAME + x * SIZE_BLOCK_SL,
				Y_LEFT_UP_CORNER_GAME + y * SIZE_BLOCK_SL);
		else
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[7],
				X_LEFT_UP_CORNER_GAME + x * SIZE_BLOCK_SL,
				Y_LEFT_UP_CORNER_GAME + y * SIZE_BLOCK_SL);
	}
	else if (((char *)(map->content))[x] == 'M')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[9 + vars->frame_enemy],
			X_LEFT_UP_CORNER_GAME + x * SIZE_BLOCK_SL,
			Y_LEFT_UP_CORNER_GAME + y * SIZE_BLOCK_SL);
}

void	display_good_tiles(t_vars *vars, t_double_list *map, int x, int y)
{
	if (((char *)(map->content))[x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[0],
			X_LEFT_UP_CORNER_GAME + x * SIZE_BLOCK_SL,
			Y_LEFT_UP_CORNER_GAME + y * SIZE_BLOCK_SL);
	else if (((char *)(map->content))[x] == '1')
		display_good_wall(vars, map, x, y);
	else if (((char *)(map->content))[x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[6],
			X_LEFT_UP_CORNER_GAME + x * SIZE_BLOCK_SL,
			Y_LEFT_UP_CORNER_GAME + y * SIZE_BLOCK_SL);
	else
		display_good_tiles_2(vars, map, x, y);
}

void	display_map(t_vars *vars)
{
	t_double_list	*buffer;
	t_double_list	*map;
	int				x;
	int				y;
	t_tilemap		*tile;

	buffer = vars->map_chunk;
	tile = buffer->content;
	while ((tile->x != vars->player->x / (SIZE_BLOCK_SL * 10))
		|| (tile->y != vars->player->y / (SIZE_BLOCK_SL * 10)))
	{
		buffer = buffer->next;
		tile = buffer->content;
	}
	y = 0;
	map = (t_double_list *)((t_tilemap *)(buffer->content))->map;
	while (map)
	{
		x = -1;
		while (++x < 10)
			display_good_tiles(vars, map, x, y);
		y++;
		map = map->next;
	}
	display_minimap(vars);
}
