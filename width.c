/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:27:34 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/01 22:47:22 by vhazelnu         ###   ########.fr       */
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
			while (str[i] && str[i] != '.' && !ft_isalpha(str[i]))
			{
				if (str[i] == '-' || str[i] == '+')
				{
					width = ft_atoi(str + i + 1);
					if (width < 0)
						return (-width);
					return (width);
				}
				i++;
			}
			width = ft_atoi(str);
			if (width < 0)
				return (-width);
			return (width);
		}
		str++;
	}
	if (width < 0)
		return (-width);
	return (width);
}

int		width(char *str, t_flags *s, int ret)
{
	if (((s->neg && !s->pos) && (s->neg && !s->zero_padd)) ||
		(s->neg && s->pos && !s->zero_padd))
		ft_putstr(str);
	if (s->neg && s->pos)
	{
		s->width -= ret + 1;
		s->pos = 0;
		ret += s->width + 1;
	}
	else
	{
		s->width -= ret;
		ret += s->width;
	}
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
	if ((s->pos >= 0 && !s->neg) || (s->pos >= 0
		&& s->zero_padd && !s->neg) || (s->neg && s->zero_padd && !s->pos))
	{
		if (s->pos && !s->zero)
			write(1, "+", 1);
		ft_putstr(str);
	}
	return (ret);
}
