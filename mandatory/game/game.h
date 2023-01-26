/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:03:49 by averdon           #+#    #+#             */
/*   Updated: 2023/01/26 16:35:17 by averdon          ###   ########.fr       */
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
	int		speed;
	char	direction;
}	t_player;

typedef struct s_raycast
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	dist_perp_wall;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	int		draw_start;
	int		draw_end;
	int		line_height;

}	t_raycast;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	char			**map;
	t_img			*screen_img;
	unsigned int	**images[4];
	char			*text_no;
	char			*text_so;
	char			*text_we;
	char			*text_ea;
	int				hex_f;
	int				hex_c;
	t_player		*player;
}	t_game;

# define WIDTH_SCREEN 1920
# define HEIGHT_SCREEN 1080
# define TITLE "Game"

# define ECHAP 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

# define SIZE_BLOCK 64
# define COEFF 10

void	start_game(t_data *data);
void	initialize_game(t_game	*game, t_data *data);
void	parse_image(t_game *game);
void	create_border(t_game *game);

void	destroy_images(t_game *game);
void	free_all(t_game *game);
int		close_window(t_game *game);
double	abs_value(double nb);
double	radian_value(double degree);

int		key_hook(int keycode, t_game *game);
void	move_player(t_game	*game, int move);
void	turn_camera(t_game	*game, int move);

void	display_screen(t_game *game);
void	draw_line(t_game *game, int x, t_raycast *raycast);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	calculate_delta_and_dist(int x, t_raycast *raycast);
void	calculate_dist_perp_wall(t_raycast *raycast);

#endif
