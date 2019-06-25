/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:06:00 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/25 20:01:10 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*column_add(char *s1, char *s2, int l1, int l2)
{
	int		i;
	int		j;
	int		rem;
	int		sum;
	char	*result;

	i = 0;
	rem = 0;
	j = l2;
	result = (char *)ft_memalloc(sizeof(char) * (l2 + 2));
	result[0] = '.';
	while (i < l1)
	{
		sum = ((s1[i] - '0') + (s2[i] - '0')) + rem;
		result[l2] = (sum % 10) + '0';
		rem = sum / 10;
		i++;
		l2--;
	}
	i = l1;
	l2 = j;
	while (i < j)
	{
		sum = (s2[i] - '0') + rem;
		result[l2] = (sum % 10) + '0';
		rem = rem / 10;
		i++;
		l2--;
	}
	if (rem)
		result[l2] = rem + '0';
	if (result[0] == '.')
		result += 1;
	return (result);
}

char	*long_arithm(char *s1, char *s2)
{
	int		l1;
	int		l2;
	char	*result;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 > l2)
	{
		ft_swap_str(&s1, &s2);
		ft_swap(&l1, &l2);
	}
	ft_revstr(s1);
	ft_revstr(s2);
	result = column_add(s1, s2, l1, l2);
	return (result);
}
