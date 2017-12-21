
#include <stdio.h>
#include <stdlib.h>

int test1()
{
	printf("\ttest1 -> built-in malloc\n\n");
	//-----#-----#-----#-----//

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