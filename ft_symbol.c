/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symbol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nygymankussainov <nygymankussainov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 10:27:31 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/30 04:44:10 by nygymankuss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_symbol(const char **format, va_list valist, t_flags *s)
{
	char	*str;
	char	sym;
	int		ret;

	ret = 0;
	s->conv = **F;
	if (**F == 's')
	{
		str = va_arg(valist, char *);
		ret = ft_strlen(str);
		if (ret >= s->width)
			ft_putstr(str);
		ret = ret < s->width ? width(str, s, ret) : ret;
	}
	else
	{
		sym = (char)va_arg(valist, int);
		if (ret >= s->width)
			ft_putchar(sym);
		ret = ret < s->width ? width(&sym, s, 1) : ret + 1;
	}
	*F += 1;
	return (ret);
}
