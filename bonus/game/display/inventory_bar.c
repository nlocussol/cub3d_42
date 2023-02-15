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
				|| (y > y_tmp + 123 && y < y_tmp + 128)
				|| (x > x_tmp + 123 && x < x_tmp + 128))
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
				|| (y > y_tmp + 127 && y < y_tmp + 134)
				|| (x > x_tmp + 131 && x < x_tmp + 136))
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
		put_one_case(game, x, y, 0xB39797);
		if (i + 1 == game->bar_index)
			put_big_case(game, x - 5, y - 5, 0xDFDFDF);
		if (i == 3)
			draw_image(game, game->bar_img[2], y + 15, x + 10);
		if (i == 0 && anim <= 50)
			draw_image(game, game->bar_img[0], y + 15, x + 10);
		else if (i == 0 && anim > 50)
		{
			if (anim == 100)
				anim = 0;
			draw_image(game, game->bar_img[1], y + 15, x + 10);
		}
		if (i == 1)
			draw_image(game, game->bar_img[3], y + 15, x + 10);
		if (i == 2)
			draw_image(game, game->bar_img[4], y + 15, x + 10);
		if (i == 4)
			draw_image(game, game->bar_img[5], y + 15, x + 10);
		y += 128;
		i++;
	}
	if (game->bar_index < 6 && game->bar_index > 1)
		draw_image(game, game->arm_img[game->bar_index - 1], 1570, 766);
	else
		draw_image(game, game->arm_img[0], 1570, 766);
}
