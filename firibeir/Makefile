# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: firibeir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 20:33:20 by firibeir          #+#    #+#              #
#    Updated: 2022/11/19 20:33:23 by firibeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = ft_printf.h

SRCS = ft_printf.c\
       ft_puthexa_up.c\
       ft_puthexa_low.c\
       ft_putchar.c\
       ft_putnbr.c\
       ft_putnbr_u.c\
       ft_putstr.c\
	ft_putpoint.c

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	ar -rc $(NAME) $(OBJ)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
