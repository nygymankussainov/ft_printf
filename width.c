/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:27:34 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/31 21:14:08 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width(char *str, t_flags *s, int ret)
{
	if (s->neg && !s->pos && !s->zero_padd)
		ft_putstr(str);
	s->width -= ret;
	ret += s->width;
	if (s->pos && s->zero && !s->neg)
		write(1, "+", 1);
	while (s->width--)
	{
		if (!s->zero)
			ft_putchar(' ');
		else
		{
			if (str[0] == '-')
			{
				write(1, "-", 1);
				str++;
			}
			ft_putchar('0');
		}
	}
	if ((s->pos >= 0 && !s->neg) || (s->pos >= 0 && s->zero_padd))
	{
		if (s->pos && !s->zero)
			write(1, "+", 1);
		ft_putstr(str);
	}
	return (ret);
}
