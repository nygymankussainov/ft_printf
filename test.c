#include <stdio.h>

int		main(void)
{
	int	a;
	void	*ptr;

	a = 100;
	ptr = &a;
	printf("%x\n", a);
	printf("%p\n", a);
}