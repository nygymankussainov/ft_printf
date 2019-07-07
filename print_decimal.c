/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 09:56:52 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/07 16:44:50 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_decimal_2(char *res, char **mant, int exp_i)
{
	char	*c;
	char	*tmp;
	char	*tmp1;

	tmp = ft_itoa(ft_power(5, 24));
	while (**mant)
	{
		tmp = longmulti(tmp, "5", c);
		if (**mant == '1')
		{
			tmp1 = (char *)ft_memalloc(sizeof(char) * (ft_strlen(tmp) + 1));
			tmp1[ft_strlen(tmp)] = '\0';
			tmp1 = ft_strcpy(tmp1, tmp);
			tmp1 = longmulti(tmp1, res, c);
			while (ft_strlen(tmp1) != ft_strlen(res))
			{
				if (ft_strlen(tmp1) > ft_strlen(res))
					res = ft_realloc(res, ft_strlen(res) + 1);
				else
					tmp1 = ft_realloc(tmp1, ft_strlen(tmp1) + 1);
			}
			res = longadd(tmp1, res);
		}
		*mant += 1;
		exp_i--;
	}
	return (res);
}

void	print_decimal(char **mant, int exp_i)
{
	char	*res;
	char	*tmp;
	double	db;
	int		i;

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
			if (ft_strlen(res) <= ft_strlen(tmp))
				while (ft_strlen(res) != (ft_strlen(tmp) + i - 1))
					res = ft_realloc(res, ft_strlen(res) + 1);
			else if (ft_strlen(res) > ft_strlen(tmp))
				while ((ft_strlen(tmp) + i - 1) != ft_strlen(res))
					res = ft_realloc(res, ft_strlen(res) + 1);
			res = longadd(res, tmp);
			*mant += 1;
		}
		exp_i--;
	}
	res = print_decimal_2(res, mant, exp_i);
	ft_putstr(res, 0);
}
