/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:53:37 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/13 17:01:31 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_x(const char *format, va_list valist)
{
	int						char_count;
	char					*integer_string;
	unsigned long long		nbr;

	char_count = 0;
	if (*F == 'h' && *(F + 1) == 'h')
		nbr = (char)va_arg(valist, int);
	else if (*F == 'h')
		nbr = (unsigned short)va_arg(valist, unsigned int);
	else if (*F == 'l' && *(F + 1) == 'l')
		nbr = (unsigned long long)va_arg(valist, unsigned long long);
	else if (*F == 'l')
		nbr = (unsigned long)va_arg(valist, unsigned long);
	else
		nbr = va_arg(valist, unsigned int);
	if (*F == 'x' || *(F + 1) == 'x' || *(F + 2) == 'x')
		integer_string = ft_uitoa_base(nbr, 16);
	else if (*F == 'X' || *(F + 1) == 'X' || *(F + 2) == 'X')
		integer_string = ft_uitoa_base(nbr, 16);
	ft_putstr(integer_string);
	char_count += ft_strlen(integer_string);
	return (char_count);
}
