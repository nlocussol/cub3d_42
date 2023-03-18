/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:57:59 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:54:14 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	item_collected(t_vars *vars, char *actual_place)
{
	t_double_list	*buffer_2;

	*actual_place = '0';
	vars->player->nb_collectibles++;
	buffer_2 = vars->map_chunk;
	while (vars->map_chunk)
	{
		ft_double_lstclear(&((t_tilemap *)(vars->map_chunk->content))->map,
			del);
		vars->map_chunk = vars->map_chunk->next;
	}
	ft_double_lstclear(&buffer_2, del);
	vars->map_chunk = divise_map(vars);
	if (vars->player->nb_collectibles == vars->nb_collectibles)
	{
		display_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player->sprite[vars->player->frame + vars->player->side],
			vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
			vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	}
}

void	check_action_on_map(t_vars *vars)
{
	t_double_list	*buffer;
	int				x;
	int				y;

	buffer = vars->map;
	y = 0;
	x = 0;
	while (y < (vars->player->y / SIZE_BLOCK_SL))
	{
		y++;
		buffer = buffer->next;
	}
	while (x < vars->player->x / SIZE_BLOCK_SL)
		x++;
	if (((char *)(buffer->content))[x] == 'C')
		item_collected(vars, &((char *)(buffer->content))[x]);
	else if (((char *)(buffer->content))[x] == 'E')
		check_collectibles_to_exit(vars);
}

void	display_nb_action(t_vars *vars)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(vars->player->nb_move);
	if (ft_strlen(str) > 4)
	{
		free(str);
		str = ft_strdup("9999");
	}
	while (str[i])
	{
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->array_ptr_sprite[14 + str[i] - 48],
			SIZE_BLOCK_SL * 10 + 10 + i * SIZE_BLOCK_SL + X_LEFT_UP_CORNER_GAME,
			SIZE_BLOCK_SL + Y_LEFT_UP_CORNER_GAME);
		i++;
	}
	free(str);
}

void	modify_display(t_vars *vars)
{
	if (vars->game_finish)
		return ;
	if (vars->player->old_point->x / (SIZE_BLOCK_SL * 10)
		!= (vars->player->x / (SIZE_BLOCK_SL * 10)))
		display_map(vars);
	if (vars->player->old_point->y / (SIZE_BLOCK_SL * 10)
		!= (vars->player->y / (SIZE_BLOCK_SL * 10)))
		display_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->player->sprite[vars->player->frame + vars->player->side],
		vars->player->x % (SIZE_BLOCK_SL * 10) + X_LEFT_UP_CORNER_GAME,
		vars->player->y % (SIZE_BLOCK_SL * 10) + Y_LEFT_UP_CORNER_GAME);
	display_nb_action(vars);
}

int	key_hook_so_long(int keycode, t_vars *vars)
{
	t_double_list	*buffer;
	int				x;
	int				y;
	int				value_return;

	if (vars->game_finish)
	{
		check_after_game(keycode, vars);
		return (0);
	}
	buffer = vars->map;
	y = 0;
	x = 0;
	value_return = 0;
	vars->player->old_point->x = vars->player->x;
	vars->player->old_point->y = vars->player->y;
	advance_x_and_y(&y, &x, vars, &buffer);
	value_return = check_key(keycode, vars, buffer, x);
	if (value_return != 0)
		return (0);
	if (key_to_move(keycode) == 1)
		modify_display(vars);
	check_action_on_map(vars);
	return (0);
}
