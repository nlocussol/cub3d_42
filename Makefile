# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:13:34 by nlocusso          #+#    #+#              #
#    Updated: 2023/01/18 21:01:50 by averdon          ###   ########.fr        #
#    Updated: 2023/01/10 15:15:05 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		?= main.c \
			   early_parsing.c \
			   game/start_game.c

OBJS		?= ${SRCS:.c=.o}

NAME		?= ./cub3D

COMPILER	?= clang

RM			?= @rm -f

CFLAGS		?= -Wall -Wextra -Werror -g 

LIBRARY     ?= -Lsources/libft -lft \
			   -Lsources/libft/ft_fdprintf -lftfdprintf \
			   -lreadline \
			   -Lsources/minilibx -lmlx -lXext -lX11

all :        ${NAME}

.c.o :		${OBJS}
			@(${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} || (clear; printf "\033[0;31;1mcompilation failed\n\033[0m"; ${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} ; exit 1))
	
${NAME}:	${OBJS}
			@clear
			@printf "\033[93;1;5mCompiling ...\n\033[0m"
			@make -C sources/libft
			@make -C sources/minilibx
			@${COMPILER} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARY}
			@clear
			@printf '\033[0;92;1mCompilation finished\n\033[0m'

clear:
			@clear

compiling:
			@printf "\033[93;1;5mCompiling ...\n\033[0m"

cleaning:
			@printf "\033[93;1;5mCleaning ...\n\033[0m"

clean :		clear cleaning
			${RM} ${OBJS} 
			@make -C sources/libft clean
			@make -C sources/minilibx clean
			@clear
			@printf '\033[0;92;1mCleaning finished\n\033[0m'

fclean :	clear clean cleaning 
			${RM} ${NAME} 
			@make -C sources/libft fclean
			@clear
			@printf '\033[0;92;1mCleaning finished\n\033[0m'

re :		fclean all

.PHONY : all clean fclean re clear compiling cleaning
