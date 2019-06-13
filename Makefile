# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/06/13 17:42:03 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_itoa_base.c ft_conv_s.c ft_conv_c.c ft_conv_d.c ft_conv_o.c ft_conv_u.c\
	ft_putchar.c ft_putstr.c ft_strlen.c ft_memalloc.c ft_bzero.c ft_itoa.c

OBJS = ft_printf.o ft_itoa_base.o ft_conv_s.o ft_conv_c.o ft_conv_p.o ft_conv_x.o ft_conv_d.o ft_conv_o.o ft_conv_u.o\
	ft_putchar.o ft_putstr.o ft_strlen.o ft_memalloc.o ft_bzero.o ft_itoa.o

CCFL = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c $(INCLUDES)
	gcc -Wall -Wextra -Werror -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
