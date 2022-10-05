SRC_MAIN		= main.c
SRCS			= ${SRC_MAIN}

LIBFT_DIR 		= Libft/

OBJ				= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= so_long
INCLUDE			= -Lmlx_linux -lmlx_Linux -L/usr/lib -Lminilibx-linux -lXext -lX11 -lm -lz
all:			$(NAME)

%.o: %.c
	$(CC) -I/usr/include -Lminilibx-linux -c $< -o $@

$(NAME): $(OBJ)
	@make -C ${LIBFT_DIR}
	$(CC) $(OBJ) $(CFLAGS) ${INCLUDE} Libft/libft.a -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
	make -C ${LIBFT_DIR} fclean
				$(RM) $(NAME)

re:				fclean
				make all

.PHONY:			all clean fclean re
