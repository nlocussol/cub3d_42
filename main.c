/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:03:15 by nlocusso          #+#    #+#             */
/*   Updated: 2023/01/19 09:17:22 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *message)
{
	ft_fdprintf(2, "%s", message);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2 || check_extension(argv[1], ".cub") == 1)
		print_error("Error\nUsage: ./cub3D <map.cub>\n");
	map = early_parsing(argc, argv);
	//if (map)
	//	start_game(map);
	//else
	//	return (1);
	return (0);
}
