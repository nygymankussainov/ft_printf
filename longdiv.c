/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longdiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:39:28 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/11 16:40:20 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*longdiv(char *number, int divisor)
{
	int		len;
	int		i;
	char	*ans;
	int		idx;
	int		temp;

	idx = 0;
	temp = number[idx] - '0';
	while (temp < divisor)
		temp = temp * 10 + (number[++idx] - '0');
	len = ft_strlen(number);
	ans = (char *)ft_memalloc(sizeof(char) * (len + 1));
	ans[len] = '\0';
	i = 0;
	while (len > idx)
	{
		ans[i] = (temp / divisor) + '0';
		temp = (temp % divisor) * 10 + number[++idx] - '0';
		i++;
	}
	if (ft_strlen(ans) == 0)
		return ("0");
	return (ans);
}
