/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:27:49 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/18 21:02:57 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s, short sign)
{
	if (!s)
		return ;
	if (sign == 1)
		write(1, "0", 1);
	else if (sign == 2)
		write(1, "+", 1);
	else if (sign == 3)
		write(1, "0x", 2);
	else if (sign == 4)
		write(1, "0X", 2);
	write(1, s, ft_strlen(s));
}
