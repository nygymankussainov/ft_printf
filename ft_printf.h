/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:02:01 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/21 19:09:49 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define F format

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef union			u_un
{
	double				d;
	int					sign : 1;
	unsigned int		exponent : 11;
	long				mantissa : 52;
}						t_un;

typedef struct			s_printf
{
	char				conv;
	short				h;
	short				l;
	int					width;
	short				zero;
	short				sign;
	short				hash;
}						t_printf;

int						ft_printf(const char *format, ...);
int						ft_conv_s(const char **format, va_list valist, t_printf s);
int						ft_conv_c(const char **format, va_list valist, t_printf s);
int						ft_conv_o(const char **format, va_list valist, t_printf s);
int						ft_conv_p(const char **format, va_list valist, t_printf s);
int						ft_conv_x(const char **format, va_list valist, t_printf s);
int						ft_conv_d(const char **format, va_list valist, t_printf s);
int						ft_conv_u(const char **format, va_list valist, t_printf s);
int						ft_number(const char **format, va_list valist, t_printf s);
int						ft_symbol(const char **format, va_list valist, t_printf s);
int						print_width(char *integer_string, t_printf s, int char_count);
int						get_width(char *str);

#endif
