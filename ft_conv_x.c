/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nygymankussainov <nygymankussainov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:53:37 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/03 15:22:15 by nygymankuss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_x(const char **format, va_list valist, t_flags *s)
{
	int						ret;
	int						tmp;
	char					*str;
	unsigned long long		nbr;

	ret = 0;
	tmp = 0;
	if (s->l == 2)
		nbr = (unsigned long long)va_arg(valist, unsigned long long);
	else if (s->l == 1)
		nbr = (unsigned long)va_arg(valist, unsigned long);
	else if (s->h == 2)
		nbr = (unsigned char)va_arg(valist, int);
	else if (s->h == 1)
		nbr = (unsigned short)va_arg(valist, unsigned int);
	else
		nbr = va_arg(valist, unsigned int);
	if (**F == 'x')
		str = ft_uitoa_base(nbr, 16, 'x');
	else
		str = ft_uitoa_base(nbr, 16, 'X');
	s->neg = s->hash && s->width && ft_count_digit_ll(nbr, 1) >= s->width ? 0 : s->neg;
	s->width = s->hash && s->width && ft_count_digit_ll(nbr, 1) >= s->width ? 0 : s->width;
	s->zero = s->zero_padd ? 0 : s->zero;
	ret = s->hash && nbr != 0 ? ft_strlen(str) + 2 : ft_strlen(str);
	if ((s->hash && nbr != 0)|| (s->hash && ret >= s->width && nbr != 0))
	{
		if (ret >= s->width && nbr != 0)
		{
			tmp = 2;
			if (**F == 'X')
				write(1, "0X", 2);
			else
				write(1, "0x", 2);
		}
		else
		{
			if (**F == 'X')
				str = ft_strjoin("0X", str, 0, 1);
			else
				str = ft_strjoin("0x", str, 0, 1);
		}
	}
	ret = manage_width(str, s) + tmp;
	*F += 1;
	free(str);
	return (ret);
}
