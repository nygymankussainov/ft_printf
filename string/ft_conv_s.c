/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:37:07 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/03 14:38:54 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_s(const char *format, va_list valist)
{
	char	*char_string;
	int		char_count;

	char_count = 0;
	if (*F == 's')
	{
		char_string = va_arg(valist, char *);
		ft_putstr(char_string);
		char_count += ft_strlen(char_string);
	}
	else if (*F == '%')
	{
		ft_putchar('%');
		char_count++;
	}
	return (char_count);
}
