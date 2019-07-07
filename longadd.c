/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:17:57 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/06 14:14:51 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*column_add(char *s1, char *s2, int l1, int l2)
{
	int		i;
	int		rem;
	int		sum;
	char	*result;

	i = 0;
	rem = 0;
	if (!(result = (char *)ft_memalloc(sizeof(char) * (l2 + 1))))
		return (NULL);
    result[l2] = '\0';
	while (i < l1)
	{
		sum = ((s1[i] - '0') + (s2[i] - '0')) + rem;
		result[i] = (sum % 10) + '0';
		rem = sum / 10;
		i++;
	}
	// i = l1;
	// while (i < l2)
	// {
	// 	sum = (s2[i] - '0') + rem;
	// 	result[i] = (sum % 10) + '0';
	// 	rem = rem / 10;
	// 	i++;
	// }
	if (rem)
	{
		result = ft_realloc(result, l2 + 1);
		result[l2] = rem + '0';
	}
	return (result);
}

char	*longadd(char *s1, char *s2)
{
	int		l1;
	int		l2;
	char	*result;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	// if (l1 > l2)
	// {
	// 	ft_swap_str(&s1, &s2);
	// 	ft_swap(&l1, &l2);
	// }
	ft_revstr(s1);
	ft_revstr(s2);
	result = column_add(s1, s2, l1, l2);
	ft_revstr(result);
	return (result);
}
