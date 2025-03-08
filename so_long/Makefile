NAME = so_long
CC = cc -g
MLX = -L/usr/include/minilibx-linux -lmlx -lXext -lX11 
GNL = includes/get_next_line/get_next_line.c includes/get_next_line/get_next_line_utils.c
LIBFT = includes/libft/libft.a 
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard src/*.c utils/*.c) 

OBJS = $(SRCS:.c=.o)

all: printf $(LIBFT) $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(GNL) includes/libft/libft.a includes/ft_printf/ft_printf.a


$(LIBFT):
		${MAKE} -C ./includes/libft

printf:
	$(MAKE) -C includes/ft_printf

clean:
	$(MAKE) -C includes/ft_printf clean
	$(MAKE) -C includes/libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C includes/ft_printf fclean
	$(MAKE) -C includes/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re printf
