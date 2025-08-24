NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRC = src/init.c src/main.c src/simulation.c src/utils.c src/utils_2.c

OBJ = ${SRC:.c=.o}

all:${NAME}

${NAME}:${OBJ}
	cc ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all fclean re clean