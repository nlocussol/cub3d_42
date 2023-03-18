/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:25:28 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:52:11 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_double_list	*parsing(int argc, char **argv)
{
	t_double_list	*map;

	check_argument(argc, argv);
	map = initialize_map(argv[1]);
	check_valid_map(&map);
	check_valid_path(&map);
	return (map);
}
