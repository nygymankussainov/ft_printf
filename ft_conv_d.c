/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:43:45 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/01 23:32:43 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_d(const char **format, va_list valist, t_flags *s)
{
	int						ret;
	char					*str;
	long long				nbr;
	int						tmp;

	ret = 0;
	tmp = 0;
	s->conv = **F;
	if (s->l == 2)
		nbr = (long long)va_arg(valist, long long);
	else if (s->l == 1)
		nbr = (long)va_arg(valist, long);
	else if (s->h == 2)
		nbr = (char)va_arg(valist, int);
	else if (s->h == 1)
		nbr = (short)va_arg(valist, int);
	else
		nbr = (long long)va_arg(valist, int);
	s->pos = nbr < 0 ? 0 : s->pos;
	str = ft_itoa_ll(nbr);
	ret = s->pos ? ft_strlen(str) + 1 : ft_strlen(str);
	s->zero = s->zero_padd ? 0 : s->zero;
	ret += s->zero_padd == s->width && s->neg && s->pos ? 1 : 0;
	s->zero_padd = ret >= s->zero_padd ? 0 : s->zero_padd;
	if (s->neg && s->pos)
	{
		write(1, "+", 1);
		ret--;
	}
	if (!s->width && s->zero_padd)
	{
		s->width = s->zero_padd;
		s->zero = 1;
		s->width += nbr < 0 || s->pos ? 1 : 0;
	}
	else if (s->width && s->zero_padd && s->zero_padd > ret)
	{
		s->zero_padd += nbr < 0 || s->pos ? 1 : 0;
		if (s->width > s->zero_padd)
		{
			s->width -= s->zero_padd;
			tmp += s->width;
			s->width += s->zero_padd;
		}
		if (s->width > s->zero_padd && !s->neg)
		{
			s->width -= s->zero_padd;
			while (s->width--)
				ft_putchar(' ');
		}
		s->width = s->zero_padd;
		s->zero = 1;
	}
	if (s->whitesp && !s->pos && str[0] != '-')
	{
		ft_putchar(' ');
		tmp += s->width && !s->zero_padd && s->neg ? 2 : 1;
		if (s->width && !s->zero_padd && s->neg)
		{
			s->width--;
			ret++;
		}
		if (s->width && !s->zero_padd)
			s->width--;
	}
	if (ret >= s->width)
	{
		if (s->pos && !s->neg)
			write(1, "+", 1);
		ft_putstr(str);
	}
	ret = ret < s->width ? width(str, s, ret) + tmp : ret + tmp;
	if (tmp > 0 && s->neg)
		while (tmp--)
			ft_putchar(' ');
	*F += 1;
	free(str);
	return (ret);
}
