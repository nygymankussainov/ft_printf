# ft_printf

Re-coded printf function

# Bonus

The b conversion prints out binary representation of double and long double values.

Works with the folowing flags:

L - long double;\n
z - prints sign;
m - prints exponent;
mm - prints mantissa;

Example:
	ft_printf("%Lb", LDBL_MAX); Will print:
	0.111111111111110.111111111111111111111111111111111111111111111111111111111111111
