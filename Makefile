# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/06/03 15:08:22 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME = ft_printf

LIB_FOLDER = ./libft/

INCLUDES = -I ./ -I $(LIB_FOLDER)

SRC = ft_printf.c ft_itoa_base.c string/ft_conv_s.c string/ft_conv_c.c integer/ft_conv_p.c integer/ft_conv_x.c integer/ft_conv_d.c integer/ft_conv_o.c integer/ft_conv_u.c

OBJECTS = $(SRC:.c=.o)

LIB = -L $(LIB_FOLDER) -lft

all:
	@make -C $(LIB_FOLDER)
	gcc $(SRC) $(LIB) $(INCLUDES) -o $(NAME) -g

clean:
	@make clean -C $(LIB_FOLDER)

fclean:	clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_FOLDER)

re:	fclean all
