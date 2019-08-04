# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/08/04 16:48:44 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = -L libft/ -lft

INCLUDES = -I ./includes -I libft/includes

SRCS = ft_symbol.c ft_printf.c ft_number.c ft_conv_f.c ft_conv_x.c ft_conv_d.c ft_conv_p.c ft_conv_o.c ft_conv_u.c width_for_f.c ft_conv_b.c \
		longadd.c longmulti.c decimal_part.c longdiv.c integer_part.c rounding_and_print.c calculate_decimal.c width.c find_conv_or_whitesp.c \
		libft/ft_atoi.c libft/ft_atoi_base.c libft/ft_bzero.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_itoa_base.c \
		libft/ft_itoa_ll.c libft/ft_memalloc.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_power.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_realloc.c \
		libft/ft_revstr.c libft/ft_strchr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strncpy.c \
		libft/ft_strndup.c libft/ft_strnew.c libft/ft_swap.c libft/ft_swap_str.c libft/ft_uitoa_base.c libft/iswhitesp.c libft/ft_bzero_null.c \
		libft/ft_islower.c libft/ft_isupper.c libft/ft_memdel.c libft/ft_skip_whitesp.c libft/ft_strcat.c

OBJS = $(SRCS:.c=.o) libft/ft_atoi.o libft/ft_atoi_base.o libft/ft_bzero.o libft/ft_isalpha.o libft/ft_isdigit.o libft/ft_itoa_base.o \
		libft/ft_itoa_ll.o libft/ft_memalloc.o libft/ft_memcpy.o libft/ft_memset.o libft/ft_power.o libft/ft_putchar.o libft/ft_putstr.o libft/ft_realloc.o \
		libft/ft_revstr.o libft/ft_strchr.o libft/ft_strcmp.o libft/ft_strcpy.o libft/ft_strdup.o libft/ft_strjoin.o libft/ft_strlen.o libft/ft_strncpy.o \
		libft/ft_strndup.o libft/ft_strnew.o libft/ft_swap.o libft/ft_swap_str.o libft/ft_uitoa_base.o libft/iswhitesp.o libft/ft_bzero_null.o \
		libft/ft_islower.o libft/ft_isupper.o libft/ft_memdel.o libft/ft_skip_whitesp.o libft/ft_strcat.o

CCFL = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
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
