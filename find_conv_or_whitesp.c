/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_conv_or_whitesp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:52:11 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/04 14:13:12 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			find_conv(const char *s)
{
	while (*s)
	{
		if (*s == 'd' || *s == 'i' || *s == 'o'
			|| *s == 'u' || *s == 'x' || *s == 'X'
			|| *s == 's' || *s == 'F' || *s == 'f' ||
			*s == 'p' || *s == 'c' || *s == '%' || *s == 'h'
			|| *s == 'l' || *s == 'L')
		{
			if (*s == 'h' || *s == 'l' || *s == 'L')
				if (!find_conv(s + 1))
					return (-1);
			return (1);
		}
		s++;
	}
	return (0);
}

void		find_whitesp(const char **format, t_flags *s)
{
	while (iswhitesp(**F) || ((**F == '-' || **F == '+')
		&& *(*F + 1) != ft_isdigit(*(*F + 1))))
	{
		if (iswhitesp(**F))
			s->whitesp++;
		else if (**F == '-')
			s->neg = 1;
		else if (**F == '+')
			s->pos = 1;
		(*F)++;
	}
}
