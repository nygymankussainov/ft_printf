/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nygymankussainov <nygymankussainov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:50:18 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/30 04:45:06 by nygymankuss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_p(const char **format, va_list valist, t_flags *s)
{
	int						ret;
	char					*str;
	void					*ptr;

	ret = 0;
	ptr = va_arg(valist, void *);
	str = ft_itoa_base((long long int)ptr, 16);
	ret = ft_strlen(str);
	if (ret >= s->width)
		ft_putstr(str);
	ret = ret < s->width ? width(str, s, ret) : ret;
	*F += 1;
	free(str);
	return (ret);
}
