/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longmulti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:19:49 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/07 10:43:10 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*operation(const char *a, const char *b, char *c)
{
	int i;
	int j;
	int	k;
	int n;
	int carry;

	i = ft_strlen(a) - 1;
	while (i >= 0)
	{
		j = ft_strlen(b) - 1;
		k = i + j + 1;
		carry = 0;
		while (j >= 0)
		{
			n = (a[i] - '0') * (b[j] - '0') + (c[k] - '0') + carry;
			carry = n / 10;
			c[k] = (n % 10) + '0';
			j--;
			k--;
		}
		c[k] += carry;
		i--;
	}
	return (c);
}

char	*longmulti(const char *a, const char *b, char *c)
{
	int la;
	int lb;

	c = (char *)ft_memalloc(sizeof(char) * 1024);
	if (a[0] == '0' || b[0] == '0')
	{
		c[0] = '0';
		c[1] = '\0';
		return (c);
	}
	la = ft_strlen(a);
	lb = ft_strlen(b);
	c = ft_memset(c, '0', la + lb);
	c[la + lb] = '\0';
	c = operation(a, b, c);
	if (c[0] == '0')
		c = ft_memmove(c, c + 1, la + lb);
	return (c);
}
