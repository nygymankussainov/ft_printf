/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nygymankussainov <nygymankussainov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:05:38 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/30 04:45:19 by nygymankuss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_u(const char **format, va_list valist, t_flags *s)
{
	int						ret;
	char					*str;
	unsigned long long		nbr;

	ret = 0;
	if (s->l == 2)
		nbr = (long long)va_arg(valist, long long);
	else if (s->l == 1)
		nbr = (unsigned long)va_arg(valist, unsigned long);
	else if (s->h == 2)
		nbr = (unsigned char)va_arg(valist, int);
	else if (s->h == 1)
		nbr = (unsigned short)va_arg(valist, unsigned int);
	else
		nbr = va_arg(valist, unsigned int);
	str = ft_uitoa_base(nbr, 10, 'u');
	ret = ft_strlen(str);
	if (ret >= s->width)
		ft_putstr(str);
	ret = ret < s->width ? width(str, s, ret) : ret;
	*F += 1;
	free(str);
	return (ret);
}
