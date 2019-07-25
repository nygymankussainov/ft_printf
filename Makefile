# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/07/24 12:41:57 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = -L libft/ -lft

INCLUDES = -I ./includes -I libft/includes

SRCS = ft_symbol.c ft_printf.c ft_number.c ft_conv_f.c ft_conv_x.c ft_conv_d.c ft_conv_p.c ft_conv_o.c ft_conv_u.c width.c \
		longadd.c longmulti.c decimal_part.c longdiv.c integer_part.c rounding_and_print.c

OBJS = $(SRCS:.c=.o)

CCFL = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) libft/*.c
	@echo "libft is (re)compiling..."
	@make -C libft
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c $(INCLUDES)
	gcc $(CCFL) -c $(SRCS) $(LIB)

clean:
	@make clean -C libft
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
	@make re -C libft
