NAME = push_swap.a

CFLAGS = -Wall -Wextra -Werror

SRC = libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strlcpy.c \
		libft/ft_strlen.c libft/ft_substr.c 

OBJ = $(SRC:.c=.o)
  
all: $(NAME)
  
$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all fclean re clean