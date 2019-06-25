#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

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
	unsigned long long		res;
	unsigned long long		tmp;
	int			digit;
	char		*res_str;
	char		*tmp_str;


	j = 63;
	i = 0;
	str[64] = '\0';
	nb = 5.333333333333333314829616256247390992939472198486328125;
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
		res = ft_power(5, -exp_i);
		res_str = ft_itoa(res);
		exp_i--;
	}
	else
	{
		res = ft_power(2, exp_i);
		res_str = ft_itoa(res);
		exp_i--;
		while (exp_i >= 0)
		{
			if (mant[i] == '0')
				i++;
			else if (mant[i] == '1')
			{
				res = ft_power(2, exp_i);
				tmp_str = ft_itoa(res);
				res_str = long_arithm(res_str, tmp_str);
				i++;
			}
			exp_i--;
		}
		ft_putstr(res_str, 0);
		write(1, ".", 1);
	}
	res = ft_power(5, -exp_i);
	res_str = ft_itoa(res);
	while (mant[i])
	{
		if (mant[i] == '0')
			i++;
		else if (mant[i] == '1')
		{
			tmp = ft_power(5, -exp_i);
			tmp_str = ft_itoa(tmp);
			if (ft_strlen(tmp_str) == ft_strlen(res_str))
				res_str = long_arithm(res_str, tmp_str);
			else
			{
                res_str = ft_realloc(res_str, ft_strlen(tmp_str));
				res_str = long_arithm(res_str, tmp_str);
			}
			i++;
		}
		exp_i--;
	}
	ft_putstr(res_str, 0);
}
