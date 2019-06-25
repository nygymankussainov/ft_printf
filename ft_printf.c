/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:57:32 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/23 16:18:08 by vhazelnu         ###   ########.fr       */
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

void		ft_fill_struct(const char *format, int i, t_printf **s)
{
	char		*str;

	str = ft_strnew(i);
	str = ft_strncpy(str, F, i);
	i = 0;
	while (str[i])
	{
		(*s)->hash = str[i] == '#' ? 1 : (*s)->hash;
		(*s)->zero = str[i] == '0' ? 1 : (*s)->zero;
		(*s)->sign = str[i] == '-' ? -1 : (*s)->sign;
		(*s)->sign = str[i] == '+' ? 2 : (*s)->sign;
		i++;
	}
	(*s)->width = get_width(str);
	(*s)->l = fl_length(str, 'l');
	(*s)->h = fl_length(str, 'h');
	free(str);
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
	t_printf	*s;

	if (!(s = (t_printf *)ft_memalloc(sizeof(t_printf))))
		return (0);
	ret = 0;
	i = 0;
	*F += 1;
	while (ft_strchr("-+#lh0123456789", *(*F + i)) && *(F + i))
		i++;
	if (i)
		ft_fill_struct(*F, i, &s);
	*F += i;
	ret = ft_conv(F, valist, *s);
	free(s);
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
