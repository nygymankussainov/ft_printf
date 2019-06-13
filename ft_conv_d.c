/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:43:45 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/13 17:01:12 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_d(const char *format, va_list valist)
{
	int						char_count;
	char					*integer_string;
	unsigned long long		nbr;

	char_count = 0;
	if (*F == 'd' || *F == 'i')
		nbr = va_arg(valist, int);
	else if (*F == 'h' && *(F + 1) == 'h')
		nbr = (char)va_arg(valist, int);
	else if (*F == 'h')
		nbr = (short)va_arg(valist, int);
	else if (*F == 'l' && *(F + 1) == 'l')
		nbr = (long long)va_arg(valist, long long);
	else
		nbr = (long)va_arg(valist, long);
	integer_string = ft_itoa(nbr);
	ft_putstr(integer_string);
	char_count += ft_strlen(integer_string);
	return (char_count);
}
