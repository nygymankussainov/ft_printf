/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:20:32 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/14 18:53:31 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_number(const char **format, va_list valist, t_printf s)
{
	int		char_count;

	char_count = 0;
	s.conv = **F;
	if (s.conv == 'd' || s.conv == 'i')
		char_count = ft_conv_d(F, valist, s);
	else if (s.conv == 'x' || s.conv == 'X')
		char_count = ft_conv_x(F, valist, s);
	else if (s.conv == 'o')
		char_count = ft_conv_o(F, valist, s);
	else if (s.conv == 'u')
		char_count = ft_conv_u(F, valist, s);
	else if (s.conv == 'p')
		char_count = ft_conv_p(F, valist, s);
	return (char_count);
}
