NAME = philo

# CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard src/*)

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	cc $(CFLAGS) -o $(NAME) $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)
