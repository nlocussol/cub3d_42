/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:42:50 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:54:26 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_BONUS_H

# define KEYS_BONUS_H

int				key_hook_so_long(int keycode, t_vars *vars);
int				key_right(t_vars *vars, char actual_place);
int				key_left(t_vars *vars, char actual_place);
int				key_down(t_vars *vars, char actual_place);
int				key_up(t_vars *vars, char actual_place);
int				check_key_next_next_next(int keycode, t_vars *vars,
					t_double_list *buffer, int x);
int				check_key_next_next(int keycode, t_vars *vars,
					t_double_list *buffer, int x);
int				check_key_next(int keycode, t_vars *vars,
					t_double_list *buffer, int x);
int				check_key(int keycode, t_vars *vars,
					t_double_list *buffer, int x);
int				key_to_move(int keycode);
void			check_collectibles_to_exit(t_vars *vars);
int				key_to_move(int keycode);
void			advance_x_and_y(int *y, int *x,
					t_vars *vars, t_double_list **buffer);
void			check_after_game(int keycode, t_vars *vars);
void			check_action_on_map(t_vars *vars);
void			item_collected(t_vars *vars, char *actual_place);
void			modify_display(t_vars *vars);
int				check_echap(t_vars *vars);
int				close_window_so_long(t_vars *vars);

#endif
