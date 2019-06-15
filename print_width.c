/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:46:28 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/15 19:44:31 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(char *str)
{
	int width;

	width = 0;
	str += str[0] == '-' ? 1 : 0;
	str += str[1] == '-' ? 2 : 0;
	if (*str >= '0' && *str <= '9')
		width = ft_atoi(str);
	return (width);
}

int		print_width(char *str, t_printf s, int ret)
{
	if (s.sign < 0)
		ft_putstr(str, s.sign);
	s.width -= ret;
	ret += s.width;
	while (s.width--)
	{
		if (!s.zero)
			ft_putchar(' ');
		else
			ft_putchar('0');
	}
	if (s.sign > 0)
		ft_putstr(str, s.sign);
	return (ret);
}
