
#include <stdio.h>
#include "malloc.h"

int main()
{
	printf("\ttest1 ->  ft_malloc\n\n");
	//-----#-----#-----#-----//

	int		i;
	char	*adr;

	i = 0;
	while(i < 1024)
	{
		adr = (char*)ft_malloc(1024);
		adr[0] = 42;
		i++;
	}

	return (0);
}