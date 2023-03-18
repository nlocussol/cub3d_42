/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:54:29 by nlocusso          #+#    #+#             */
/*   Updated: 2023/03/18 12:56:25 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	check_data(t_data *data)
{
	if (data->orientation == 0)
	{
		free_data(data);
		print_error("Error\nA player position is missing\n");
	}
}

void	pars_door(t_data *data, int i, int j)
{
	if (data->map[i][j - 1] == '1' && data->map[i][j + 1] == '1'
		&& data->map[i - 1][j] != 'D' && data->map[i + 1][j] != 'D')
		return ;
	else if (data->map[i - 1][j] == '1' && data->map[i + 1][j] == '1'
		&& data->map[i][j + 1] != 'D' && data->map[i][j - 1] != 'D')
		return ;
	else
	{
		free_data(data);
		print_error("Error\nThe door is not between 2 walls\n");
	}
}

void	pars_empty(t_data *data, int i, int j)
{
	int	error;

	error = 0;
	if (j == 0 || i == 0 || !data->map[i][j + 1]
		|| !data->map[i + 1] || !data->map[i - 1][j] || !data->map[i][j - 1])
		error = 1;
	else if (data->map[i][j + 1] == ' ' || data->map[i][j - 1] == ' '
		|| data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' ')
		error = 1;
	if (error == 1)
	{
		free_data(data);
		print_error("Error\nThe map is not closed\n");
	}
	if (data->map[i][j] == 'D')
		pars_door(data, i, j);
}

void	map_error(t_data *data, int i, int j)
{
	if (ft_strchr("NSEW01D ", data->map[i][j]) == NULL)
	{
		free_data(data);
		print_error("Error\nThe map can only be composed of '01' \
and can own only one character position (N, S, E, W)");
	}
	else if (data->map[i][j] == '0' || data->map[i][j] == 'D'
		|| ft_strchr("NSEW", data->map[i][j]))
		pars_empty(data, i, j);
	if (ft_strchr("NSEW", data->map[i][j]) != NULL)
	{
		if (data->orientation != 0
			|| !ft_strchr("01D", data->map[i - 1][j])
			|| !ft_strchr("01D", data->map[i + 1][j])
			|| !ft_strchr("01D", data->map[i][j - 1])
			|| !ft_strchr("01D", data->map[i][j + 1]))
		{
			free_data(data);
			print_error("Error\n\
Multilple or bad position of the player !\n");
		}
		data->orientation = data->map[i][j];
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
			map_error(data, i, j);
			j++;
		}
		i++;
	}
}
