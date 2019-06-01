/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:06:11 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/01 14:16:04 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		integer(const char *format, va_list valist)
{
	int				char_count;
	int				nbr;
	char			*integer_string;
	void			*ptr;
	unsigned int	u_nbr;

	char_count = 0;
	if (*format == 'i')
	{
		nbr = va_arg(valist, int);
		integer_string = ft_itoa(nbr);
	}
	else if (*format == 'p')
	{
		ptr = va_arg(valist, void *);
		integer_string = ft_itoa_base((long long int)ptr, 16);
	}
	else if (*format == 'o')
	{
		u_nbr = va_arg(valist, unsigned int);
		integer_string = ft_itoa_base(u_nbr, 8);
	}
	ft_putstr(integer_string);
	char_count += ft_strlen(integer_string);
	return (char_count);
}

int		string(const char *format, va_list valist)
{
	char	*char_string;
	char	sym;
	int		char_count;

	char_count = 0;
	if (*format == 's')
	{
		char_string = va_arg(valist, char *);
		ft_putstr(char_string);
		char_count += ft_strlen(char_string);
	}
	else if (*format == 'c')
	{
		sym = (char)va_arg(valist, int);
		ft_putchar(sym);
		char_count++;
	}
	else if (*format == '%')
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

	va_start(valist, format);
	char_count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's' || *format == 'c' || *format == '%')
			{
				char_count += string(format, valist);
				format++;
			}
			else if (*format == 'i' || *format == 'p' || *format == 'o')
			{
				char_count += integer(format, valist);
				format++;
			}
			else
			{
				ft_putchar(*format);
				format++;
				char_count += 2;
			}
		}
		else
		{
			ft_putchar(*format);
			format++;
			char_count++;
		}
	}
	va_end(valist);
	return (char_count);
}

int		main(void)
{
	// char abc[] = "Hello Vladimir Putin from school";
	int ret_origin;
	int ret_mine;
	void *ptr;
	int	a;

	a = 10;
	ptr = &a;
	ret_origin = printf("Original       : %x\n", a);
	ret_mine = ft_printf("Mine           : %o\n", a);
	printf("Original return: %i\n", ret_origin);
	ft_printf("Mine return    : %i\n", ret_mine);
	return (0);
}
