/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:57:32 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/15 19:44:35 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short		fl_length(char *str, char c)
{
	short i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

t_printf	ft_fill_struct(const char *format, int i)
{
	char		*str;
	t_printf	s;

	str = ft_strnew(i);
	str = ft_strncpy(str, F, i);
	s.zero = str[0] == '0' ? 1 : 0;
	s.sign = str[0] == '-' ? -1 : 1;
	s.sign = str[0] == '+' || str[1] == '+' ? 2 : s.sign;
	s.width = get_width(str);
	s.l = fl_length(str, 'l');
	s.h = fl_length(str, 'h');
	free(str);
	return (s);
}

int			ft_conv(const char **format, va_list valist, t_printf s)
{
	int		ret;

	ret = 0;
	if (ft_strchr("diouxXp", **F) && *F)
		ret = ft_number(F, valist, s);
	else if (ft_strchr("sc", **F) && **F)
		ret = ft_symbol(F, valist, s);
	else
	{
		ft_putchar(**F);
		*F += 1;
		ret++;
	}
	return (ret);
}

int			ft_percent(const char **format, va_list valist)
{
	int			ret;
	int			i;
	t_printf	s;

	ret = 0;
	i = 0;
	*F += 1;
	while (ft_strchr("-+lh0123456789", *(*F + i)) && *(F + i))
		i++;
	s = ft_fill_struct(*F, i);
	*F += i;
	ret = ft_conv(F, valist, s);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	int			ret;
	va_list		valist;

	va_start(valist, F);
	ret = 0;
	while (*F)
	{
		if (*F == '%')
			ret += ft_percent(&F, valist);
		else
		{
			ft_putchar(*F);
			F++;
			ret++;
		}
	}
	va_end(valist);
	return (ret);
}
