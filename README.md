# ft_printf

Re-coded printf function

	During this project I learnt about representation of floating point numbers in a computer
	and how printf function works.

* **Usage**

	make
	gcc <file.c> libftprintf.a libft/libft.a -I libft/ -I ./

	You are supposed to call ft_printf function from <file.c>. In order to get rid of warnings
	prototype: 
		#include "ft_printf.h"
	at the top of <file.c>

* **Conversions and flags that has been managed in ft_printf:** 

- Conversions: `s`, `p`, `d`, `i`, `o`, `u`, `x`&`c` with flags:
- `hh`, `h`, `l`, `ll`, `j`, & `z`.
- `%%`
- flags: `#`, `0`, `-`, `+` & `space`
- minimum field-width
- precision

* **One more conversion as a bonus:**

The b conversion prints out binary representation of double and long double values.

Works with the folowing flags:

- `L` - long double;
- `z` - prints sign;
- `m` - prints exponent;
- `mm` - prints mantissa;

Example:
	`ft_printf("%Lb", LDBL_MAX);` will print:
	`0.111111111111110.111111111111111111111111111111111111111111111111111111111111111`
