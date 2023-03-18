/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:14:19 by nlocusso          #+#    #+#             */
/*   Updated: 2023/03/18 12:56:24 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_all_data(t_data *data)
{
	if (data->text_no && data->text_so && data->text_we && data->text_ea
		&& data->text_f && data->text_c && data->text_door)
		return (1);
	return (0);
}

void	print_error(char *message)
{
	ft_fdprintf(2, "%s", message);
	exit(EXIT_FAILURE);
}

void	open_texture(t_data *data, char *texture)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd < 0 || check_extension(texture, ".xpm") == 1)
	{
		free(texture);
		free_data(data);
		print_error("Error\nBad texture path or extension (only .xpm)\n");
	}
	close(fd);
}

void	free_data(t_data *data)
{
	ft_free_array(data->map);
	ft_free_array(data->text_f);
	ft_free_array(data->text_c);
	free(data->text_no);
	free(data->text_so);
	free(data->text_we);
	free(data->text_ea);
	free(data->text_door);
}

void	init_data(t_data *data)
{
	data->map = NULL;
	data->text_f = NULL;
	data->text_c = NULL;
	data->text_no = NULL;
	data->text_so = NULL;
	data->text_we = NULL;
	data->text_ea = NULL;
	data->text_door = NULL;
	data->orientation = 0;
}
