#include "../../cub3d.h"

void	put_64_block(t_game *game, int x_tmp, int y_tmp, int color)
{
	int	x;
	int	y;
	
	x = x_tmp;
	while (x < x_tmp + 128)
	{
		y = y_tmp;
		while (y < y_tmp + 128)
		{
			if ((x >= x_tmp && x < x_tmp + 5) || (y >= y_tmp && y < y_tmp + 5)
					|| (y > y_tmp + 123 && y < y_tmp + 128) || (x > x_tmp + 123 && x < x_tmp + 128))
				my_mlx_pixel_put(game->screen_img, y, x, color);
			y++;
		}
		x++;
	}
}

void	nb_game_bar(t_game *game)
{
	int		i;
	int		x;
	int		y;
	char	*nb;

	x = 864;
	y = 448;
	i = 0;
	while (i != 8)
	{
		nb = ft_itoa(i + 1);
		mlx_string_put(game->mlx, game->window, y + 20, x + 110, 0xB39797, nb);
		free(nb);
		y += 128;
		i++;
	}
}

void	game_bar(t_game *game)
{
	int		x;
	int		y;

	x = 864;
	y = 448;
	while (y < 1472)
	{
		put_64_block(game, x, y ,0xB39797);
		y += 128;
	}
}
