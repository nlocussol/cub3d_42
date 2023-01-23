/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:22:15 by averdon           #+#    #+#             */
/*   Updated: 2023/01/23 19:42:30 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_image(t_game *game)
{
	void	*img;
	char	*img_data;
	int		i;

	img = mlx_xpm_file_to_image(game->mlx, "textures/S.xpm", &i, &i);
	img_data = mlx_get_data_addr(img, &i, &i, &i);
	i = -1;
	while (img_data[++i])
		printf("%d\n", img_data[i]);
}
