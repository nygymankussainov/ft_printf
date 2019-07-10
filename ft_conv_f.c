/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:12:15 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/10 14:50:02 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_binary(double db)
{
	__int64_t	nb;
	int			j;
	int			i;
	char		*str;

	j = 63;
	str = (char *)ft_memalloc(sizeof(char) * 65);
	str[64] = '\0';
	i = 0;
	ft_memcpy(&nb, &db, 8);
	while (j >= 0)
	{
		str[i] = ((nb & ((__int64_t)1 << j)) >> j) + '0';
		j--;
		i++;
	}
	return (str);
}

int		get_exp(char *binary, char *exp, int exp_i)
{
	if (!(exp = (char *)ft_memalloc(sizeof(char) * 12)))
		return (0);
	exp = ft_strncpy(exp, binary + 1, 11);
	exp[11] = '\0';
	exp_i = ft_atoi_base(exp, 2) - 1023;
	return (exp_i);
}

int		print_integer_2(int exp_i, char **mant)
{
	char	*res;
	char	*tmp;

	res = ft_itoa(ft_power(2, exp_i));
	exp_i--;
	while (exp_i >= 0)
	{
		if (**mant == '1')
		{
			tmp = ft_itoa(ft_power(2, exp_i));
			res = longadd(res, tmp);
		}
		*mant += 1;
		exp_i--;
	}
	ft_putstr(res, 0);
	write(1, ".", 1);
	return (exp_i);
}

int		print_integer(char *binary, char *exp, int exp_i, char **mant)
{
	char	*res;

	*mant = ft_strncpy(*mant, binary + 12, 52);
	if (exp_i < 0)
		write(1, "0.", 2);
	else
		exp_i = print_integer_2(exp_i, mant);
	return (exp_i);
}

int		ft_conv_f(const char **format, va_list valist, t_printf s)
{
	int			ret;
	char		*str;
	t_f			f;
	int			sign;

	ret = 0;
	f.db = (long double)va_arg(valist, double);
	sign = f.db < 0 ? 1 : 0;
	f.binary = sign ? get_binary(-f.db) : get_binary(f.db);
	if (!(f.mant = (char *)ft_memalloc(sizeof(char) * 53)))
		return (0);
	f.mant[52] = '\0';
	f.exp_i = get_exp(f.binary, f.exp, f.exp_i);
	f.isint = f.exp_i >= 0 ? 1 : 0;
	f.exp_i = print_integer(f.binary, f.exp, f.exp_i, &f.mant);
	print_decimal(f.mant, f.exp_i, f.isint);
	*F += 1;
	return (ret);
}
