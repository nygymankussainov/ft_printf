/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:05:38 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/13 17:01:27 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		udigit_count(unsigned long long nb, int base)
{
	int i;

	i = 0;
	while (nb /= base)
		i++;
	return (i + 1);
}

char			*ft_uitoa_base(unsigned long long nb, int base)
{
	char	*str_base;
	char	*result;
	int		i;

	str_base = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	i = udigit_count(nb, base);
	result = (char *)ft_memalloc(sizeof(char) * i + 1);
	result[i] = '\0';
	while (i > 0)
	{
		result[i - 1] = str_base[nb % base];
		nb /= base;
		i--;
	}
	return (result);
}

int				ft_conv_u(const char *format, va_list valist)
{
	int						char_count;
	char					*integer_string;
	unsigned long long		nbr;

	char_count = 0;
	if (*F == 'h' && *(F + 1) == 'h')
		nbr = (unsigned char)va_arg(valist, int);
	else if (*F == 'h')
		nbr = (unsigned short)va_arg(valist, unsigned int);
	else if (*F == 'l' && *(F + 1) == 'l')
		nbr = (long long)va_arg(valist, long long);
	else if (*F == 'l')
		nbr = (unsigned long)va_arg(valist, unsigned long);
	else
		nbr = va_arg(valist, unsigned int);
	integer_string = ft_uitoa_base(nbr, 10);
	ft_putstr(integer_string);
	char_count += ft_strlen(integer_string);
	return (char_count);
}
