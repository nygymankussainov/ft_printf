/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding_and_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:18:47 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/28 20:23:41 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ifnine(char **decimal, char **integer, int prec)
{
	while ((*decimal)[prec] == '9')
		(*decimal)[prec--] = '0';
	if (prec >= 0)
		(*decimal)[prec]++;
	else
		longadd(*integer, "1", integer);
	return (prec);
}

void	rounding(char **decimal, char **integer, int prec)
{
	int		tmp;
	int		i;

	tmp = prec;
	if ((*decimal)[prec] >= '5' && prec > 0)
	{
		if ((*decimal)[tmp] == '9')
			tmp = ifnine(decimal, integer, tmp);
		else if ((*decimal)[tmp - 1] == '9')
			tmp = ifnine(decimal, integer, tmp - 1);
		else if ((*decimal)[tmp] < '9' && prec > 0)
		{
			i = tmp == prec ? 1 : 0;
			if (!(*decimal)[tmp + i])
				(*decimal)[tmp - i]--;
			else
				(*decimal)[tmp - i]++;
		}
	}
	else if (prec == 0 && (*decimal)[prec])
	{
		if ((*decimal)[prec] > '5')
			longadd(*integer, "1", integer);
		// else if ((*decimal)[prec] == '5')
		// 	if ((*decimal)[prec + 1])
		// 		longadd(*integer, "1", integer);
	}
	(*decimal)[prec] = '\0';
}

int		print(char **decimal, char **integer, t_printf s, int sign)
{
	int		ret;
	char	*res;

	ret = s.signflag > 0 && sign >= 0 ? 1 : 0;
	rounding(decimal, integer, s.prec);
	if (s.prec || s.hash)
		*integer = ft_strjoin(*integer, ".", 1, 0);
	res = ft_strjoin(*integer, *decimal, 1, 0);
	res = sign < 0 ? ft_strjoin("-", res, 0, 1) : res;
	ret += ft_strlen(res);
	if (s.width)
		ret = width(res, s, ret);
	else
	{
		if (s.signflag > 0 && sign >= 0)
			write(1, "+", 1);
		ft_putstr(res, 0);
	}
	if (s.prec && (!(*decimal)[s.prec] || !**decimal))
	{
		s.prec = s.prec - ft_strlen(*decimal);
		ret += s.prec > 0 ? s.prec : 0;
		while (s.prec--)
			write(1, "0", 1);
	}
	free(*decimal);
	free(res);
	return (ret);
}
