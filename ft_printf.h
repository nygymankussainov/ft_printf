/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:02:01 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/29 22:59:57 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define F format

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_f
{
	char			*binary;
	short			sign;
	char			*exp;
	char			*mant;
	long double		db;
	int				exp_i;
	int				mant_i;
	short			isint;
}					t_f;

typedef struct		s_printf
{
	int				prec;
	short			bigl;
	short			h;
	short			l;
	int				width;
	short			zero;
	short			pos;
	short			neg;
	short			hash;
}					t_printf;

int					ft_printf(const char *format, ...);
int					ft_conv_s(const char **format, va_list valist, t_printf s);
int					ft_conv_c(const char **format, va_list valist, t_printf s);
int					ft_conv_o(const char **format, va_list valist, t_printf s);
int					ft_conv_p(const char **format, va_list valist, t_printf s);
int					ft_conv_x(const char **format, va_list valist, t_printf s);
int					ft_conv_d(const char **format, va_list valist, t_printf s);
int					ft_conv_u(const char **format, va_list valist, t_printf s);
int					ft_conv_f(const char **format, va_list valist, t_printf *s);
int					ft_number(const char **format, va_list valist, t_printf *s);
int					ft_symbol(const char **format, va_list valist, t_printf s);
int					width(char *str, t_printf s, int ret);
int					integer_part(t_f f, t_printf *s, int sign);
int					decimal_part(char **integer, t_f f, t_printf *s, int sign);
int					print(char **decimal, char **integer, t_printf *s,
	int sign);
int					get_width(char *str);
void				longadd(char *s1, char *s2, char **res2);
void				longmulti(char *a, const char *b, char **c);
void				longdiv(char *number, int divisor, char **res);
int					iswhitesp(char c);

#endif
