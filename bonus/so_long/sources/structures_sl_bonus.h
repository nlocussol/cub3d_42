/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_sl_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:46:33 by averdon           #+#    #+#             */
/*   Updated: 2023/03/18 12:51:23 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_SL_BONUS_H

# define STRUCTURES_SL_BONUS_H

typedef struct s_components
{
	int	start;
	int	exit;
	int	collectibles;
}	t_components;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player_so_long {
	void	**sprite;
	int		x;
	int		y;
	t_point	*old_point;
	int		nb_collectibles;
	int		nb_move;
	int		frame;
	int		side;
}				t_player_so_long;

typedef struct s_tilemap {
	int				x;
	int				y;
	t_double_list	*map;
}	t_tilemap;

typedef struct s_vars {
	void				*mlx;
	void				*window;
	t_player_so_long	*player;
	t_double_list		*map;
	t_double_list		*map_chunk;
	t_double_list		*positions_enemies;
	void				**array_ptr_sprite;
	int					nb_columns;
	int					nb_rows;
	int					nb_collectibles;
	int					frame_enemy;
	int					game_finish;
	int					argc;
	char				**argv;
}	t_vars;

#endif
