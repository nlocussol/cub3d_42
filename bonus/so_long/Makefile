SRCS	?= main.c \
		   parsing/check_valid_path/check_components.c \
		   parsing/check_valid_path/check_valid_path.c \
		   parsing/check_valid_path/fload_map.c \
		   parsing/check_valid_path/set_up_copy.c \
		   parsing/initialize_map/check_outline.c \
		   parsing/initialize_map/initialize_map.c \
		   parsing/check_argument.c \
		   parsing/check_valid_map.c \
		   parsing/parsing.c \
		   game/display_map/check_walls.c \
		   game/display_map/check_walls_2.c \
		   game/display_map/display_good_walls.c \
		   game/display_map/display_map.c \
		   game/enemies/enemies.c \
		   game/enemies/enemies_movements.c \
		   game/enemies/enemies_utils.c \
		   game/enemies/randomize_enemies.c \
		   game/enemies/randomize_enemies_utils.c \
		   game/keys/actions_key.c \
		   game/keys/check_key.c \
		   game/keys/key_utils.c \
		   game/keys/keyhook.c \
		   game/set_up_game/divise_map.c \
		   game/set_up_game/set_up_sprite.c \
		   game/set_up_game/set_up_var.c \
		   game/game_utils.c \
		   game/launch_animation_and_movement.c \
		   sources/srcs_double_list/ft_double_lstadd_back.c \
		   sources/srcs_double_list/ft_double_lstadd_front.c \
		   sources/srcs_double_list/ft_double_lstclear.c \
		   sources/srcs_double_list/ft_double_lstdelone.c \
		   sources/srcs_double_list/ft_double_lstlast.c \
		   sources/srcs_double_list/ft_double_lstnew.c \
		   sources/srcs_double_list/ft_double_lstsize.c 

OBJS 	?= ${SRCS:.c=.o}

BOBJS 	?= ${BSRCS:.c=.o}

NAME 	?= so_long

COMPILER ?= clang

RM		?= rm -f

CFLAGS 	?= -Wall -Werror -Wextra -g

LIBRARY ?= sources/libft/libft.a \
		  sources/libft/ft_printf/libftprintf.a \
		  sources/minilibx/libmlx.a

.c.o:		${OBJS}
			${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: 		${NAME}

${NAME}:	${OBJS}
			make -C sources/libft
			make -C sources/minilibx
			${COMPILER} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBRARY} -lXext -lX11 

clean: 
			${RM} ${OBJS} ${BOBJS} 
			make -C sources/libft clean
			make -C sources/minilibx clean

fclean: 	clean
			${RM} ${NAME} ${BONUS}
			make -C sources/libft fclean

re:
			make fclean
			make

norm:
			norminette game parsing main.c so_long.h structures.h

.PHONY: 	all bonus clean fclean re norm
