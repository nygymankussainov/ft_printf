/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:06:11 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/02 11:06:48 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_integer(const char *format, va_list valist)
{
	int				char_count;
	int				nbr;
	char			*integer_string;
	void			*ptr;
	unsigned int	u_nbr;

	char_count = 0;
	if (*format == 'i' || *format == 'd' ||
		(*format == 'h' && (*(format + 1) == 'd' || (*(format + 1) == 'i'))))
	{
		if (*format == 'h' && (*(format + 1) == 'd' || (*(format + 1) == 'i')))
			nbr = (short)va_arg(valist, int);
		else
			nbr = va_arg(valist, int);
		integer_string = ft_itoa(nbr);
	}
	else if (*format == 'p')
	{
		ptr = va_arg(valist, void *);
		integer_string = ft_itoa_base((long long int)ptr, 16, 'p');
	}
	else if (*format == 'o' || *format == 'x' || *format == 'X'
		|| *format == 'u')
	{
		u_nbr = va_arg(valist, unsigned int);
		if (*format == 'o')
			integer_string = ft_itoa_base(u_nbr, 8, 'o');
		else if (*format == 'u')
			integer_string = ft_itoa_base(u_nbr, 10, 'u');
		else if (*format == 'x')
			integer_string = ft_itoa_base(u_nbr, 16, 'x');
		else
			integer_string = ft_itoa_base(u_nbr, 16, 'X');
	}
	ft_putstr(integer_string);
	char_count += ft_strlen(integer_string);
	return (char_count);
}

int		ft_string(const char *format, va_list valist)
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
	else if (*format == 'c' || (*format == 'h' && *(format + 1) == 'h' &&
		(*(format + 2) == 'd' || (*(format + 2) == 'i'))))
	{
		sym = (char)va_arg(valist, int);
		if (*format == 'c')
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
			if (*format == 's' || *format == 'c' || *format == '%' ||
				(*format == 'h' && *(format + 1) == 'h' &&
				(*(format + 2) == 'd' || (*(format + 2) == 'i'))))
			{
				char_count += ft_string(format, valist);
				if (*format == 'h' && *(format + 1) == 'h' &&
					(*(format + 2) == 'd' || (*(format + 2) == 'i')))
					format += 3;
				else
					format++;
			}
			else if (*format == 'i' || *format == 'p' || *format == 'o'
				|| *format == 'x' || *format == 'X' || *format == 'u'
				|| *format == 'd' || (*format == 'h' &&
				(*(format + 1) == 'd' || (*(format + 1) == 'i'))))
			{
				char_count += ft_integer(format, valist);
				if (*format == 'h' &&
					(*(format + 1) == 'd' || (*(format + 1) == 'i')))
					format += 2;
				else
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
	char b;
	short c;

	a = 6000000;
	c = 32761;
	b = '\0';
	ptr = &a;
	ret_origin = printf("Original       : %hhi\n", b);
	ret_mine = ft_printf("Mine           : %hhi\n", b);
	printf("Original return: %i\n", ret_origin);
	ft_printf("Mine return    : %i\n", ret_mine);

	return (0);
}
