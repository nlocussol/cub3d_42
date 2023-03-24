/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:20:37 by nlocusso          #+#    #+#             */
/*   Updated: 2023/03/18 12:56:22 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "../cub3d_bonus.h"

typedef struct s_data
{
	char	**map;
	char	*text_no;
	char	*text_so;
	char	*text_we;
	char	*text_ea;
	char	*text_door;
	char	**text_f;
	int		hex_f;
	char	**text_c;
	int		hex_c;
	char	orientation;
}	t_data;

bool	pars_line(char *str);
void	check_rgb_value(t_data *data);
void	pars_rgb_color(t_data *data);
void	print_error(char *message);
void	check_data(t_data *data);
void	pars_map(t_data *data);
void	open_texture(t_data *data, char *texture);
void	free_data(t_data *data);
void	find_texture(t_data *data);
void	init_data(t_data *data);
int		ft_count(char *str, char c);
int		early_parsing(int argc, char **argv, t_data *data);
int		check_all_data(t_data *data);

#endif
