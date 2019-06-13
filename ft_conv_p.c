/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:50:18 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/13 17:01:20 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_p(const char *format, va_list valist)
{
	int						char_count;
	char					*integer_string;
	void					*ptr;

	char_count = 0;
	if (*F == 'p')
	{
		ptr = va_arg(valist, void *);
		integer_string = ft_itoa_base((long long int)ptr, 16, 'p');
		ft_putstr(integer_string);
		char_count += ft_strlen(integer_string);
	}
	return (char_count);
}
