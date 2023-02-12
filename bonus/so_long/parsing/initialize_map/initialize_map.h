/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:45:19 by averdon           #+#    #+#             */
/*   Updated: 2022/11/18 00:58:51 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_MAP_H

# define INITIALIZE_MAP_H

t_double_list	*initialize_map(char *file);
void			check_last_line(t_double_list **map);
void			check_first_line(t_double_list **map);
void			check_borders(t_double_list **map);

#endif
