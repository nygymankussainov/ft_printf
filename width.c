/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:46:28 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/28 20:23:36 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(char *str)
{
	int width;

	width = 0;
	str += str[0] == '-' || str[0] == '+' ? 1 : 0;
	str += str[1] == '-' || str[1] == '+'  ? 2 : 0;
	if (*str >= '0' && *str <= '9')
		width = ft_atoi(str);
	return (width);
}

int		width(char *str, t_printf s, int ret)
{
	if (s.signflag < 0)
		ft_putstr(str, s.signflag);
	s.width -= ret;
	if (s.width > 0)
	{
		ret += s.width;
		while (s.width--)
		{
			if (!s.zero)
				ft_putchar(' ');
			else
			{
				if (str[0] == '-' && s.signflag >= 0)
				{
					write(1, "-", 1);
					str++;
				}
				ft_putchar('0');
			}
		}
	}
	if (s.signflag >= 0)
		ft_putstr(str, s.signflag);
	return (ret);
}
