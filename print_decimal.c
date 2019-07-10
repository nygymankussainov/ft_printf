/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 09:56:52 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/10 14:45:35 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_decimal_2(char *res, char *tmp, char *mant, int exp_i)
{
	char		*c;
	char		*tmptmp;
	int			i;
	int			j;
	int			k;

	tmptmp = ft_itoa(ft_power(5, 24));
	while (*mant)
	{
		tmptmp = longmulti(tmptmp, "5", c);
		if (*mant == '1')
		{
			i = 0;
			j = ft_strlen(tmptmp);
			k = 0;
			while (tmptmp[k])
			{
				while (j < -exp_i)
				{
					i++;
					j++;
				}
				tmp[i] = tmptmp[k];
				i++;
				k++;
			}
			res = longadd(res, tmp);
			ft_bzero(tmp, ft_strlen(tmp));
		}
		mant += 1;
		exp_i--;
	}
	return (res);
}

void	print_decimal(char *mant, int exp_i, short isint)
{
	char		*res;
	char		*tmp;
	long double	db;
	int			i;
	int			k;
	int			j;
	char		*restmp;
	char		*tmptmp;

	i = -exp_i;
	while (*mant != '\0')
	{
		i++;
		mant++;
	}
	while (*mant != '1')
	{
		i--;
		mant--;
	}
	res = (char *)ft_memalloc(sizeof(char) * (i + 1));
	res[i + 1] = '\0';
	tmp = (char *)ft_memalloc(sizeof(char) * (i + 1));
	tmp[i + 1] = '\0';
	mant = mant - (i + exp_i);
	if (isint)
	{
		while (*mant != '1')
		{
			mant++;
			exp_i--;
		}
		mant++;
	}
	restmp = ft_itoa(ft_power(5, -exp_i));
	i = 0;
	j = ft_strlen(restmp);
	while (*restmp)
	{
		while (j < -exp_i)
		{
			i++;
			j++;
		}
		res[i] = *restmp;
		i++;
		restmp++;
	}
	exp_i--;
	while (*mant && -exp_i <= 24)
	{
		if (*mant == '1')
		{
			i = 0;
			tmptmp = ft_itoa(ft_power(5, -exp_i));
			j = ft_strlen(tmptmp);
			while (*tmptmp)
			{
				while (j < -exp_i)
				{
					i++;
					j++;
				}
				tmp[i] = *tmptmp;
				i++;
				tmptmp++;
			}
			res = longadd(res, tmp);
			ft_bzero(tmp, ft_strlen(tmp));
		}
		mant += 1;
		exp_i--;
	}
	res = print_decimal_2(res, tmp, mant, exp_i);
	ft_putstr(res, 0);
	free(res);
	free(tmp);
}
