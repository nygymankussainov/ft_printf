/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:54:57 by nygymankuss       #+#    #+#             */
/*   Updated: 2019/07/23 20:49:34 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_length(char *mant, int exp_i)
{
	int		i;
	int		j;

	i = -exp_i;
	j = 0;
	while (*mant)
	{
		if (*mant == '1')
		{
			j = i;
			if (*(mant + 1) == '\0')
				j++;
		}
		i++;
		mant++;
	}
	if (j == -exp_i)
		return (j);
	else if (j == 0)
		return (-exp_i);
	return (j + 1);
}

void	put_zeroes(char *n1, char **res, int exp_i)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(n1);
	while (*n1)
	{
		while (j < -exp_i)
		{
			i++;
			j++;
		}
		(*res)[i] = *n1;
		i++;
		n1++;
	}
}

char	*get_initial_number(int len, int exp_i, char **n1)
{
	int		i;
	char	*res;
	char	*n2;

	if (!(res = (char *)ft_memalloc(sizeof(char) * (len + 1))) ||
		!(*n1 = (char *)ft_memalloc(sizeof(char) * 16382)))
		return (0);
	ft_bzero(res, len);
	i = 1;
	n2 = ft_itoa(ft_power(5, 0));
	longmulti(n2, "5", n1);
	free(n2);
	while (i++ < -exp_i)
	{
		if (!(n2 = (char *)ft_memalloc(sizeof(char) * ft_strlen(*n1) + 1)))
			return (NULL);
		n2 = ft_strcpy(n2, *n1);
		longmulti(n2, "5", n1);
		free(n2);
	}
	put_zeroes(*n1, &res, exp_i);
	return (res);
}

void	get_ret(char *mant, char **res, int exp_i, char **n1)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*res);
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return ;
	ft_bzero(tmp, len);
	while (*mant)
	{
		longmulti(*n1, "5", n1);
		if (*mant == '1')
		{
			put_zeroes(*n1, &tmp, exp_i);
			longadd(*res, tmp, res);
			ft_bzero(tmp, len);
		}
		mant++;
		exp_i--;
	}
	free(*n1);
	free(tmp);
}

int		iszeroes(char *mant)
{
	while (*mant)
	{
		if (*mant != '0')
			return (0);
		mant++;
	}
	return (1);
}

int		decimal_part(char **integer, t_f f, t_printf *s, int sign)
{
	int		len;
	char	*res;
	char	*n1;

	if (!*f.mant || iszeroes(f.mant))
	{
		res = ft_strnew(0);
		return (print(&res, integer, s, sign));
	}
	len = get_length(f.mant, f.exp_i);
	if (f.isint && *f.mant)
	{
		while (*f.mant != '1')
		{
			f.mant++;
			f.exp_i--;
		}
		f.mant++;
	}
	res = get_initial_number(len, f.exp_i, &n1);
	f.exp_i--;
	f.mant = s->bigl ? f.mant + 1 : f.mant;
	get_ret(f.mant, &res, f.exp_i, &n1);
	return (print(&res, integer, s, sign));
}
