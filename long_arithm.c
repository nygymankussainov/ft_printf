/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:06:00 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/25 16:16:47 by vhazelnu         ###   ########.fr       */
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
	result = (char *)ft_memalloc(sizeof(char) * (l2));
	while (i <= l1)
	{
		if (s1[i] && s2[i])
			sum = ((s1[i] - '0') + (s2[i] - '0')) + rem;
		else
			sum = (s2[i] - '0') + rem;
		result[l2 - 1] = (sum % 10) + '0';
		rem = sum / 10;
		l2--;
		i++;
	}
	i = l1;
	while (i <= l2)
	{
		sum = (s2[i] - '0') + rem;
		result[l2 - 1] = (sum % 10) + '0';
		rem = rem / 10;
		i++;
		l2--;
	}
	if (rem)
		result[l2 - 1] = rem + '0';
	return (result);
}

void	long_arithm(char *s1, char *s2)
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
	ft_putstr(result, 0);
	free(result);
	result = NULL;
}

int		main(void)
{
	char *s1;
	char *s2;

	s2 = (char *)ft_memalloc(sizeof(char) * 4);
	s1 = (char *)ft_memalloc(sizeof(char) * 5);
	// s1[0] = '1';
	// s1[1] = '2';
	// s1[2] = '3';
	// s1[3] = '\0';
	
	// s2[0] = '1';
	// s2[1] = '2';
	// s2[2] = '3';
	// s2[3] = '4';
	// s2[4] = '\0';

	s1[0] = '1';
	s1[1] = '2';
	s1[2] = '3';
	s1[3] = '4';
	s1[4] = '\0';
	
	s2[0] = '1';
	s2[1] = '2';
	s2[2] = '3';
	s2[3] = '\0';
	long_arithm(s1, s2);
	free(s1);
	free(s2);
	return (0);
}
