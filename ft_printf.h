/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:02:01 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/16 15:47:49 by vhazelnu         ###   ########.fr       */
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
	long double		longdb;
	short			isint;
	double			db;
	char			*binary;
	char			*exp;
	char			*mant;
	int				exp_i;
	int				mant_i;
}					t_f;

typedef struct		s_printf
{
	char			conv;
	short			bigl;
	short			h;
	short			l;
	int				width;
	short			zero;
	short			sign;
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
int					ft_conv_f(const char **format, va_list valist, t_printf s);
int					ft_number(const char **format, va_list valist, t_printf s);
int					ft_symbol(const char **format, va_list valist, t_printf s);
int					print_width(char *str, t_printf s, int ret);
void				print_decimal(char *mant, int exp_i, short isint);
int					get_width(char *str);
void				longadd(char *s1, char *s2, char **res2);
void				longmulti(char *a, const char *b, char **c);
void				longdiv(char *number, int divisor, char **res);

#endif
