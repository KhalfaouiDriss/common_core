LIBFT = libft/libft.a

CC = cc
# CCFLAGS = cc -Wall -Werror -Wextra

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
SRCS_SERVER_BONUS = bonus/server_bonus.c
SRCS_CLIENT_BONUS = bonus/client_bonus.c
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIEN_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)



all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
		${CC} ${OBJS_SERVER} libft/libft.a -o ${SERVER}
		${CC} ${OBJS_CLIENT} libft/libft.a -o ${CLIENT}

$(LIBFT):
		${MAKE} -C ./libft




bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) $(CLIENT_BONUS): $(OBJS_CLIEN_BONUS) $(OBJS_SERVER_BONUS) $(LIBFT)
		${CC} ${OBJS_SERVER_BONUS} ./libft/libft.a -o ${SERVER_BONUS}
		${CC} ${OBJS_CLIEN_BONUS} ./libft/libft.a -o ${CLIENT_BONUS}




clean:	
		$(MAKE) clean -C ./libft
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT} $(OBJS_CLIEN_BONUS) $(OBJS_SERVER_BONUS)

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re:	fclean all

.PHONY: clean fclean re all