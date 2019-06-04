/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:01:49 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/04 11:28:00 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		digit_count(long long int nb, int base)
{
	int i;

	i = 0;
	while (nb /= base)
		i++;
	return (i + 1);
}

char			*ft_itoa_base(long long int nb, int base, char c)
{
	char	*str_base;
	char	*result;
	int		i;
	int		j;


	if (c == 'X')
		str_base = "0123456789ABCDEF";
	else
		str_base = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	j = 0;
	if (base == 16)
	{
		if (c == 'p')
		{
			j = 2;
			i = digit_count(nb, base) + j;
			result = (char *)ft_memalloc(sizeof(char) * i + 1);
			result[0] = '0';
			result[1] = 'x';
		}
		else if (c == 'x' || c == 'X')
		{
			i = digit_count(nb, base) + j;
			result = (char *)ft_memalloc(sizeof(char) * i + 1);
		}
	}
	if (base == 8 || base == 10)
	{
		i = digit_count(nb, base);
		result = (char *)ft_memalloc(sizeof(char) * i + 1);
	}
	result[i] = '\0';
	while (i - j > 0)
	{
		result[i - 1] = str_base[nb % base];
		nb /= base;
		i--;
	}
	return (result);
}
