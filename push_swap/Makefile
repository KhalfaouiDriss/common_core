NAME = push_swap

SRCS = $(wildcard src/*.c utils/*.c)

OBJS = ${SRCS:.c=.o}

CC = gcc
# CFLAGS = -Wall -Wextra -Werror -Wno-unused-but-set-variable


RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${OBJS} ./libft/libft.a -o ${NAME}

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CHECK_OBJS} ./libft/libft.a -o ${CHECK}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re