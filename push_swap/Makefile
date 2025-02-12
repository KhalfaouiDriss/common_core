NAME = push_swap

SRCS = $(wildcard src/*.c)

OBJS = ${SRCS:.c=.o}

CC = cc -g
CFLAGS = -Wall -Wextra -Werror


RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${CC} ${OBJS} -o ${NAME}

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
