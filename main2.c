#include <stdio.h>
#include <stdlib.h>

void	check2(char str)
{
	printf("%c\n", str);
}

void	check(char **str)
{
	*str += 1;
	//check2(str[2]);
}

int		main()
{
	char *str;

	str = (char *)malloc(sizeof(char) * 4);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';
	check(&str);
	printf("%c\n", *str);
}
