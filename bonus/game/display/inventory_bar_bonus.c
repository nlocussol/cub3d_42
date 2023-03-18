/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory_bar_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:13:31 by nlocusso          #+#    #+#             */
/*   Updated: 2023/03/18 12:59:15 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	nb_game_bar(t_game *game)
{
	int		i;
	int		x;
	int		y;
	char	*nb;

	x = 834;
	y = 448;
	i = 0;
	while (i != 7)
	{
		nb = ft_itoa(i + 1);
		mlx_string_put(game->mlx, game->window, y + 20, x + 110, 0xB39797, nb);
		free(nb);
		y += 128;
		i++;
	}
}

void	draw_bar(t_game *game, int x, int y, int i)
{
	if (i + 1 == game->bar_index)
		put_big_case(game, x - 5, y - 5, 0xDFDFDF);
	if (i == 3)
		draw_image(game, game->bar_img[2], y + 15, x + 10);
	if (i == 1)
		draw_image(game, game->bar_img[3], y + 15, x + 10);
	if (i == 2)
		draw_image(game, game->bar_img[4], y + 15, x + 10);
	if (i == 4)
		draw_image(game, game->bar_img[5], y + 15, x + 10);
}

void	define_var(int *x, int *y, int *i, int *anim)
{
	*x = 834;
	*y = 448;
	*i = 0;
	(*anim)++;
}

void	game_bar(t_game *game)
{
	int			x;
	int			y;
	int			i;
	static int	anim = 0;

	define_var(&x, &y, &i, &anim);
	while (y < 1344)
	{
		put_one_case(game, x, y, 0xB39797);
		if (i == 0 && anim <= 50)
			draw_image(game, game->bar_img[0], y + 15, x + 10);
		else if (i == 0 && anim > 50)
		{
			if (anim == 100)
				anim = 0;
			draw_image(game, game->bar_img[1], y + 15, x + 10);
		}
		draw_bar(game, x, y, i);
		y += 128;
		i++;
	}
	if (game->bar_index < 6 && game->bar_index > 1)
		draw_image(game, game->arm_img[game->bar_index - 1], 1570, 766);
	else
		draw_image(game, game->arm_img[0], 1570, 766);
}
