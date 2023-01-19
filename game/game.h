/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:03:49 by averdon           #+#    #+#             */
/*   Updated: 2023/01/19 10:41:32 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "../cub3d.h"

typedef struct s_player
{
	int		x;
	int		y;
	char	orientation;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	t_player	*player;
}	t_game;

# define WIDTH_SCREEN 1920
# define LENGTH_SCREEN 1080
# define TITLE "Game"

# define ECHAP 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define DOWN_ARROW 65364
# define RIGHT_ARROW 65363

# define SIZE_BLOCK 64

void	start_game(t_data *data);

#endif
