/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:03:49 by averdon           #+#    #+#             */
/*   Updated: 2023/01/24 16:03:20 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "../cub3d.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_player
{
	double	x;
	double	y;
	int		orientation;
	char	direction;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	t_img		*screen_img;
	unsigned int **images[4];
	t_player	*player;
	t_data		*data;
}	t_game;

# define WIDTH_SCREEN 1920
# define HEIGHT_SCREEN 1080
# define TITLE "Game"

# define ECHAP 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define FOV 100

# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

# define SIZE_BLOCK 64
# define COEFF 10

void	start_game(t_data *data);
void	move_player(t_game	*game, int move);
void	turn_camera(t_game	*game, int move);
void	reload_display(t_game *game);
double	abs_value(double nb);
double	radian_value(double degree);
void	parse_image(t_game *game);

#endif
