# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/06/15 10:36:10 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIB = -L libft/ -lft

INCLUDES = -I ./includes -I libft/includes

SRCS = ft_symbol.c ft_itoa_base.c ft_printf.c ft_number.c ft_conv_x.c ft_conv_d.c ft_conv_p.c ft_conv_o.c ft_conv_u.c main.c

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
