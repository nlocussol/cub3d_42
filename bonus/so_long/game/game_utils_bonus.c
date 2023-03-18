/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:01:19 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:53:34 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	del(void *content)
{
	free(content);
}

void	destroy_all_images(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 28)
	{
		mlx_destroy_image(vars->mlx, vars->array_ptr_sprite[i]);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		mlx_destroy_image(vars->mlx, vars->player->sprite[i]);
		i++;
	}
}

void	destroy_and_free_so_long(t_vars *vars)
{
	t_double_list	*buffer;

	destroy_all_images(vars);
	ft_double_lstclear(&vars->map, del);
	buffer = vars->map_chunk;
	while (vars->map_chunk)
	{
		ft_double_lstclear(&((t_tilemap *)(vars->map_chunk->content))->map,
			del);
		vars->map_chunk = vars->map_chunk->next;
	}
	ft_double_lstclear(&buffer, del);
	free(vars->player->sprite);
	free(vars->player->old_point);
	free(vars->player);
	free(vars->array_ptr_sprite);
	free(vars);
}

void	put_black_screen(t_vars *vars)
{
	int	x;
	int	substract_x;
	int	y;
	int	substract_y;

	x = 0;
	while (x < 17)
	{
		y = 0;
		while (y < 14)
		{
			substract_x = 0;
			substract_y = 0;
			if (x == 16)
				substract_x = 5;
			if (y == 14)
				substract_y = 5;
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->array_ptr_sprite[8],
				X_LEFT_UP_CORNER_GAMEBOY + x * SIZE_BLOCK_SL - substract_x,
				Y_LEFT_UP_CORNER_GAMEBOY + y * SIZE_BLOCK_SL - substract_y);
			y++;
		}
		x++;
	}
}
