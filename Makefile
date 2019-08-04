# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile1                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/08/03 21:53:19 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIB = -L libft/ -lft

INCLUDES = -I ./includes -I libft/includes

SRCS = ft_symbol.c ft_printf.c ft_number.c ft_conv_f.c ft_conv_x.c ft_conv_d.c ft_conv_p.c ft_conv_o.c ft_conv_u.c width_for_f.c main.c \
		longadd.c longmulti.c decimal_part.c longdiv.c integer_part.c rounding_and_print.c calculate_decimal.c width.c find_conv_or_whitesp.c

OBJS = $(SRCS:.c=.o)

CCFL = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) libft/libft.a -g

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
