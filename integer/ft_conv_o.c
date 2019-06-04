/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:51:47 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/04 09:46:04 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_o(const char *format, va_list valist)
{
	int						char_count;
	char					*integer_string;
	unsigned long long int	nbr;

	char_count = 0;
	if (*F == 'h' && *(F + 1) == 'h')
		nbr = (char)va_arg(valist, int);
	else if (*F == 'h')
		nbr = (unsigned short)va_arg(valist, unsigned int);
	else if (*F == 'l' && *(F + 1) == 'l')
		nbr = (long long int)va_arg(valist, long long int);
	else if (*F == 'l')
		nbr = (long int)va_arg(valist, long int);
	else
		nbr = va_arg(valist, unsigned int);
	integer_string = ft_itoa_base(nbr, 8, 'o');
	ft_putstr(integer_string);
	char_count += ft_strlen(integer_string);
	return (char_count);
}
