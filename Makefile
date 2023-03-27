# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:13:34 by nlocusso          #+#    #+#              #
#    Updated: 2023/03/17 15:22:59 by averdon          ###   ########.fr        #
#    Updated: 2023/01/10 15:15:05 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		:= mandatory/main.c \
			   mandatory/parsing/early_parsing.c \
			   mandatory/parsing/utils_pars.c \
			   mandatory/parsing/pars_texture.c \
			   mandatory/parsing/pars_map.c \
			   mandatory/parsing/pars_rgb.c \
			   mandatory/game/start_game.c \
			   mandatory/game/initialize_game.c \
			   mandatory/game/game_utils.c \
			   mandatory/game/key_functions.c \
			   mandatory/game/display.c \
			   mandatory/game/calculate_display.c \
			   mandatory/game/draw_display.c \
			   mandatory/game/parse_image.c \
			   mandatory/game/create_border.c

BSRCS		:= 	bonus/main_bonus.c \
				bonus/parsing/early_parsing_bonus.c \
				bonus/parsing/utils_pars_bonus.c \
				bonus/parsing/pars_texture_bonus.c \
				bonus/parsing/pars_map_bonus.c \
				bonus/parsing/pars_rgb_bonus.c \
				bonus/game/start_game_bonus.c \
				bonus/game/initialize_game_bonus.c \
				bonus/game/move_camera_bonus.c \
				bonus/game/song_bonus.c \
				bonus/game/key_functions/animations_bonus.c \
				bonus/game/key_functions/update_song_bonus.c \
				bonus/game/key_functions/launch_animations_and_movement_bonus.c \
				bonus/game/key_functions/player_movement_bonus.c \
				bonus/game/key_functions/player_actions_bonus.c \
				bonus/game/key_functions/utils_bonus.c \
				bonus/game/key_functions/interactions_bonus.c \
				bonus/game/display/display_bonus.c \
				bonus/game/display/door_recessed_bonus.c \
				bonus/game/display/calculate_display_bonus.c \
				bonus/game/display/draw_display_bonus.c \
				bonus/game/display/draw_image_bonus.c \
				bonus/game/display/parse_image_bonus.c \
				bonus/game/display/launch_parsing_image_bonus.c \
				bonus/game/display/parse_image_utils_bonus.c \
			   	bonus/game/display/inventory_bar_bonus.c \
			   	bonus/game/display/put_case_bar_bonus.c \
			   	bonus/game/display/minimap_bonus.c \
			   	bonus/game/display/put_minimap_textures_bonus.c \
				bonus/game/utils/calculation_bonus.c \
				bonus/game/utils/close_game_bonus.c \
				bonus/game/utils/suppress_nodes_bonus.c \
				bonus/so_long/main_so_long_bonus.c \
				bonus/so_long/parsing/check_valid_path/check_components_bonus.c \
				bonus/so_long/parsing/check_valid_path/check_valid_path_bonus.c \
				bonus/so_long/parsing/check_valid_path/fload_map_bonus.c \
				bonus/so_long/parsing/check_valid_path/set_up_copy_bonus.c \
				bonus/so_long/parsing/initialize_map/check_outline_bonus.c \
				bonus/so_long/parsing/initialize_map/initialize_map_bonus.c \
				bonus/so_long/parsing/check_argument_bonus.c \
				bonus/so_long/parsing/check_valid_map_bonus.c \
				bonus/so_long/parsing/parsing_bonus.c \
				bonus/so_long/game/display_map/check_walls_bonus.c \
				bonus/so_long/game/display_map/check_walls_2_bonus.c \
				bonus/so_long/game/display_map/display_good_walls_bonus.c \
				bonus/so_long/game/display_map/display_map_bonus.c \
				bonus/so_long/game/enemies/enemies_bonus.c \
				bonus/so_long/game/enemies/enemies_movements_bonus.c \
				bonus/so_long/game/enemies/enemies_utils_bonus.c \
				bonus/so_long/game/enemies/randomize_enemies_bonus.c \
				bonus/so_long/game/enemies/randomize_enemies_utils_bonus.c \
				bonus/so_long/game/keys/actions_key_bonus.c \
				bonus/so_long/game/keys/check_key_bonus.c \
				bonus/so_long/game/keys/key_utils_bonus.c \
				bonus/so_long/game/keys/keyhook_bonus.c \
				bonus/so_long/game/set_up_game/divise_map_bonus.c \
				bonus/so_long/game/set_up_game/set_up_sprite_bonus.c \
				bonus/so_long/game/set_up_game/set_up_var_bonus.c \
				bonus/so_long/game/game_utils_bonus.c \
				bonus/so_long/game/launch_animation_and_movement_bonus.c \
				bonus/so_long/game/calculate_utils_bonus.c \

OBJS		:= ${SRCS:.c=.o}

NAME		:= ./cub3D

BOBJS		:= ${BSRCS:.c=.o}

NAME_BONUS	:= ./cub3D_bonus

COMPILER	?= clang

RM			:= @rm -f

CFLAGS		:= -Wall -Wextra -Werror -g -Ilibraries

LIBRARY     := -Llibraries/libft -lft \
			   -Llibraries/libft/ft_fdprintf -lftfdprintf \
			   -Llibraries/minilibx -lmlx -lXext -lX11 -lm

all :        ${NAME}

.c.o :		${OBJS}
			@(${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} || (clear -x; printf "\033[0;31;1mcompilation failed\n\033[0m"; ${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} ; exit 1))
	
${NAME}:	${OBJS}
			@clear -x
			@printf "\033[93;1;5mCompiling ...\n\033[0m"
			@make -C libraries/libft
			@make -C libraries/minilibx
			@${COMPILER} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARY}
			@clear -x
			@printf '\033[0;92;1mCompilation finished\n\033[0m'

clear:
			@clear -x

compiling:
			@printf "\033[93;1;5mCompiling ...\n\033[0m"

cleaning:
			@printf "\033[93;1;5mCleaning ...\n\033[0m"

clean :		clear cleaning
			${RM} ${OBJS} ${BOBJS} 
			@make -C libraries/libft clean
			@make -C libraries/minilibx clean
			@clear -x
			@printf '\033[0;92;1mCleaning finished\n\033[0m'

fclean :	clear clean cleaning 
			${RM} ${NAME} ${NAME_BONUS}
			@clear -x
			@printf '\033[0;92;1mCleaning finished\n\033[0m'

re :		fclean all


${NAME_BONUS}:	${BOBJS}
			@clear -x
			@printf "\033[93;1;5mCompiling ...\n\033[0m"
			@make -C libraries/libft
			@make -C libraries/minilibx
			@${COMPILER} ${CFLAGS} -o ${NAME_BONUS} ${BOBJS} ${LIBRARY}
			@clear -x
			@printf '\033[0;92;1mCompilation finished\n\033[0m'

bonus: ${NAME_BONUS}

norm :
	@norminette libraries/libft
	@norminette ${SRCS} ${BSRCS}

.PHONY : all clean fclean re clear compiling cleaning bonus norm
