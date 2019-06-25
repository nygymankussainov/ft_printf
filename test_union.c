#include <stdio.h>

typedef union	s_un
{
	int		sign : 1;
	int		a : 3;
	int		nb;
}				t_un;

int		main(void)
{
	t_un un;

	un.nb = 1000;
	un.sign = 0;
	printf("%d\n", un.nb);
}
