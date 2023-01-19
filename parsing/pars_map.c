/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:54:29 by nlocusso          #+#    #+#             */
/*   Updated: 2023/01/19 12:32:24 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pars_empty(t_data *data, int i, int j)
{
	int	error;

	error = 0;
	if (data->map[i][j + 1] == '\0' || data->map[i][j + 1] == ' ')
		error = 1;
	else if (j != 0 && data->map[i][j - 1] == ' ')
		error = 1;
	else if (i != 0 && data->map[i - 1][j] == ' ')
		error = 1;
	else if (data->map[i + 1] && data->map[i + 1][j] == ' ')
		error = 1;
	if (error == 1)
	{
		free_data(data);
		print_error("Error\nThe map is not closed\n");
	}
}

void	pars_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("NSEW01 ", data->map[i][j]) == NULL)
			{
				free_data(data);
				print_error("Error\nThe map can only be composed of '01' \
and can own only one character position (N, S, E, W)");
			}
			else if (data->map[i][j] == '0')
				pars_empty(data, i, j);
			else if (ft_strchr("NSEW", data->map[i][j]) != NULL)
			{
				if (data->orientation != 0)
				{
					free_data(data);
					print_error("Error\n\
There cannot be several positions of the character\n");
				}
				data->orientation = data->map[i][j];
			}
			j++;
		}
		i++;
	}
}
