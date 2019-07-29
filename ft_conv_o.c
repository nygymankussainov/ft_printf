/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:51:47 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/29 20:28:25 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_o(const char **format, va_list valist, t_printf s)
{
	int						ret;
	char					*str;
	unsigned long long		nbr;

	ret = 0;
	if (s.l == 2)
		nbr = (long long)va_arg(valist, long long);
	else if (s.l == 1)
		nbr = (long)va_arg(valist, long);
	else if (s.h == 2)
		nbr = (char)va_arg(valist, int);
	else if (s.h == 1)
		nbr = (unsigned short)va_arg(valist, unsigned int);
	else
		nbr = va_arg(valist, unsigned int);
	str = ft_itoa_base(nbr, 8);
	ret = s.hash ? ft_strlen(str) + 1 : ft_strlen(str);
	if (ret >= s.width)
	{
		if (s.hash == 1)
			write(1, "0", 1);
		else if (s.hash == 2)
			write(1, "+", 1);
		ft_putstr(str);
	}
	ret = ret < s.width ? width(str, s, ret) : ret;
	*F += 1;
	free(str);
	return (ret);
}
