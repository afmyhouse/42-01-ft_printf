# DIRECTORIES = $(wildcard */.)

# all:
# 	@echo $(DIRECTORIES)
# Todos os subdirectórios


CFLAGS	= -Wall -Wextra -Werror
CC	= cc
RM	= rm -f
AR	= ar rcs
LIBFT	= libft
INC	= -I .

NAME	= libftprintf.a

SRCS	= ft_printf.c ft_printhex.c ft_printnbr.c \
	  ft_printptr.c ft_printuint.c ft_print_utils.c

OBJS	= ${SRCS:.c=.o}

all: ${NAME}

${NAME}:${OBJS}
	${AR} $@ $^

%.o:%.c
	${CC} ${CFLAGS} ${INC} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: re clean fclean all

