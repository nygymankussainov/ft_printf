#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

int		main()
{
	double		nb;
	int			sign;
	unsigned int 		exp_mask;
	unsigned long int	mant_mask;
	int			exp_i;
	int			mant_i;
	char		str[65];
	int			i;
	__int64_t	nb1;
	int	j;
	__int64_t	nb2;
	char		*exp;
	char		*mant;
	long double		res;
	long double		tmp;
	int			digit;


	j = 63;
	i = 0;
	str[64] = '\0';
	nb = 0.333333333333333314829616256247390992939472198486328125;
	ft_memcpy(&nb1, &nb, 8);
	res = 0;
	while (j >= 0)
	{
		nb2 = (nb1 & ((__int64_t)1 << j));
		str[i] = (nb2 >> j) + '0';
		if (i > 0)
			write(1, &str[i], 1);
		j--;
		i++;
	}
	printf("\n");
	exp = (char *)ft_memalloc(sizeof(char) * 12);
	exp[11] = '\0';
	exp = ft_strncpy(exp, str + 1, 11);
	ft_putstr(exp, 0);
	printf("\n");
	exp_i = ft_atoi_base(exp, 2) - 1023;
	ft_putnbr(exp_i);
	printf("\n");
	mant = (char *)ft_memalloc(sizeof(char) * 53);
	mant[52] = '\0';
	mant = ft_strncpy(mant, str + 12, 52);
	printf("%63s\n", mant);
	i = 0;
	if (exp_i < 0)
	{
		write(1, "0.", 2);
		res += ft_power(2, -exp_i);
		res = 1 / res;
		exp_i--;
	}
	else
	{
		res += ft_power(2, exp_i);
		exp_i--;
		while (exp_i >= 0)
		{
			if (mant[i] == '0')
				i++;
			else if (mant[i] == '1')
			{
				res += ft_power(2, exp_i);
				i++;
			}
			exp_i--;
		}
		ft_putnbr(res);
		write(1, ".", 1);
		res = 0;
	}
	while (mant[i])
	{
		if (mant[i] == '0')
			i++;
		else if (mant[i] == '1')
		{
			tmp = ft_power(2, -exp_i);
			tmp = 1 / tmp;
			if (ft_count_digit(tmp, 1) == ft_count_digit(res, 1))
				res += tmp;
			else
			{
				if (res == 0)
					res += tmp;
				else
				{
					while (ft_count_digit(tmp, 1) != ft_count_digit(res, 1))
						tmp /= 10;
					res += tmp;
				}
			}
			i++;
		}
		exp_i--;
	}
	ft_putnbr(res * 1000000000);
}
