/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:20:37 by nlocusso          #+#    #+#             */
/*   Updated: 2023/01/19 09:41:45 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

typedef struct s_data
{
	char	**map;
	//direction start
	//faces of wall
}	t_data;

int		early_parsing(int argc, char **argv, t_data *data);

#endif
