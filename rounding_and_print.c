/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding_and_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:18:47 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/30 16:56:09 by vhazelnu         ###   ########.fr       */
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
	}
	(*decimal)[prec] = '\0';
}

int		print(char **decimal, char **integer, t_flags *s, int sign)
{
	int		ret;
	char	*res;

	s->pos = sign < 0 ? 0 : s->pos;
	ret = s->pos && sign >= 0 ? 1 : 0;
	rounding(decimal, integer, s->prec);
	if (s->prec || s->hash)
		*integer = ft_strjoin(*integer, ".", 1, 0);
	res = ft_strjoin(*integer, *decimal, 1, 0);
	if ((sign < 0 && !s->width) || (sign < 0 && s->width && s->zero))
	{
		write(1, "-", 1);
		ret++;
	}
	else
		res = sign < 0 ? ft_strjoin("-", res, 0, 1) : res;
	ret += ft_strlen(res);
	if (s->prec && (!(*decimal)[s->prec] || !**decimal))
	{
		s->prec = s->prec - ft_strlen(*decimal);
		ret += s->prec > 0 ? s->prec : 0;
		while (s->prec--)
			res = ft_strjoin(res, "0", 1, 0);
	}
	if (s->whitesp && sign >= 0 && !s->pos)
	{
		ft_putchar(' ');
		ret++;
	}
	if (s->width)
		ret = width(res, s, ret);
	else
	{
		if (s->pos && sign >= 0)
			write(1, "+", 1);
		ft_putstr(res);
	}
	free(*decimal);
	free(res);
	return (ret);
}
