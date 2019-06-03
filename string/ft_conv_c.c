/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:41:37 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/03 14:33:20 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_c(const char *format, va_list valist)
{
	char	sym;
	int		char_count;

	char_count = 0;
	if (*F == 'c')
	{
		sym = (char)va_arg(valist, int);
		ft_putchar(sym);
		char_count++;
	}
	return (char_count);
}
