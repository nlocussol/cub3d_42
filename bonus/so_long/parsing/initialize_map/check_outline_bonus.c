/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outline_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:00:16 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:53:10 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	check_last_line(t_double_list **map)
{
	t_double_list	*buffer;
	char			*str;
	int				i;

	i = 0;
	buffer = *map;
	while (buffer)
	{
		str = (char *)buffer->content;
		buffer = buffer->next;
	}
	while (str[i])
	{
		if (str[i] != '1')
		{
			ft_double_lstclear(map, del);
			exit (0);
		}
		i++;
	}
}

void	check_first_line(t_double_list **map)
{
	t_double_list	*buffer;
	char			*str;
	int				i;

	buffer = *map;
	str = (char *)buffer->content;
	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
		{
			ft_double_lstclear(map, del);
			exit (0);
		}
		i++;
	}
}

void	check_borders(t_double_list **map)
{
	t_double_list	*buffer;
	int				len_line;

	buffer = *map;
	while (buffer)
	{
		len_line = ft_strlen((char *)buffer->content);
		if (((char *)(buffer->content))[0] != '1'
				|| ((char *)(buffer->content))[len_line - 1] != '1')
		{
			ft_double_lstclear(map, del);
			exit (0);
		}
		buffer = buffer->next;
	}
}
