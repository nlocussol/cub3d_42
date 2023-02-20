/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:03:15 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/14 12:42:22 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **tab) {
	for (int j = 0; tab[j]; j++) {
		for (int i = 0; tab[j][i]; i++)
			printf("%c", tab[j][i]);
		printf("\n");
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init_data(&data);
	if (argc != 2 || check_extension(argv[1], ".cub") == 1)
		print_error("Error\nUsage: ./cub3D <map.cub>\n");
	if (early_parsing(argc, argv, &data) != 1)
	{
		print_map(data.map);
		start_game(&data, env);
		return (0);
	}
	else
		return (1);
}
