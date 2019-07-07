/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:20:32 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/06 15:18:10 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_number(const char **format, va_list valist, t_printf s)
{
	int		ret;

	ret = 0;
	s.conv = **F;
	if (s.conv == 'd' || s.conv == 'i')
		ret = ft_conv_d(F, valist, s);
	else if (s.conv == 'x' || s.conv == 'X')
		ret = ft_conv_x(F, valist, s);
	else if (s.conv == 'o')
		ret = ft_conv_o(F, valist, s);
	else if (s.conv == 'u')
		ret = ft_conv_u(F, valist, s);
	else if (s.conv == 'p')
		ret = ft_conv_p(F, valist, s);
	else if (s.conv == 'f')
		ret = ft_conv_f(F, valist, s);
	return (ret);
}
