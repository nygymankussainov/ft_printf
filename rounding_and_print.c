/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding_and_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:18:47 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/25 19:15:34 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rounding(char **res, int prec)
{
	int		tmp;

	tmp = prec;
	// if ((*res)[prec])
	// {
		if ((*res)[prec] >= '5')
		{
			if ((*res)[prec] == '9')
			{
				while ((*res)[tmp] == '9')
					(*res)[tmp--] = '0';
				(*res)[tmp]++;
			}
			else
				(*res)[prec - 1]++;
			if ((*res)[prec] == '5')
				if (!(*res)[prec + 1])
					(*res)[prec - 1]--;
		}
		(*res)[prec] = '\0';
	// }
	// else if (!(*res)[prec] && prec == 0)
	// 	(*res)[prec] = '\0';
	// else if (!(*res)[prec] && prec > 0)
	// {
	// 	while (prec--)
	// 		write(1, "0", 1);
	// }
}

// int		if_noprec(char **res)
// {
// 	int		prec;
// 	int		len;

// 	prec = 6;
// 	while ((*res)[prec - 1])
// 	{
// 		if ((*res)[prec - 1] != '0')
// 		{
// 			rounding(res, 6);
// 			ft_putstr(*res, 0);
// 			free(*res);
// 			return (7);
// 		}
// 		prec--;
// 	}
// 	(*res)[prec] = '\0';
// 	len = ft_strlen(*res);
// 	ft_putstr(*res, 0);
// 	prec -= len;
// 	while (prec--)
// 		write(1, "0", 1);
// 	free(*res);
// 	return (7);
// }

int		print(char **res, int prec)
{
	int		ret;

	rounding(res, prec);
	ret = ft_strlen(*res);
	if (prec > 0)
		write(1, ".", 1);
	ft_putstr(*res, 0);
	if (prec && !(*res)[prec])
	{
		prec = prec - ret;
		ret += prec > 0 ? prec : 0;
		while (prec-- > 0)
			write(1, "0", 1);
	}
	free(*res);
	return (ret + 1);
}
