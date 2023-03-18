/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:23:04 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:52:43 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	add_to_list(char *str, t_double_list **map)
{
	t_double_list	*new_elt;

	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
	new_elt = ft_double_lstnew(str);
	if (!str || !new_elt)
	{
		free(str);
		ft_double_lstclear(map, del);
		exit (0);
	}
	ft_double_lstadd_back(map, new_elt);
}

void	check_len_line(int len_line, int len_first_line, t_double_list **map)
{
	if (len_line != len_first_line)
	{
		ft_double_lstclear(map, del);
		exit (0);
	}
}

void	create_and_check_map(int fd, t_double_list **map)
{
	char			*str;
	int				len_first_line;
	int				len_line;

	str = get_next_line(fd);
	if (!str)
	{
		exit (0);
	}
	len_first_line = ft_strlen(str) - 1;
	while (str)
	{
		add_to_list(str, map);
		len_line = ft_strlen(str);
		check_len_line(len_line, len_first_line, map);
		str = get_next_line(fd);
	}
	check_borders(map);
	check_first_line(map);
	check_last_line(map);
	close(fd);
}

t_double_list	*initialize_map(char *file)
{
	int				fd;
	t_double_list	*map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		exit(0);
	}
	map = NULL;
	create_and_check_map(fd, &map);
	return (map);
}
