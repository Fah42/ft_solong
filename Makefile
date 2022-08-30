SRCS			= ${SRC_MAIN} ${SRC_GNL}

SRC_MAIN		= main.c

LIBFT_A 		= libft.a
LIBFT_DIR 		= Libft/
LIBFT			= $(addprefix $(LIBFT_DIR), $(LIBFT_A))

GNL 			= get_next_line.c get_next_line_utils.c
SRC_GNL 		= $(addprefix Julien/, $(GNL))

OBJ				= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= so_long
INCLUDE			= -Lmlx_linux -lmlx_Linux -L/usr/lib -Lminilibx-linux -lXext -lX11 -lm -lz
all:			$(NAME)

%.o: %.c
	$(CC) -I/usr/include -Lminilibx-linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@make -C ${LIBFT_DIR}
	$(CC) $(OBJ) ${INCLUDE} -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean
				make all

.PHONY:			all clean fclean re
