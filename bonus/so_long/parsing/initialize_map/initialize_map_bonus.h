/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:45:19 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:52:34 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_MAP_BONUS_H

# define INITIALIZE_MAP_BONUS_H

t_double_list	*initialize_map(char *file);
void			check_last_line(t_double_list **map);
void			check_first_line(t_double_list **map);
void			check_borders(t_double_list **map);

#endif
