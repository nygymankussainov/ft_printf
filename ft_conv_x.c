/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:53:37 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/14 18:19:59 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_x(const char **format, va_list valist, t_printf s)
{
	int						char_count;
	char					*integer_string;
	unsigned long long		nbr;

	char_count = 0;
	if (s.l == 2)
		nbr = (unsigned long long)va_arg(valist, unsigned long long);
	else if (s.l == 1)
		nbr = (unsigned long)va_arg(valist, unsigned long);
	else if (s.h == 2)
		nbr = (unsigned char)va_arg(valist, int);
	else if (s.h == 1)
		nbr = (unsigned short)va_arg(valist, unsigned int);
	else
		nbr = va_arg(valist, unsigned int);
	if (**F == 'x')
		integer_string = ft_uitoa_base(nbr, 16, 'x');
	else
		integer_string = ft_uitoa_base(nbr, 16, 'X');
	ft_putstr(integer_string);
	char_count += ft_strlen(integer_string);
	*F += 1;
	return (char_count);
}
