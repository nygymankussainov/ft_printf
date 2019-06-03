/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:06:11 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/03 15:44:39 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		char_count;
	va_list valist;

	va_start(valist, F);
	char_count = 0;
	while (*F)
	{
		if (*F == '%')
		{
			F++;
			if (*F == 's' || *F == '%')
				char_count += ft_conv_s(F, valist);
			else if (*F == 'c')
				char_count += ft_conv_c(F, valist);
			else if (*F == 'd' || *F == 'i' ||
				(*F == 'h' && (*(F + 1) == 'd' || *(F + 1) == 'i')) ||
				(*F == 'h' && *(F + 1) == 'h' && (*(F + 2) == 'd' ||
				*(F + 2) == 'i')))
				char_count += ft_conv_d(F, valist);
			else if (*F == 'o' || (*F == 'h' && *(F + 1) == 'o') ||
				(*F == 'h' && *(F + 1) == 'h' && *(F + 2) == 'o'))
				char_count += ft_conv_o(F, valist);
			else if (*F == 'p')
				char_count += ft_conv_p(F, valist);
			else if (*F == 'x' || *F == 'X' ||
				(*F == 'h' && (*(F + 1) == 'x' || *(F + 1) == 'X')) ||
				(*F == 'h' && *(F + 1) == 'h' && (*(F + 2) == 'x'
				|| *(F + 2) == 'X')))
				char_count += ft_conv_x(F, valist);
			else if (*F == 'u' || (*F == 'h' && *(F + 1) == 'u') ||
				(*F == 'h' && *(F + 1) == 'h' && *(F + 2) == 'u'))
				char_count += ft_conv_u(F, valist);
			else
			{
				ft_putchar(*F);
				char_count += 2;
			}
			if (*F == 'h' && *(F + 1) == 'h')
				F += 3;
			else if (*F == 'h')
				F += 2;
			else
				F++;
		}
		else
		{
			ft_putchar(*F);
			F++;
			char_count++;
		}
	}
	va_end(valist);
	return (char_count);
}

int		main(void)
{
	char abc[] = "Hello Vladimir Putin from school";
	int ret_origin;
	int ret_mine;
	void *ptr;
	int	a;
	unsigned long long int d;
	char b;
	short c;

	a = 6000000;
	c = 33761;
	b = 'a';
	d = 1846744073709551615;
	ptr = &a;
	ret_origin = printf("Original       : %hhx\n", b);
	ret_mine = ft_printf("Mine           : %hhx\n", b);
	printf("Original return: %i\n", ret_origin);
	ft_printf("Mine return    : %i\n", ret_mine);

	return (0);
}
