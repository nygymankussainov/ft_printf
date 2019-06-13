/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:01:49 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/13 10:25:46 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_digit_count(long long nb, int base)
{
	int i;

	i = 0;
	while (nb /= base)
		i++;
	return (i + 1);
}

int				ft_get_result(char **result, long long nb, int base, char c)
{
	int		i;

	i = 0;
	if (base == 16)
	{
		if (c == 'p')
		{
			i = ft_digit_count(nb, base) + 2;
			*result = (char *)ft_memalloc(sizeof(char) * i + 1);
			*result[0] = '0';
			*result[1] = 'x';
		}
		else if (c == 'x' || c == 'X')
		{
			i = ft_digit_count(nb, base);
			*result = (char *)ft_memalloc(sizeof(char) * i + 1);
		}
	}
	else if (base == 8 || base == 10)
	{
		i = ft_digit_count(nb, base);
		*result = (char *)ft_memalloc(sizeof(char) * i + 1);
	}
	return (i);
}

char			*ft_itoa_base(long long nb, int base, char c)
{
	char	*str_base;
	char	*result;
	int		i;
	int		j;

	if (c == 'X')
		str_base = "0123456789ABCDEF";
	else
		str_base = "0123456789abcdef";
	j = 0;
	if (c == 'p')
		j = 2;
	i = ft_get_result(&result, nb, base, c);
	result[i] = '\0';
	while (i - j > 0)
	{
		result[i - 1] = str_base[nb % base];
		nb /= base;
		i--;
	}
	return (result);
}
