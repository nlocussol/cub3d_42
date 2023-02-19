/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:05:24 by averdon           #+#    #+#             */
/*   Updated: 2023/02/19 16:45:38 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

void	destroy_images(t_game *game);
void	free_all(t_game *game);
int		close_window(t_game *game);

double	abs_value(double nb);
double	radian_value(double degree);
long	calculate_time(void);

t_anim	*find_square_anim(t_game *game, int x, int y);
t_graff	*find_square_graff(t_game *game, t_raycast *raycast);
void	suppress_node_anim(t_game *game, int x, int y);
void	suppress_node_graff(t_game *game, t_raycast *raycast);

#endif
