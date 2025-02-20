# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 00:57:03 by sel-abbo          #+#    #+#              #
#    Updated: 2024/11/23 17:31:38 by sel-abbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
ARCH = ar rcs
RM = rm -f

FILES = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putnbr_unsigned.c ft_puthexa.c

OB = ${FILES:.c=.o}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OB}
	${ARCH} ${NAME} ${OB}

all: ${NAME}

clean:
	${RM} ${OB}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
