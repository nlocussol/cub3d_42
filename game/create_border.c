/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_border.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:58:50 by averdon           #+#    #+#             */
/*   Updated: 2023/01/26 13:12:39 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	length_max_in_tab(char **tab)
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

void	add_line(char **new_map, int index, int length)
{
	int		j;

	new_map[index] = ft_calloc(3 + length, sizeof(char));
	if (!new_map[index])
	{
		ft_free_array(new_map);
		return ;
	}
	j = 0;
	while (j < length + 2)
	{
		new_map[index][j] = '2';
		j++;
	}
}

void	create_new_tab(t_game *game, char **new_map, int length)
{
	int		i;
	int		j;

	add_line(new_map, 0, length);
	i = 0;
	while (++i < ft_len_tab(game->map) + 1)
	{
		new_map[i] = ft_calloc(3 + length, sizeof(char));
		if (!new_map[i])
		{
			ft_free_array(new_map);
			return ;
		}
		new_map[i][0] = '2';
		j = -1;
		while (game->map[i - 1][++j])
			new_map[i][j + 1] = game->map[i - 1][j];
		while (j < length)
		{
			new_map[i][j + 1] = ' ';
			j++;
		}
		new_map[i][j + 1] = '2';
	}
	add_line(new_map, i, length);
}

void	create_border(t_game *game)
{
	int		length;
	char	**new_map;

	new_map = ft_calloc(3 + ft_len_tab(game->map), sizeof(char *));
	if (!new_map)
		return ;
	length = length_max_in_tab(game->map);
	create_new_tab(game, new_map, length);
	free_tab(game->map);
	game->map = new_map;
}
