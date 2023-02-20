/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:03:49 by averdon           #+#    #+#             */
/*   Updated: 2023/02/20 10:20:36 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "../cub3d.h"

void	draw_image(t_game *game, unsigned int **img, int x, int y);
int		mouse_hook(int mouse, int x, int y, t_game *game);
void	start_game(t_data *data, char **env);
void	initialize_game(t_game	*game, t_data *data);
void	parse_image(t_game *game);
void	create_border(t_game *game);

int		launch_movements(t_game *game);
int		key_pressed(int keycode, t_game *game);
int		key_released(int keycode, t_game *game);
int		key_hook(int keycode, t_game *game);
void	move_player(t_game	*game, int move);
void	turn_camera(t_game	*game, int move);
int		move_camera(void *arg);
void	interact(t_game *game, int *mouse_pos_x, int *mouse_pos_y);

void	launch_song(t_game *game, int mode);
void	suppress_node_sound(t_game *game, t_double_list *buffer);
#endif
