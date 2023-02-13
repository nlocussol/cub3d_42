/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:02:05 by averdon           #+#    #+#             */
/*   Updated: 2023/02/11 17:27:56 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_SO_LONG_H

# define PARSING_SO_LONG_H

# include "check_valid_path/check_valid_path.h"
# include "initialize_map/initialize_map.h"

t_double_list	*parsing(int argc, char **argv);
void			check_argument(int argc, char **argv);
void			check_valid_map(t_double_list **map);

#endif
