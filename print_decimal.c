/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 09:56:52 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/18 18:52:53 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_decimal_2(char *res, char *tmp, char *mant, int exp_i)
{
	char		*n2;
	int			i;
	int			j;
	int			k;

	n2 = ft_itoa(ft_power(5, 24));
	while (*mant)
	{
		longmulti(n2, "5", &n2);
		if (*mant == '1')
		{
			i = 0;
			j = ft_strlen(n2);
			k = 0;
			while (n2[k])
			{
				while (j < -exp_i)
				{
					i++;
					j++;
				}
				tmp[i] = n2[k];
				i++;
				k++;
			}
			longadd(res, tmp, &res);
			ft_bzero(tmp, ft_strlen(tmp));
		}
		mant += 1;
		exp_i--;
	}
	return (res);
}

int		print_decimal(char *mant, int exp_i, short isint)
{
	char		*res;
	char		*tmp;
	int			i;
	int			j;
	char		*n1;
	char		*n2;

	i = -exp_i;
	if (!*mant)
	{
		write(1, "0", 1);
		return (1);
	}
	while (*mant)
	{
		i++;
		mant++;
	}
	while (*mant != '1' && i + exp_i)
	{
		i--;
		mant--;
	}
	if (!(res = (char *)ft_memalloc(sizeof(char) * (i + 1))) ||
		!(tmp = (char *)ft_memalloc(sizeof(char) * (i + 1))))
		return (0);
	ft_bzero(res, i);
	ft_bzero(tmp, i);
	mant = mant - (i + exp_i);
	if (isint && *mant)
	{
		while (*mant != '1')
		{
			mant++;
			exp_i--;
		}
		mant++;
	}
	if (-exp_i > 27)
	{
		i = 27;
		n1 = ft_itoa(ft_power(5, 27));
		while (-exp_i > i)
		{
			longmulti(n1, "5", &n1);
			i++;
		}
		i = 0;
		j = ft_strlen(n1);
		while (*n1)
		{
			while (j < -exp_i)
			{
				i++;
				j++;
			}
			res[i] = *n1;
			i++;
			n1++;
		}
		exp_i--;
	}
	else
	{
		n1 = ft_itoa(ft_power(5, -exp_i));
		i = 0;
		j = ft_strlen(n1);
		while (*n1)
		{
			while (j < -exp_i)
			{
				i++;
				j++;
			}
			res[i] = *n1;
			i++;
			n1++;
		}
		exp_i--;
		while (*mant && -exp_i <= 24)
		{
			if (*mant == '1')
			{
				i = 0;
				n2 = ft_itoa(ft_power(5, -exp_i));
				j = ft_strlen(n2);
				while (*n2)
				{
					while (j < -exp_i)
					{
						i++;
						j++;
					}
					tmp[i] = *n2;
					i++;
					n2++;
				}
				longadd(res, tmp, &res);
				ft_bzero(tmp, ft_strlen(tmp));
			}
			mant += 1;
			exp_i--;
		}
	}
	res = print_decimal_2(res, tmp, mant, exp_i);
	ft_putstr(res, 0);
	free(res);
	free(tmp);
	return (0);
}
