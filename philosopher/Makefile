NAME = philo

# CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard src/*.c)

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