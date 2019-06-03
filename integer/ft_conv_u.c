/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:05:38 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/03 15:25:40 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_u(const char *format, va_list valist)
{
	int						char_count;
	char					*integer_string;
	unsigned long long int	nbr;

	char_count = 0;
	if (*F == 'h' && *(F + 1) == 'h')
		nbr = (unsigned char)va_arg(valist, int);
	else if (*F == 'h')
		nbr = (unsigned short)va_arg(valist, unsigned int);
	else
		nbr = va_arg(valist, unsigned int);
	integer_string = ft_itoa_base(nbr, 10, 'u');
	ft_putstr(integer_string);
	char_count += ft_strlen(integer_string);
	return (char_count);
}
