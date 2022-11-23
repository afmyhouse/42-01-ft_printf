# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 16:48:10 by antoda-s          #+#    #+#              #
#    Updated: 2022/11/23 17:00:24 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = ft_printf.c ft_printhex.c ft_printnbr.c \
          ft_printptr.c ft_printuint.c ft_print_utils.c

OBJS    = ${SRCS:.c=.o}

CFLAGS  = -Wall -Wextra -Werror
CC      = cc
RM      = rm -f
AR      = ar rcs
LIBFT   = libft
INC     = -I .

NAME    = libftprintf.a


all:		${NAME}

${NAME}:	${OBJS}
			${AR} $@ $^

%.o:%.c
			${CC} ${CFLAGS} ${INC} -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		re clean fclean all
