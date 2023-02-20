/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:31:35 by averdon           #+#    #+#             */
/*   Updated: 2023/02/20 16:33:13 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H

# define DISPLAY_H

# include "../game.h"

unsigned int	calculate_color(int x, int y, t_img *img);
double			calculate_wall_x(t_game *game, t_raycast *raycast, int mode);
void			display_rayon(t_game *game, int x, t_raycast *raycast);
void			nb_game_bar(t_game *game);
void			game_bar(t_game *game);
void			open_minimap(t_game *game);
void			display_screen(t_game *game);
void			draw_line(t_game *game, int x, t_raycast *raycast);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			calculate_delta_and_dist(int x, t_raycast *raycast);
void			calculate_dist_perp_wall(t_game *game, t_raycast *raycast);
void			detect_wall(t_game *game, t_raycast *raycast);
bool			door_should_be_recessed(t_game *game, int x,
					t_raycast *raycast);
bool			wall_should_appear_not_door(t_game *game, t_raycast *raycast,
					long time);
bool			parse_one_group_image(t_game *game, unsigned int ***game_tab,
					char **name_img_tab, int length_tab);
void			move_bar(t_game *game);
void			free_previous_malloc(unsigned int ***image, int y);
void			free_group(t_game *game, int nb_group_image);

#endif
