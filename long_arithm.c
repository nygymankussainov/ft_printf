/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:21:13 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/25 11:36:47 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_swap_str(char *s1, char *s2, int l1, int l2)
{
	
}

char	*column_add(char *s1, char *s2, int l1, int l2)
{
	int		i;
	int		rem;
	int		sum;
	char	*result;

	i = 0;
	rem = 0;
	result = (char *)ft_memalloc(sizeof(char) * (l2 + 1));
	while (i < l1)
	{
		sum = ((s1[i] - '0') + (s2[i] - '0')) + rem;
		result[l2] = (sum % 10) + '0';
		rem = sum / 10;
		l2--;
		i++;
	}
	i = l1;
	while (i < l2)
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

char	*long_arithm(char *s1, char *s2)
{
	int	 l1;
	int	 l2;
	char	*result;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 > l2)
	{
		ft_swap_str(s1, s2, l1, l2);
		ft_swap(&l1, &l2);
	}
	s1 = ft_revstr(s1);
	s2 = ft_revstr(s2);
	result = column_add(s1, s2, l1, l2);
	result = ft_revstr(result);
	return (result);
}

int		main(void)
{
	char s1[] = "12312";
	char s2[] = "5434";

	printf("%s\n", long_arithm(s1, s2));
	return (0);
}
