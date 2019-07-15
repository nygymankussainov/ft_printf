/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:12:15 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/15 14:51:26 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_binary_bigl(long double db, char **str, char **exp, char **mant)
{
	__int128_t	nb;
	int			j;
	int			i;

	j = 127;
	(*str)[80] = '\0';
	i = 0;
	ft_memcpy(&nb, &db, 16);
	while (j >= 0)
	{
		(*str)[i] = ((nb & ((__int128_t)1 << j)) >> j) + '0';
		j--;
		i++;
	}
	// printf("str_i: %d\n %s\n", ft_strlen(*str), *str);
	*exp = ft_strncpy(*exp, *str + 49, 15);
	(*exp)[15] = '\0';
	*mant = ft_strncpy(*mant, *str + 64, 63);
	(*mant)[63] = '\0';
	// printf("exp_i: %d\n %s\n", ft_strlen(*exp), *exp);
	// printf("mant_i: %d\n %s\n", ft_strlen(*mant), *mant);
}

void	get_binary(double db, char **str, char **exp, char **mant)
{
	__int64_t	nb;
	int			j;
	int			i;

	j = 63;
	(*str)[64] = '\0';
	i = 0;
	ft_memcpy(&nb, &db, 8);
	while (j >= 0)
	{
		(*str)[i] = ((nb & ((__int64_t)1 << j)) >> j) + '0';
		j--;
		i++;
	}
	*exp = ft_strncpy(*exp, *str + 1, 11);
	(*exp)[11] = '\0';
	*mant = ft_strncpy(*mant, *str + 12, 52);
	(*mant)[52] = '\0';
}

int		print_integer(int exp_i, char **mant)
{
	char	*res;
	char	*tmp;
	char	*tmpres;
	int		i;

	i = 63;
	if (exp_i >= 64)
	{
		res = ft_itoa(ft_power(2, i));
		while (i++ < exp_i)
			res = longmulti(res, "2", res);
		i = 63;
		tmpres = ft_itoa(ft_power(2, i));
		while (i++ < exp_i)
			tmpres = longmulti(tmpres, "2", tmpres);
		exp_i--;
		while (**mant && exp_i >= 0)
		{
			tmp = longdiv(tmpres, 2);
			tmpres = longdiv(tmpres, 2);
			if (**mant == '1')
				res = longadd(res, tmp);
			*mant += 1;
			exp_i--;
		}
	}
	else
	{
		res = ft_itoa(ft_power(2, exp_i));
		exp_i--;
		while (**mant && exp_i >= 0)
		{
			if (**mant == '1')
			{
				tmp = ft_itoa(ft_power(2, exp_i));
				res = longadd(res, tmp);
			}
			*mant += 1;
			exp_i--;
		}
	}
	ft_putstr(res, 0);
	write(1, ".", 1);
	return (exp_i);
}

int		ft_conv_f(const char **format, va_list valist, t_printf s)
{
	int			ret;
	t_f			f;

	ret = 0;
	if (!s.bigl)
	{
		f.db = (long double)va_arg(valist, double);
		if (!(f.binary = (char *)ft_memalloc(sizeof(char) + 65)))
			return (0);
		if (!(f.exp = (char *)ft_memalloc(sizeof(char) * 12)))
			return (0);
		if (!(f.mant = (char *)ft_memalloc(sizeof(char) * 53)))
			return (0);
		get_binary(f.db, &f.binary, &f.exp, &f.mant);
		free(f.binary);
		f.exp_i = ft_atoi_base(f.exp, 2) - 1023;
	}
	else
	{
		f.longdb = (long double)va_arg(valist, long double);
		if (!(f.binary = (char *)ft_memalloc(sizeof(char) + 81)))
			return (0);
		if (!(f.exp = (char *)ft_memalloc(sizeof(char) * 16)))
			return (0);
		if (!(f.mant = (char *)ft_memalloc(sizeof(char) * 64)))
			return (0);
		get_binary_bigl(f.longdb, &f.binary, &f.exp, &f.mant);
		free(f.binary);
		f.exp_i = ft_atoi_base(f.exp, 2) - 16383;
	}
	if (f.exp_i < 0)
		write(1, "0.", 2);
	else
		f.exp_i = print_integer(f.exp_i, &f.mant);
	f.isint = f.exp_i >= 0 ? 1 : 0;
	print_decimal(f.mant, f.exp_i, f.isint);
	*F += 1;
	free(f.exp);
	/* free(f.mant); - fix this (!) */
	return (ret);
}
