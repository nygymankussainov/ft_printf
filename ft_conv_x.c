/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:53:37 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/19 10:58:41 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_x(const char **format, va_list valist, t_printf s)
{
	int						ret;
	char					*str;
	unsigned long long		nbr;

	ret = 0;
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
		str = ft_uitoa_base(nbr, 16, 'x');
	else
		str = ft_uitoa_base(nbr, 16, 'X');
	ret = s.hash ? ft_strlen(str) + 2 : ft_strlen(str);
	if (ret >= s.width)
	{
		if (s.hash)
		{
			s.hash = 3;
			if (**F == 'X')
				s.hash = 4;
		}
		ft_putstr(str, s.hash);
	}
	ret = ret < s.width ? print_width(str, s, ret) : ret;
	*F += 1;
	return (ret);
}
