# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 16:12:57 by fhadhri           #+#    #+#              #
#    Updated: 2022/06/16 12:21:46 by fhadhri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			= ft_printf.c ft_printchar.c ft_printint.c ft_printu.c ft_printpercent.c ft_printhex.c ft_printstr.c ft_printaddr.c ft_tools.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean
				make all


.PHONY:			all clean fclean re
