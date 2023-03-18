/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:00:26 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:57:35 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	destroy_one_group_image(unsigned int ***img, int nb_images)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_images)
	{
		j = 0;
		if (img[i])
		{
			while (img[i][j])
			{
				free(img[i][j]);
				j++;
			}
			free(img[i]);
		}
		i++;
	}
}

void	destroy_images(t_game *game)
{
	destroy_one_group_image(game->images, 11);
	destroy_one_group_image(game->minimap_img, 4);
	destroy_one_group_image(game->bar_img, 7);
	destroy_one_group_image(game->arm_img, 5);
	destroy_one_group_image(game->anim_gameboy, 10);
}

void	kill_sound_forks(t_game *game)
{
	t_double_list	*next;
	t_song			*song;

	while (game->lst_sound)
	{
		song = game->lst_sound->content;
		kill(song->pid, SIGKILL);
		next = game->lst_sound->next;
		ft_double_lstdelone(game->lst_sound, del);
		game->lst_sound = next;
	}
}

void	free_all(t_game *game)
{
	mlx_loop_end(game->mlx);
	kill_sound_forks(game);
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
}

int	close_window(t_game *game)
{
	t_double_list	*buffer;
	t_double_list	*next;
	t_song			*song;

	ft_fdprintf(1, "Exit Program\n");
	buffer = game->lst_sound;
	while (buffer)
	{
		song = buffer->content;
		next = buffer->next;
		if (song->type == START_GAMEBOY)
			break ;
		buffer = next;
	}
	if (game->started_gameboy == true && !buffer)
		destroy_and_free_so_long(game->vars);
	free_all(game);
	exit (0);
}
