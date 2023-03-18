/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:31:35 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 13:00:04 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_BONUS_H

# define DISPLAY_BONUS_H

# include "../game_bonus.h"

/*calculate_display.c*/
unsigned int	calculate_color(int x, int y, t_img *img);
double			calculate_wall_x(t_game *game, t_raycast *raycast, int mode);
void			calculate_delta_and_dist(int x, t_raycast *raycast);
void			calculate_dist_perp_wall(t_game *game, t_raycast *raycast);

/*display.c*/
void			display_rayon(t_game *game, int x, t_raycast *raycast);
void			display_screen(t_game *game);
void			detect_wall(t_game *game, t_raycast *raycast);

/*draw_display.c*/
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			draw_line(t_game *game, int x, t_raycast *raycast);

/*inventory_bar.c*/
void			nb_game_bar(t_game *game);
void			game_bar(t_game *game);
void			move_bar(t_game *game);
void			put_one_case(t_game *game, int x_tmp, int y_tmp, int color);
void			put_big_case(t_game *game, int x_tmp, int y_tmp, int color);

/*minimap.c*/
void			open_minimap(t_game *game);
void			put_one_block(t_game *game, unsigned int color);
void			put_assets(t_game *game, unsigned int **color);
int				calculate_arrow(int a, int b, int mode);
void			put_cursor(t_game *game, int x, int y);
void			put_arrow(t_game *game, int i_minimap, int j_minimap, int mode);

/*door_recessed.c*/
bool			door_should_be_recessed(t_game *game, int x,
					t_raycast *raycast);
bool			wall_should_appear_not_door(t_game *game, t_raycast *raycast,
					long time);

/*parse_image.c*/
bool			parse_one_group_image(t_game *game, unsigned int ***game_tab,
					char **name_img_tab, int length_tab);

/*parse_image_utils.c*/
void			free_previous_malloc(unsigned int ***image, int y);
void			free_group(t_game *game, int nb_group_image);

/*launch_parsing_image.c*/
bool			parse_image(t_game *game);

/*draw_image.c*/
void			draw_image(t_game *game, unsigned int **img, int x, int y);

#endif
