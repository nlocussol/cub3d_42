/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:55:20 by nlocusso          #+#    #+#             */
/*   Updated: 2023/01/19 09:32:18 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "sources/includes.h"

typedef struct s_data
{
	char	**map;
	//direction start
	//faces of wall
}	t_data;

char	**early_parsing(int argc, char **argv);
void	print_tab(char **map);
void	print_error(char *message);

#endif
