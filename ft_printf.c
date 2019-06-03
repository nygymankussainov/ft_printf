/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:06:11 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/03 15:40:51 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_integer(const char *F, va_list valist)
{
	int						char_count;
	char					*integer_string;
	void					*ptr;
	unsigned long long int	nbr;

	char_count = 0;
	if (*F == 'i' || *F == 'd' ||
		(*F == 'h' && (*(F + 1) == 'd' || (*(F + 1) == 'i'))))
	{
		if (*F == 'h' && (*(F + 1) == 'd' || (*(F + 1) == 'i')))
			nbr = (short)va_arg(valist, int);
		else
			nbr = va_arg(valist, int);
		integer_string = ft_itoa(nbr);
	}
	else if (*F == 'p')
	{
		ptr = va_arg(valist, void *);
		integer_string = ft_itoa_base((long long int)ptr, 16, 'p');
	}
	else if (*F == 'o' || *F == 'x' || *F == 'X'
		|| *F == 'u' || (*F == 'h' && *(F + 1) == 'o'))
	{
		if (*F == 'h')
			nbr = (unsigned short)va_arg(valist, unsigned int);
		else
			nbr = va_arg(valist, unsigned int);
		if (*F == 'o' || (*F == 'h' && *(F + 1) == 'o'))
			integer_string = ft_itoa_base(nbr, 8, 'o');
		else if (*F == 'u')
			integer_string = ft_itoa_base(nbr, 10, 'u');
		else if (*F == 'x')
			integer_string = ft_itoa_base(nbr, 16, 'x');
		else
			integer_string = ft_itoa_base(nbr, 16, 'X');
	}
	ft_putstr(integer_string);
	char_count += ft_strlen(integer_string);
	return (char_count);
}

int		ft_string(const char *F, va_list valist)
{
	char	*char_string;
	char	sym;
	int		char_count;

	char_count = 0;
	if (*F == 's')
	{
		char_string = va_arg(valist, char *);
		ft_putstr(char_string);
		char_count += ft_strlen(char_string);
	}
	else if (*F == 'c' || (*F == 'h' && *(F + 1) == 'h' &&
		(*(F + 2) == 'd' || (*(F + 2) == 'i'))))
	{
		sym = (char)va_arg(valist, int);
		if (*F == 'c')
		{
			ft_putchar(sym);
			char_count++;
		}
		else
		{
			ft_putnbr(sym);
			char_count = ft_count_digit(sym, 1);
		}
	}
	else if (*F == '%')
	{
		ft_putchar('%');
		char_count++;
	}
	return (char_count);
}

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
