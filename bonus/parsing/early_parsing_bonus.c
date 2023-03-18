/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   early_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:05 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:56:26 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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

void	put_eol(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		data->map[i][ft_strlen(data->map[i]) - 1] = '\0';
		i++;
	}
}

char	*check_infile(int fd)
{
	char	*str;

	if (fd < 0)
	{
		close(fd);
		print_error("Error\nThe file cannot be opened\n");
	}
	str = get_next_line(fd);
	if (!str)
	{
		close(fd);
		print_error("Error\nThe file is empty\n");
	}
	return (str);
}

int	early_parsing(int argc, char **argv, t_data *data)
{
	char	*str;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	str = check_infile(fd);
	while (str)
	{
		data->map = append_to_tab(data->map, str);
		free(str);
		if (!data->map)
		{
			close(fd);
			return (1);
		}
		str = get_next_line(fd);
	}
	close(fd);
	put_eol(data);
	find_texture(data);
	return (0);
}
