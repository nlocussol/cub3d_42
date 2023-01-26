/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   early_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:05 by averdon           #+#    #+#             */
/*   Updated: 2023/01/26 13:13:26 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	early_parsing(int argc, char **argv, t_data *data)
{
	char	*str;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Error\nThe file cannot be opened\n");
	str = get_next_line(fd);
	if (!str)
		print_error("Error\nThe file is empty\n");
	while (str)
	{
		data->map = append_to_tab(data->map, str);
		free(str);
		if (!data->map)
			return (1);
		str = get_next_line(fd);
	}
	put_eol(data);
	find_texture(data);
	return (0);
}
