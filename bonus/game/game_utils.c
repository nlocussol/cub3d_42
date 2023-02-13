/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:24:24 by averdon           #+#    #+#             */
/*   Updated: 2023/02/13 19:28:02 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	destroy_images(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 11)
	{
		j = 0;
		while (game->images[i][j])
		{
			free(game->images[i][j]);
			j++;
		}
		free(game->images[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (game->minimap_img[i][j])
		{
			free(game->minimap_img[i][j]);
			j++;
		}
		free(game->minimap_img[i]);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		j = 0;
		while (game->bar_img[i][j])
		{
			free(game->bar_img[i][j]);
			j++;
		}
		free(game->bar_img[i]);
		i++;
	}
	j = 0;
	while (game->arm_img[0][j])
	{
		free(game->arm_img[0][j]);
		j++;
	}
	free(game->arm_img[0]);
}

void	free_all(t_game *game)
{
	mlx_loop_end(game->mlx);
	free(game->player);
	ft_double_lstclear(&game->lst_anim, del);
	ft_double_lstclear(&game->lst_graff, del);
	destroy_images(game);
	mlx_destroy_image(game->mlx, game->screen_img->img);
	free(game->screen_img);
	free(game->text_no);
	free(game->text_so);
	free(game->text_we);
	free(game->text_ea);
	free(game->text_do);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_tab(game->map);
	free(game->mlx);
	free(game);
}

int	close_window(t_game *game)
{
	ft_fdprintf(1, "Exit Program\n");
	free_all(game);
	exit (0);
}

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
