NAME = philo

# CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard src/*.c)

OBJ = ${SRC:.c=.o}

all:${NAME}

${NAME}:${OBJ}
	${MAKE} -C libft/
	cc ${CFLAGS} ${OBJ} libft/libft.a -o ${NAME}

clean:
	${MAKE} -C libft/ fclean
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all fclean re clean