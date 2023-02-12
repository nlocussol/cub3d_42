/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:44:16 by averdon           #+#    #+#             */
/*   Updated: 2022/11/18 01:01:12 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_VALID_PATH_H

# define CHECK_VALID_PATH_H

void			check_valid_path(t_double_list	**map);
t_point			*find_start(t_double_list	**map);
void			fload_map(t_double_list *map, int start_x, int start_y);
t_double_list	*create_list_copy(t_double_list **initial_list);
void			modify_map_clean(t_double_list *map_clean, t_double_list **map);
void			search_components(t_double_list **map,
					t_double_list **components);
int				verify_components_accessibility(t_double_list **map_clean,
					t_double_list	**components);

#endif
