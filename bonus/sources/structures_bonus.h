/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:36:16 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:46:46 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H

# define STRUCTURES_BONUS_H

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
	long	time_start;
	char	direction;
}	t_graff;

typedef struct s_song
{
	int			pid;
	long		start_time;
	int			type;
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
	unsigned int	**images[12];
	unsigned int	**minimap_img[5];
	unsigned int	**bar_img[8];
	unsigned int	**arm_img[6];
	unsigned int	**anim_gameboy[11];
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
	char			**env;
}	t_game;

typedef struct s_raycast
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
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
	int		draw_start;
	int		draw_end;
	int		line_height;
}	t_raycast;

#endif
