/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:24:24 by averdon           #+#    #+#             */
/*   Updated: 2023/01/26 16:32:29 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	destroy_images(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4 && game->images[i])
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
}

void	free_all(t_game *game)
{
	mlx_loop_end(game->mlx);
	free(game->player);
	destroy_images(game);
	mlx_destroy_image(game->mlx, game->screen_img->img);
	free(game->screen_img);
	free(game->text_no);
	free(game->text_so);
	free(game->text_we);
	free(game->text_ea);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_tab(game->map);
	free(game->mlx);
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
