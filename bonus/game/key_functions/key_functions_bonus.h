/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:53:52 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:58:36 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_FUNCTIONS_BONUS_H

# define KEY_FUNCTIONS_BONUS_H

/*animations.c*/
void	check_update(t_game *game);
void	anim_start_gameboy(t_game *game);
void	update_song(t_game *game);

/*player_movement.c*/
int		key_pressed(int keycode, t_game *game);
int		key_released(int keycode, t_game *game);
void	move_player(t_game	*game, int move);

/*player_actions.c*/
int		key_hook(int keycode, t_game *game);

/*move_camera.c*/
void	turn_camera(t_game	*game, int move);
int		move_camera(void *arg);

/*launch_animations_and_movements.c*/
int		launch_movements(t_game *game);

/*utils.c*/
int		mouse_hook(int mouse, int x, int y, t_game *game);

/*interactions.c*/
void	interact(t_game *game, int *mouse_pos_x, int *mouse_pos_y);

#endif
