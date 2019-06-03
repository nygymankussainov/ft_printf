/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:43:45 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/03 15:22:24 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_d(const char *format, va_list valist)
{
	int						char_count;
	char					*integer_string;
	unsigned long long int	nbr;

	char_count = 0;
	if (*F == 'd' || *F == 'i')
		nbr = va_arg(valist, int);
	else if (*F == 'h' && *(F + 1) == 'h')
		nbr = (char)va_arg(valist, int);
	else
		nbr = (short)va_arg(valist, int);
	integer_string = ft_itoa(nbr);
	ft_putstr(integer_string);
	char_count += ft_strlen(integer_string);
	return (char_count);
}
