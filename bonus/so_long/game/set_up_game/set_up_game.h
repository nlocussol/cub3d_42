/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_game.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:43:24 by averdon           #+#    #+#             */
/*   Updated: 2022/11/18 00:50:31 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_UP_GAME_H

# define SET_UP_GAME_H

void			set_up_array_ptr_player(t_vars *vars);
void			set_up_array_ptr_tile(t_vars *vars);
void			initialize_var(t_vars *vars, t_double_list *map,
					int argc, char **argv);
t_double_list	*divise_map(t_vars *vars);

#endif
