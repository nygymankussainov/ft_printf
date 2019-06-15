/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:50:18 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/15 19:18:11 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_p(const char **format, va_list valist, t_printf s)
{
	int						ret;
	char					*str;
	void					*ptr;

	ret = 0;
	ptr = va_arg(valist, void *);
	str = ft_itoa_base((long long int)ptr, 16, 'p');
	ret = s.sign == 2 ? ft_strlen(str) + 1 : ft_strlen(str);
	if (ret >= s.width)
		ft_putstr(str, s.sign);
	ret = ret < s.width ? print_width(str, s, ret) : ret;
	*F += 1;
	return (ret);
}
