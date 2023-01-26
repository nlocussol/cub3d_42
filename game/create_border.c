/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_border.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:58:50 by averdon           #+#    #+#             */
/*   Updated: 2023/01/26 13:04:15 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		length_max_in_tab(char **tab)
{
	int	i;
	int	length;

	length = 0;
	i = 0;
	while (tab[i])
	{
		if ((int)ft_strlen(tab[i]) > length)
			length = ft_strlen(tab[i]);
		i++;
	}
	return (length);
}

void	create_border(t_game *game)
{
	int		i;
	int		j;
	int		length;
	char	**new_map;

	new_map = ft_calloc(3 + ft_len_tab(game->map), sizeof(char *));
	if (!new_map)
		return ;
	length = length_max_in_tab(game->map);
	new_map[0] = ft_calloc(3 + length, sizeof(char));
	if (!new_map[0])
	{
		ft_free_array(new_map);
		return ;
	}
	j = 0;
	while (j < length + 2)
	{
		new_map[0][j] = '2';
		j++;
	}
	i = 1;
	while (i < ft_len_tab(game->map) + 1)
	{
		new_map[i] = ft_calloc(3 + length, sizeof(char));
		if (!new_map[i])
		{
			ft_free_array(new_map);
			return ;
		}
		new_map[i][0] = '2';
		j = 0;
		while (game->map[i - 1][j])
		{
			new_map[i][j + 1] = game->map[i - 1][j];
			j++;
		}
		while (j < length)
		{
			new_map[i][j + 1] = ' ';
			j++;
		}
		new_map[i][j + 1] = '2';
		i++;
	}
	new_map[i] = ft_calloc(3 + length, sizeof(char));
	if (!new_map[i])
	{
		ft_free_array(new_map);
		return ;
	}
	j = 0;
	while (j < length + 2)
	{
		new_map[i][j] = '2';
		j++;
	}
	free_tab(game->map);
	game->map = new_map;
}
