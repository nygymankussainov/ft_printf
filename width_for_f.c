/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_for_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:46:28 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/07/31 19:25:30 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(char *str)
{
	int width;
	int	i;

	width = 0;
	i = 0;
	while (*str && *str != '.')
	{
		if (ft_isdigit(*str))
		{
			while (str[i] != '.' && !ft_isalpha(str[i]))
			{
				if (str[i] == '-' || str[i] == '+')
				{
					width = ft_atoi(str + i + 1);
					return (width);
				}
				i++;
			}
			width = ft_atoi(str);
			return (width);
		}
		str++;
	}
	return (width);
}

int		width_for_f(char *str, t_flags *s, int ret)
{
	if (s->pos && s->zero)
		write(1, "+", 1);
	else if (s->neg)
	{
		if (s->pos)
			write(1, "+", 1);
		ft_putstr(str);
	}
	s->width -= ret;
	if (s->width > 0)
	{
		ret += s->width;
		while (s->width--)
		{
			if (!s->zero)
				ft_putchar(' ');
			else
				ft_putchar('0');
		}
	}
	if ((s->pos && !s->neg) || (!s->pos && !s->neg))
	{
		if (s->pos && !s->neg && !s->zero)
			write(1, "+", 1);
		ft_putstr(str);
	}
	return (ret);
}
