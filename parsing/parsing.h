/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:20:37 by nlocusso          #+#    #+#             */
/*   Updated: 2023/01/19 16:37:56 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

typedef struct s_data
{
	char	**map;
	char	*text_no;
	char	*text_so;
	char	*text_we;
	char	*text_ea;
	char	**text_f;
	char	**text_c;
	char	orientation;
}	t_data;

void	check_data(t_data *data);
void	pars_map(t_data *data);
void	open_texture(t_data *data, char *texture);
void	free_data(t_data *data);
void	find_texture(t_data *data);
void	init_data(t_data *data);
int		early_parsing(int argc, char **argv, t_data *data);

#endif
