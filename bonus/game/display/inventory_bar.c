#include "../../cub3d.h"

void	put_one_case(t_game *game, int x_tmp, int y_tmp, int color)
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

void	put_big_case(t_game *game, int x_tmp, int y_tmp, int color)
{
	int	x;
	int	y;
	
	x = x_tmp;
	while (x < x_tmp + 136)
	{
		y = y_tmp;
		while (y < y_tmp + 134)
		{
			if ((x >= x_tmp && x < x_tmp + 5) || (y >= y_tmp && y < y_tmp + 5)
					|| (y > y_tmp + 127 && y < y_tmp + 134) || (x > x_tmp + 131 && x < x_tmp + 136))
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

	x = 834;
	y = 448;
	i = 0;
	while (i != 7)
	{
		nb = ft_itoa(i + 1);
		mlx_string_put(game->mlx, game->window, y + 20, x + 110, 0xB39797, nb);
		free(nb);
		y += 128;
		i++;
	}
}

void	put_map_icone(t_game *game, int x, int y, unsigned int **color)
{
	int	x_img;
	int	y_img;

	x_img = 0;
	while (x_img != 100)
	{
		y_img = 0;
		while (y_img != 100)
		{
			if (color[x_img][y_img] != 0xff000000)
				my_mlx_pixel_put(game->screen_img, y_img + y, x_img + x, color[x_img][y_img]);
			y_img++;
		}
		x_img++;
	}
}

void	put_arm(t_game *game, int x, int y, unsigned int **color)
{
	int	x_img;
	int	y_img;

	x_img = 0;
	while (x_img != 314)
	{
		y_img = 0;
		while (y_img != 350)
		{
			if (color[x_img][y_img] != 0xff000000)
				my_mlx_pixel_put(game->screen_img, y_img + y, x_img + x, color[x_img][y_img]);
			y_img++;
		}
		x_img++;
	}
}

void	game_bar(t_game *game)
{
	int			x;
	int			y;
	int			i;
	static int	anim = 0;

	anim++;
	i = 0;
	x = 834;
	y = 448;
	while (y < 1344)
	{
		put_one_case(game, x, y ,0xB39797);
		if (i + 1 == game->bar_index)
			put_big_case(game, x - 5, y - 5, 0xDFDFDF);
		if (i == 3)
			put_map_icone(game, x + 10, y + 15, game->bar_img[2]);
		if (i == 0 && anim <= 50)
			put_map_icone(game, x + 10, y + 15, game->bar_img[0]);
		else if (i == 0 && anim > 50)
		{
			if (anim == 100)
				anim = 0;
			put_map_icone(game, x + 10, y + 15, game->bar_img[1]);
		}
		if (i == 1)
			put_map_icone(game, x + 10, y + 15, game->bar_img[3]);
		if (i == 2)
			put_map_icone(game, x + 10, y + 15, game->bar_img[4]);
		if (i == 4)
			put_map_icone(game, x + 10, y + 15, game->bar_img[5]);
		y += 128;
		i++;
	}
	put_arm(game, 766, 1570, game->arm_img[0]);
}
