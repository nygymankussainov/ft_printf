/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:12:15 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/17 16:36:28 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_binary_bigl(long double db, char *str, char **exp, char **mant)
{
	__int128_t	nb;
	int			j;
	int			i;

	j = 127;
	if (!(str = (char *)ft_memalloc(sizeof(char) + 129)))
		return (0);
	str[128] = '\0';
	i = 0;
	ft_memcpy(&nb, &db, 16);
	while (j >= 0)
	{
		str[i] = ((nb & ((__int128_t)1 << j)) >> j) + '0';
		j--;
		i++;
	}
	if (str[48] == '1')
		write(1, "-", 1);
	*exp = ft_strncpy(*exp, str + 49, 15);
	(*exp)[15] = '\0';
	*mant = ft_strncpy(*mant, str + 64, 63);
	(*mant)[63] = '\0';
	free(str);
	return (ft_atoi_base(*exp, 2) - 16383);
}

int		get_binary(double db, char *str, char **exp, char **mant)
{
	__int64_t	nb;
	int			j;
	int			i;

	j = 63;
	if (!(str = (char *)ft_memalloc(sizeof(char) + 65)))
		return (0);
	str[64] = '\0';
	i = 0;
	ft_memcpy(&nb, &db, 8);
	while (j >= 0)
	{
		str[i] = ((nb & ((__int64_t)1 << j)) >> j) + '0';
		j--;
		i++;
	}
	if (str[0] != '0')
		write(1, "-", 1);
	*exp = ft_strncpy(*exp, str + 1, 11);
	(*exp)[11] = '\0';
	*mant = ft_strncpy(*mant, str + 12, 52);
	(*mant)[52] = '\0';
	free(str);
	return (ft_atoi_base(*exp, 2) - 1023);
}

int		ft_conv_f(const char **format, va_list valist, short bigl)
{
	int			ret;
	t_f			f;

	f.db = bigl ? va_arg(valist, long double) :
		(double)va_arg(valist, double);
	if (bigl)
	{
		if (!(f.exp = (char *)ft_memalloc(sizeof(char) * 16)) ||
			!(f.mant = (char *)ft_memalloc(sizeof(char) * 64)))
			return (0);
		f.exp_i = get_binary_bigl(f.db, f.binary, &f.exp, &f.mant);
	}
	else
	{
		if (!(f.exp = (char *)ft_memalloc(sizeof(char) * 12)) ||
			!(f.mant = (char *)ft_memalloc(sizeof(char) * 53)))
			return (0);
		f.exp_i = get_binary(f.db, f.binary, &f.exp, &f.mant);
	}
	f.isint = f.exp_i >= 0 ? 1 : 0;
	ret = print_integer(f.exp_i, f.mant, f.isint);
	*F += 1;
	free(f.exp);
	free(f.mant);
	return (ret);
}
