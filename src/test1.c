
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int		i;
	char	*adr;

	i = 0;
	while(i < 1024)
	{
		adr = (char*)malloc(1024);
		adr[0] = 42;
		i++;
	}
	return (0);
}