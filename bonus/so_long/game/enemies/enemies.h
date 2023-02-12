/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:25:17 by averdon           #+#    #+#             */
/*   Updated: 2022/11/17 11:28:05 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_H

# define ENEMIES_H

int		enemies_movement(t_vars *vars);
void	enemy_go_down(int y, int i, t_vars *vars, t_double_list *buffer);
void	enemy_go_left(int y, int i, t_vars *vars, t_double_list *buffer);
void	enemy_go_up(int y, int i, t_vars *vars, t_double_list *buffer);
void	enemy_go_right(int y, int i, t_vars *vars, t_double_list *buffer);
void	enemy_kill_player(t_vars *vars);
void	update_map_chunk(t_vars *vars);
void	advance_buffer_and_y(t_double_list **buffer, int *y);
void	randomize_enemies(t_vars *vars);
void	find_line(int *y, t_double_list **buffer_map,
			t_double_list **buffer_place_enemies);
void	write_enemy(t_double_list **buffer_place_enemies,
			t_double_list **buffer_map);

#endif
