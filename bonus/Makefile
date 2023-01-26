# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:13:34 by nlocusso          #+#    #+#              #
#    Updated: 2023/01/26 17:22:33 by averdon          ###   ########.fr        #
#    Updated: 2023/01/10 15:15:05 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		?= main.c \
			   parsing/early_parsing.c \
			   parsing/utils_pars.c \
			   parsing/pars_texture.c \
			   parsing/pars_map.c \
			   parsing/pars_rgb.c \
			   game/start_game.c \
			   game/initialize_game.c \
			   game/game_utils.c \
			   game/key_functions.c \
			   game/display.c \
			   game/calculate_display.c \
			   game/draw_display.c \
			   game/parse_image.c \

OBJS		?= ${SRCS:.c=.o}

NAME		?= ./cub3D

COMPILER	?= clang

RM			?= @rm -f

CFLAGS		?= -Wall -Wextra -Werror -g 

LIBRARY     ?= -Lsources/libft -lft \
			   -Lsources/libft/ft_fdprintf -lftfdprintf \
			   -Lsources/minilibx -lmlx -lXext -lX11 -lm

all :        ${NAME}

.c.o :		${OBJS}
			@(${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} || (clear -x; printf "\033[0;31;1mcompilation failed\n\033[0m"; ${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} ; exit 1))
	
${NAME}:	${OBJS}
			@clear -x
			@printf "\033[93;1;5mCompiling ...\n\033[0m"
			@make -C sources/libft
			@make -C sources/minilibx
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
			${RM} ${OBJS} 
			@make -C sources/libft clean
			@make -C sources/minilibx clean
			@clear -x
			@printf '\033[0;92;1mCleaning finished\n\033[0m'

fclean :	clear clean cleaning 
			${RM} ${NAME} 
			@make -C sources/libft fclean
			@clear -x
			@printf '\033[0;92;1mCleaning finished\n\033[0m'

re :		fclean all

norm :
	@norminette sources/libft
	@norminette ${SRCS}

.PHONY : all clean fclean re clear compiling cleaning
