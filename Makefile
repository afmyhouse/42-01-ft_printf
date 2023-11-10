#teste
NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./libft/libft.a

RM = rm -rf

SRCS = ./src/ft_pf_all2s_1.c ./src/ft_pf_all2s_2.c\
		./src/ft_pf_tools_1.c\
		./src/ft_pf_fwp2s.c ./src/ft_pf_fwp2f.c\
		./src/ft_pf_type_numbers.c\
		./src/ft_printf.c ./src/ft_pf_type_scp.c


SRCS_BONUS = ./src/_ft_pf_all2s_1.c ./src/_ft_pf_all2s_2.c\
		./src/_ft_pf_tools_1.c\
		./src/_ft_pf_fwp2s.c ./src/_ft_pf_fwp2f.c\
		./src/_ft_pf_type_numbers.c\
		./src/_ft_printf.c ./src/_ft_pf_type_scp.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_BONUS:.c=.o)

OBJS_M = $(SRC_MAIN:.c=.o)

all: $(NAME)


$(NAME):$(OBJS)
	$(MAKE) -C ./libft
	@echo "libft ok!"
	cp $(LIBFT) $(NAME)
	@echo "copy to libftprintf OK!"
	ar rcs $(NAME) $(OBJS)
	@echo "buuild libftprintf mandatory OK!"

bonus:fclean $(OBJS_B)
	$(MAKE) -C ./libft
	@echo "libft ok!"
	cp $(LIBFT) $(NAME)
	@echo "copy to libftprintf OK!"
	ar rcs $(NAME) $(OBJS_B)
	@echo "build libftprintf bonus OK!"


clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(OBJS_B)
	@echo "clean OK!"

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	@echo "fclean OK!"

re: fclean all

.PHONY: all clean fclean re bonus
