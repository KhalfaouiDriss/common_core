NAME = so_long
BNAME = so_long_bonus
CC = cc -g
MLX = includes/minilibx-linux -lmlx -lXext -lX11 
GNL = includes/get_next_line/get_next_line.c includes/get_next_line/get_next_line_utils.c 
# CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c src/mv_player.c src/render_map.c  src/valid_map.c src/utils_1.c src/utils_2.c
BSRCS = src_bonus/main_bonus.c src_bonus/mv_player_bonus.c src_bonus/render_map_bonus.c \
		src_bonus/valid_map_bonus.c src_bonus/utils_1_bonus.c src_bonus/utils_2_bonus.c \
		src_bonus/animation_bonus.c src_bonus/utils_3_bonus.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: printf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(GNL) includes/ft_printf/libftprintf.a

printf:
	$(MAKE) -C includes/ft_printf

bonus: printf $(BOBJS)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS) $(MLX) $(GNL) includes/ft_printf/libftprintf.a

clean:
	$(MAKE) -C includes/ft_printf clean
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean: clean
	$(MAKE) -C includes/ft_printf fclean
	rm -f bonus
	rm -f $(NAME)
	rm -f $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus printf
