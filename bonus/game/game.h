/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:03:49 by averdon           #+#    #+#             */
/*   Updated: 2023/02/11 17:54:43 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "../cub3d.h"

typedef struct s_img
{
	void			*img;
	int				height;
	int				width;
	unsigned char	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_img;

typedef struct s_player
{
	double	x;
	double	y;
	int		orientation;
	int		speed;
	char	direction;
}	t_player;

typedef struct s_anim
{
	int		x;
	int		y;
	long	time_anim_start;
}	t_anim;

typedef struct s_graff
{
	int		x;
	int		y;
	int		frame;
	long	last_frame_changed;
	char	direction;
}	t_graff;

typedef struct s_song
{
	FILE	*stream;
	long	start_time;
	int		type;
}	t_song;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	char			**map;
	t_img			*screen_img;
	long			time_start;
	int				mouse_height;
	int				bar_index;
	bool			started_gameboy;

	unsigned int	**images[11];
	unsigned int	**minimap_img[4];
	unsigned int	**bar_img[6];
	char			*text_no;
	char			*text_so;
	char			*text_we;
	char			*text_ea;
	char			*text_do;
	int				hex_f;
	int				hex_c;

	int				x_minimap;
	int				y_minimap;
	int				minimap;

	t_player		*player;
	int				movements[4];
	int				nb_graff;

	t_double_list	*lst_anim;
	t_double_list	*lst_graff;
	t_double_list	*lst_sound;
	t_vars			*vars;
}	t_game;

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

# define WIDTH_SCREEN 1920
# define HEIGHT_SCREEN 1080
# define TITLE "Game"

# define TAB 65289
# define ECHAP 65307
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define W 119
# define A 97
# define S 115
# define D 100
# define E 101
# define G 103
# define H 104
# define Z 122

# define SPRAY 1
# define DOOR 2

# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

# define SIZE_BLOCK 64
# define CAMERA_SPEED_REVERSE 25
# define HIT_BOX_WALL 10

int		mouse_hook(int mouse, int x, int y, t_game *game);
void	start_game(t_data *data);
void	initialize_game(t_game	*game, t_data *data);
void	parse_image(t_game *game);
void	create_border(t_game *game);
long	calculate_time(void);

void	destroy_images(t_game *game);
void	free_all(t_game *game);
int		close_window(t_game *game);
double	abs_value(double nb);
double	radian_value(double degree);

int		launch_movements(t_game *game);
int		key_pressed(int keycode, t_game *game);
int		key_released(int keycode, t_game *game);
int		key_hook(int keycode, t_game *game);
void	move_player(t_game	*game, int move);
void	turn_camera(t_game	*game, int move);
int		move_camera(void *arg);
void	interact(t_game *game, int keycode);

t_anim	*find_square(t_game *game, int x, int y);
t_graff	*find_square_2(t_game *game, t_raycast *raycast);
void	suppress_node(t_game *game, int x, int y);
void	suppress_node_3(t_game *game, t_double_list *buffer);

void	launch_song(t_game *game, int mode);
#endif
