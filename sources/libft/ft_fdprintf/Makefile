SRCS	= ft_fdprintf.c \
		  ft_putnbr_base.c \
		  ft_iterative_power.c \
		  ../ft_putchar_fd.c \
		  ../ft_putstr_fd.c \
		  ../ft_strchr.c \
		  ../ft_strlen.c

OBJS 	= ${SRCS:.c=.o}

NAME 	= libftfdprintf.a

COMPILER= clang

RM		= @rm -f

CFLAGS 	= -Wall -Werror -Wextra -g

all: 		${NAME}

.c.o:		${OBJS}
			@(${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} || (clear; printf "\033[0;31;1mcompilation failed\n\033[0m"; ${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} ; exit 1))
	
${NAME}:	clear compiling ${OBJS}
			@ar rcs ${NAME} ${OBJS}
			@clear
			@printf '\033[0;92;1mcompilation finished\n\033[0m'

clear:
			@clear

compiling:
			@printf "\033[93;1;5mcompiling ...\n\033[0m"

cleaning:
			@printf "\033[93;1;5mcleaning ...\n\033[0m"

clean:		clear cleaning 
			${RM} ${OBJS} 
			@clear
			@printf '\033[0;92;1mcleaning finished\n\033[0m'

fclean: 	clear clean cleaning
			${RM} ${NAME}
			@clear
			@printf '\033[0;92;1mcleaning finished\n\033[0m'

re: 		fclean all

.PHONY: 	all clean fclean re
