/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:28:59 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/28 18:31:26 by vhazelnu         ###   ########.fr       */
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

void	big_int(char **mant, int *exp_i, char **res)
{
	char	*tmp;

	if (!(*res = (char *)ft_memalloc(sizeof(char) * 16382)))
		return ;
	get_big_number(res, *exp_i);
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * (ft_strlen(*res) + 1))))
		return ;
	get_big_number(&tmp, (*exp_i)--);
	while (**mant && *exp_i >= 0)
	{
		longdiv(tmp, 2, &tmp);
		if (**mant == '1')
			longadd(*res, tmp, res);
		(*mant)++;
		(*exp_i)--;
	}
	free(tmp);
}

void	small_int(char **mant, int *exp_i, char **res)
{
	char	*nb1;
	char	*nb2;

	*res = ft_itoa(ft_power(2, (*exp_i)--));
	while (**mant && *exp_i >= 0)
	{
		if (**mant == '1')
		{
			if (!(nb1 = (char *)ft_memalloc(ft_strlen(*res) + 1)))
				return ;
			nb1 = ft_strcpy(nb1, *res);
			nb2 = ft_itoa(ft_power(2, *exp_i));
			longadd(nb1, nb2, res);
			free(nb1);
			free(nb2);
		}
		(*mant)++;
		(*exp_i)--;
	}
}

int		integer_part(t_f f, t_printf s, int sign)
{
	int		i;
	int		ret;
	char	*res;

	if (f.exp_i < 0)
	{
		res = ft_strnew(2);
		res[0] = '0';
		ret = decimal_part(&res, f, s, sign) + 1;
	}
	else
	{
		f.exp_i >= 64 ? big_int(&f.mant, &f.exp_i, &res) :
			small_int(&f.mant, &f.exp_i, &res);
		ret = decimal_part(&res, f, s, sign);
	}
	return (ret);
}
