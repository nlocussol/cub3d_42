/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_so_long_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:29:26 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:53:56 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SO_LONG_BONUS_H

# define GAME_SO_LONG_BONUS_H

# include "enemies/enemies_bonus.h"
# include "keys/keys_bonus.h"
# include "display_map/display_map_bonus.h"
# include "set_up_game/set_up_game_bonus.h"

int				calculate_columns(t_double_list *map);
int				calculate_collectibles(t_double_list **map);
int				calculate_rows(t_double_list *map);
void			destroy_and_free_so_long(t_vars *vars);
int				animations(t_vars *vars);
int				animation_and_movement(t_vars *vars);
void			del(void *content);
void			put_black_screen(t_vars *vars);

#endif
