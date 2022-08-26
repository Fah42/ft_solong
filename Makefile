SRCS			= main.c

OBJ				= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= so_long

all:			$(NAME)

# $(NAME):		$(OBJS)
# 				ar rcs $(NAME) $(OBJS)
%.o: %.c
	$(CC) -I/usr/include -Lminilibx-linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Lminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
#gcc main.c -L ./minilibx-linux -lmlx -lXext -lX11 -I ./minilibx-linux


clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean
				make all

.PHONY:			all clean fclean re
