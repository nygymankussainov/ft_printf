/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:57:32 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/15 16:56:17 by vhazelnu         ###   ########.fr       */
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
	s.width = get_width(str, s.sign);
	s.l = fl_length(str, 'l');
	s.h = fl_length(str, 'h');
	free(str);
	return (s);
}

int			ft_conv(const char **format, va_list valist, t_printf s)
{
	int		char_count;

	char_count = 0;
	if (ft_strchr("diouxXp", **F) && *F)
		char_count = ft_number(F, valist, s);
	else if (ft_strchr("sc", **F) && **F)
		char_count = ft_symbol(F, valist, s);
	else
	{
		ft_putchar(**F);
		*F += 1;
		char_count++;
	}
	return (char_count);
}

int			ft_percent(const char **format, va_list valist)
{
	int			char_count;
	int			i;
	t_printf	s;

	char_count = 0;
	i = 0;
	*F += 1;
	while (ft_strchr("-lh0123456789", *(*F + i)) && *(F + i))
		i++;
	s = ft_fill_struct(*F, i);
	*F += i;
	char_count = ft_conv(F, valist, s);
	return (char_count);
}

int			ft_printf(const char *format, ...)
{
	int			char_count;
	va_list		valist;

	va_start(valist, F);
	char_count = 0;
	while (*F)
	{
		if (*F == '%')
			char_count += ft_percent(&F, valist);
		else
		{
			ft_putchar(*F);
			F++;
			char_count++;
		}
	}
	va_end(valist);
	return (char_count);
}
