/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:14:19 by nlocusso          #+#    #+#             */
/*   Updated: 2023/03/16 16:17:35 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_count(char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
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
	data->orientation = 0;
}
