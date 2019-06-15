/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symbol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 10:27:31 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/15 17:09:47 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_symbol(const char **format, va_list valist, t_printf s)
{
	char	*str;
	char	sym;
	int		ret;

	ret = 0;
	if (**F == 's')
	{
		str = va_arg(valist, char *);
		ret = ft_strlen(str);
		if (ret >= s.width)
			ft_putstr(str);
		ret = ret < s.width ? print_width(str, s, ret) : ret;
	}
	else
	{
		sym = (char)va_arg(valist, int);
		if (ret >= s.width)
			ft_putchar(sym);
		ret = ret < s.width ? print_width(&sym, s, 1) : ret + 1;
	}
	*F += 1;
	return (ret);
}
