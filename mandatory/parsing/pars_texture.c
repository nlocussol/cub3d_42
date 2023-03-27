/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:51:42 by nlocusso          #+#    #+#             */
/*   Updated: 2023/03/16 16:11:47 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

void	pars_texture(t_data *data)
{
	char	*tmp;

	tmp = ft_strtrim(data->text_no, " \t");
	open_texture(data, tmp);
	free(data->text_no);
	data->text_no = tmp;
	tmp = ft_strtrim(data->text_so, " \t");
	open_texture(data, tmp);
	free(data->text_so);
	data->text_so = tmp;
	tmp = ft_strtrim(data->text_we, " \t");
	open_texture(data, tmp);
	free(data->text_we);
	data->text_we = tmp;
	tmp = ft_strtrim(data->text_ea, " \t");
	open_texture(data, tmp);
	free(data->text_ea);
	data->text_ea = tmp;
	pars_rgb_color(data);
}

int	check_all_data(t_data *data)
{
	if (data->text_no && data->text_so && data->text_we && data->text_ea
		&& data->text_f && data->text_c)
		return (1);
	return (0);
}

void	check_texture(t_data *data, char *line)
{
	if ((ft_strncmp(line, "NO ", 3) == 0
			|| ft_strncmp(line, "NO\t", 3) == 0) && !data->text_no)
		data->text_no = ft_strdup(&line[3]);
	else if ((ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "SO\t", 3) == 0) && !data->text_so)
		data->text_so = ft_strdup(&line[3]);
	else if ((ft_strncmp(line, "WE ", 3) == 0
			|| ft_strncmp(line, "WE\t", 3) == 0) && !data->text_we)
		data->text_we = ft_strdup(&line[3]);
	else if ((ft_strncmp(line, "EA ", 3) == 0
			|| ft_strncmp(line, "EA\t", 3) == 0) && !data->text_ea)
		data->text_ea = ft_strdup(&line[3]);
	else if ((ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "F\t", 2) == 0)
		&& !data->text_f && ft_count(line, ',') == 2)
		data->text_f = ft_split(&line[2], ',');
	else if ((!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C\t", 2))
		&& !data->text_c && ft_count(line, ',') == 2)
		data->text_c = ft_split(&line[2], ',');
	else
	{
		free(line);
		free_data(data);
		print_error("Error\nBad data, you can only put: NO, SO, WE, EA, F, C\n");
	}
}

int	fill_data(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->map[i])
	{
		tmp = ft_strtrim(data->map[i], " \t");
		if (tmp && tmp[0])
			check_texture(data, tmp);
		free(tmp);
		i++;
		if (check_all_data(data) == 1)
			break ;
	}
	if (check_all_data(data) == 0)
	{
		free_data(data);
		print_error("Error\nThe map does not have all the data\n");
	}
	return (i);
}

void	find_texture(t_data *data)
{
	char	**new_map;
	int		i;

	new_map = NULL;
	i = fill_data(data);
	pars_texture(data);
	while (!ft_strchr(data->map[i], '1') && !ft_strchr(data->map[i], '0'))
	{
		if (pars_line(data->map[i]) == false)
		{
			free_data(data);
			print_error("Error\nThe map contains bad data!\n");
		}
		i++;
	}
	while (data->map[i])
	{
		new_map = append_to_tab(new_map, data->map[i]);
		i++;
	}
	ft_free_array(data->map);
	data->map = new_map;
	pars_map(data);
	check_data(data);
}
