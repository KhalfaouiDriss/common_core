NAME = libftprintf.a

FLAGS = -Wall -Wextra - Werror

SRC = ft_printf.c ft_putnbr.c ft_putptr ft_print_hex_low.c \
		ft_print_hex_upp.c ft_printf_utiles.c ft_u_putnbr.c \
		ft_putstr.c 

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar crs ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ}
fclean: clean
	rm -rf ${NAME}
re: fclean all

.PHONY: all clean fclean re
