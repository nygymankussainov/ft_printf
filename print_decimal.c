/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 09:56:52 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/08 13:43:39 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_decimal_2(char *res, char **mant, int exp_i)
{
	char		*c;
	char		*tmp;
	char		*tmp1;
	int			i;
	long double	db;
	int			j;
	int			k;

	tmp = ft_itoa(ft_power(5, 24));
	while (**mant)
	{
		tmp = longmulti(tmp, "5", c);
		if (**mant == '1')
		{
			i = 0;
			db = ft_power_db(2, exp_i);
			while (!(int)db)
			{
				db *= 10;
				i++;
			}
			j = ft_strlen(tmp);
			k = ft_strlen(res);
			if (!(tmp1 = (char *)ft_memalloc(sizeof(char) * (j + 1))))
				return (NULL);
			tmp1[j] = '\0';
			tmp1 = ft_strcpy(tmp1, tmp);
			if (k <= j)
				while (k != (j + i - 1))
				{
					res = ft_realloc(res, k + 1);
					k++;
				}
			else if (k > j)
				while ((j + i - 1) != k)
				{
					res = ft_realloc(res, k + 1);
					k++;
				}
			res = longadd(res, tmp1);
			free(tmp1);
		}
		*mant += 1;
		exp_i--;
	}
	return (res);
}

void	print_decimal(char **mant, int exp_i)
{
	char		*res;
	char		*tmp;
	long double	db;
	int			i;
	int			j;
	int			k;

	res = ft_itoa(ft_power(5, -exp_i));
	exp_i--;
	while (**mant && -exp_i <= 24)
	{
		if (**mant == '0')
			*mant += 1;
		else if (**mant == '1')
		{
			i = 0;
			db = ft_power_db(2, exp_i);
			while (!(int)db)
			{
				db *= 10;
				i++;
			}
			tmp = ft_itoa(ft_power(5, -exp_i));
			j = ft_strlen(tmp);
			k = ft_strlen(res);
			if (k <= j)
				while (k != (j + i - 1))
				{
					res = ft_realloc(res, k + 1);
					k++;
				}
			else if (k > j)
				while ((j + i - 1) != k)
				{
					res = ft_realloc(res, k + 1);
					k++;
				}
			res = longadd(res, tmp);
			*mant += 1;
		}
		exp_i--;
	}
	res = print_decimal_2(res, mant, exp_i);
	ft_putstr(res, 0);
}
