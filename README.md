# ft_printf

Re-coded printf function

# Usage
	make
	gcc <file.c> libftprintf.a libft/libft.a -I libft/ -I ./

	You are supposed to call ft_printf function from <file.c>. In order to get rid of warnings
	prototype **#include "ft_printf.h"** at the top of <file.c>
# Bonus

The b conversion prints out binary representation of double and long double values.

Works with the folowing flags:

L - long double;
z - prints sign;
m - prints exponent;
mm - prints mantissa;

Example:
	ft_printf("%Lb", LDBL_MAX); Will print:
	0.111111111111110.111111111111111111111111111111111111111111111111111111111111111
