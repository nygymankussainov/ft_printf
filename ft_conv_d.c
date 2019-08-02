/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:43:45 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/02 21:12:18 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	get_nbr(const char **format, va_list valist, t_flags *s)
{
	long long	nbr;

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
	return (nbr);
}

int			ft_conv_d(const char **format, va_list valist, t_flags *s)
{
	int						ret;
	int						sign;
	int						tmp;
	char					*str;
	long long				nbr;
	int						key;

	ret = 0;
	tmp = 0;
	key = 0;
	nbr = get_nbr(F, valist, s);
	sign = nbr < 0 ? -1 : 1;
	nbr = sign < 0 ? -nbr : nbr;
	str = ft_itoa_ll(nbr);
	s->zero = s->zero_padd ? 0 : s->zero;
	if (nbr == 0 && !s->zero_padd && s->dot)
		*str = '\0';
	if (s->pos && s->neg)
	{
		if (sign < 0)
			s->pos = 0;
	}
	if (sign < 0 && s->width)
		str = ft_strjoin("-", str, 0, 1);
	else if ((s->pos && s->neg) || (s->pos && !s->neg && s->width && sign > 0))
		str = ft_strjoin("+", str, 0, 1);
	if (!s->width && s->zero_padd && !s->zero)
	{
		if (sign < 0 || s->pos > 0)
		{
			if (sign < 0)
				write(1, "-", 1);
			else
				write(1, "+", 1);
			tmp++;
		}
		s->width = s->zero_padd;
		s->zero_padd = 0;
		s->zero = 1;
		key = 1;
	}
	ret += ft_strlen(str);
	if (s->whitesp && (s->width <= ret || s->neg ||
		(key && !s->zero_padd) || (s->width && s->zero)) && sign > 0 && !s->pos)
	{
		write(1, " ", 1);
		if (s->neg && s->width > ret)
		{
			s->width -= s->zero_padd ? 1 : 0;
			ret += !s->zero_padd ? 1 : 0;
			tmp += s->zero_padd ? 1 : 0;
		}
		else if (s->width && s->zero && !key)
			ret += s->width > ret ? 1 : 0;
		else if (key)
			tmp += s->width > ret ? 1 : 0;
	}
	s->whitesp = s->width > ret || s->pos || sign < 0 ? 0 : s->whitesp;
	ret += width(str, s, sign, ret) + tmp + s->whitesp;
	*F += 1;
	free(str);
	return (ret);
}
