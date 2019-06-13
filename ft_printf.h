/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:02:01 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/13 17:59:52 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# define F format

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
char	*ft_itoa_base(long long nb, int base, char c);
int		ft_conv_s(const char *format, va_list valist);
int		ft_conv_c(const char *format, va_list valist);
int		ft_conv_o(const char *format, va_list valist);
int		ft_conv_p(const char *format, va_list valist);
int		ft_conv_x(const char *format, va_list valist);
int		ft_conv_d(const char *format, va_list valist);
int		ft_conv_u(const char *format, va_list valist);
char	*ft_uitoa_base(unsigned long long nb, int base);

#endif
