/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:22:35 by averdon           #+#    #+#             */
/*   Updated: 2023/02/20 13:37:08 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_argument(int argc, char **argv)
{
	if (argc < 2)
	{
		exit (0);
	}
	if (argc > 2)
	{
		exit (0);
	}
	if (ft_strlen(argv[1]) == 4 || argv[1][ft_strlen(argv[1]) - 5] == '/'
		|| ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
	{
		exit (0);
	}
}
