/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:57:32 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/01 21:27:44 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short		flag_length(char *str, char c)
{
	short	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

void		ft_fill_struct(const char *format, int i, t_flags *s)
{
	char		*str;

	str = ft_strnew(i + 1);
	str = ft_strncpy(str, F, i + 1);
	str[i + 1] = '\0';
	i = 0;
	while (str[i])
	{
		s->prec = str[i] == '.' ? ft_atoi(str + i + 1) : s->prec;
		s->zero_padd = str[i] == '.' ? ft_atoi(str + i + 1) : s->zero_padd;
		s->hash = str[i] == '#' ? 1 : s->hash;
		s->zero = str[i] == '0' && !ft_isalpha(str[i + 1]) ? 1 : s->zero;
		s->neg = str[i] == '-' ? 1 : s->neg;
		s->pos = str[i] == '+' ? 1 : s->pos;
		s->bigl = str[i] == 'L' ? 1 : s->bigl;
		i++;
	}
	s->width += get_width(str);
	s->l = flag_length(str, 'l');
	s->h = flag_length(str, 'h');
	free(str);
}

int			ft_conv(const char **format, va_list valist, t_flags *s)
{
	int		ret;

	ret = 0;
	s->zero = s->neg && (**F == 'f' || **F == 'F') ? 0 : s->zero;
	if (ft_strchr("diouxXpfF", **F) && *F)
		ret = ft_number(F, valist, s);
	else if (ft_strchr("sc", **F) && **F)
		ret = ft_symbol(F, valist, s);
	else
	{
		if (s->width)
		{
			ret += --s->width;
			while (s->width--)
				write(1, " ", 1);
		}
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
	t_flags		*s;

	if (!(s = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (0);
	i = 0;
	(*F)++;
	while (iswhitesp(**F) || ((**F == '-' || **F == '+')
		&& *(*F + 1) != ft_isdigit(*(*F + 1))))
	{
		if (iswhitesp(**F))
			s->whitesp++;
		else if (**F == '-')
			s->neg = 1;
		else if (**F == '+')
			s->pos = 1;
		(*F)++;
	}
	s->prec = 6;
	while (ft_strchr(".-+#lLh0123456789", *(*F + i)) && *(F + i))
		i++;
	if (i)
		ft_fill_struct(*F, i, s);
	*F += i;
	ret = ft_conv(F, valist, s);
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
