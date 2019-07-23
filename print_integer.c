/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:28:59 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/18 19:07:26 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_big_number(char **res, int exp_i)
{
	int		i;
	char	*s1;

	i = 64;
	s1 = ft_itoa(ft_power(2, i - 1));
	longmulti(s1, "2", res);
	free(s1);
	while (i++ < exp_i)
	{
		if (!(s1 = (char *)ft_memalloc(sizeof(char) * (ft_strlen(*res) + 1))))
			return ;
		s1 = ft_strcpy(s1, *res);
		longmulti(s1, "2", res);
		free(s1);
	}
}

int		big_int(char **mant, int *exp_i)
{
	int		ret;
	char	*tmp;
	char	*res;

	if (!(res = (char *)ft_memalloc(sizeof(char) * 16382)))
		return (0);
	get_big_number(&res, *exp_i);
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * (ft_strlen(res) + 1))))
		return (0);
	get_big_number(&tmp, (*exp_i)--);
	while (**mant && *exp_i >= 0)
	{
		longdiv(tmp, 2, &tmp);
		if (**mant == '1')
			longadd(res, tmp, &res);
		(*mant)++;
		(*exp_i)--;
	}
	ft_putstr(res, 0);
	ret = ft_strlen(res);
	free(res);
	free(tmp);
	return (ret);
}

int		small_int(char **mant, int *exp_i)
{
	int		ret;
	char	*res;
	char	*nb1;
	char	*nb2;

	res = ft_itoa(ft_power(2, (*exp_i)--));
	while (**mant && *exp_i >= 0)
	{
		if (**mant == '1')
		{
			if (!(nb1 = (char *)ft_memalloc(ft_strlen(res) + 1)))
				return (0);
			nb1 = ft_strcpy(nb1, res);
			nb2 = ft_itoa(ft_power(2, *exp_i));
			longadd(nb1, nb2, &res);
			free(nb1);
			free(nb2);
		}
		(*mant)++;
		(*exp_i)--;
	}
	ft_putstr(res, 0);
	ret = ft_strlen(res);
	free(res);
	return (ret);
}

int		print_integer(int exp_i, char *mant, short isint)
{
	int		i;
	int		ret;

	if (exp_i < 0)
	{
		write(1, "0.", 2);
		return (print_decimal(mant, exp_i, isint));
	}
	ret = exp_i >= 64 ? big_int(&mant, &exp_i) :
		small_int(&mant, &exp_i);
	write(1, ".", 1);
	ret += print_decimal(mant, exp_i, isint);
	return (ret);
}
