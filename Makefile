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

LIB = -L libft/ -lft

INCLUDES = -I ./includes -I libft/includes

SRCS = ft_printf.c ft_itoa_base.c ft_conv_p.c ft_conv_x.c ft_conv_s.c ft_conv_c.c ft_conv_d.c ft_conv_o.c ft_conv_u.c\

OBJS = $(SRCS:.c=.o)

CCFL = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c $(INCLUDES)
	gcc $(CCFL) -c $(SRCS) $(LIB) $(INCLUDES)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
