/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:41:56 by averdon           #+#    #+#             */
/*   Updated: 2022/11/18 00:54:46 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_MAP_H

# define DISPLAY_MAP_H

void			display_good_tiles(t_vars *vars, t_double_list *map,
					int x, int y);
void			display_good_wall_2(t_vars *vars, t_double_list *map,
					int x, int y);
void			display_good_wall(t_vars *vars, t_double_list *map,
					int x, int y);
void			display_map(t_vars *vars);
void			display_background(t_vars *vars);
int				check_right_top_corner(t_double_list *map, int x);
int				check_left_top_corner(t_double_list *map, int x);
int				check_right_bot_corner(t_double_list *map, int x);
int				check_left_bot_corner(t_double_list *map, int x);
int				check_left_side(t_double_list *map, int x);
int				check_right_side(t_double_list *map, int x);
int				check_top_side(t_double_list *map, int x);
int				check_bot_side(t_double_list *map, int x);
int				check_crate(t_vars *vars, int x, int y);

#endif
