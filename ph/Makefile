NAME = philo

CFLAGS = -Wall -Wextra -Werror

# SRC = $(wildcard src/*.c)
SRC = src/init.c src/main.c src/simulation.c src/utils.c src/utils_2.c

OBJ = ${SRC:.c=.o}

all:${NAME}

${NAME}:${OBJ}
# 	${MAKE} -C libft/
	cc ${CFLAGS} ${OBJ} -o ${NAME}

clean:
# 	${MAKE} -C libft/ fclean
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all fclean re clean