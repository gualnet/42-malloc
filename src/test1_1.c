
#include <stdio.h>
#include "malloc.h"

int test1_1()
{
	printf("\ttest1 ->  ft_malloc\n\n");
	//-----#-----#-----#-----//

	int		i;
	char	*adr;

	i = 0;
	while(i < 1024)
	{
		ft_printf("\n\t =====> BOUCLE DE TEST %d\n", i);
		adr = (char*)ft_malloc(1024);
		ft_printf("\t =====> BOUCLE DE TEST %d - step 2\n", i);
		// if (i < 4 && i > 4)
		// 	adr[1] = 42;
		adr[1] = 42;
		ft_printf("\t =====> BOUCLE DE TEST %d - step 3\n", i);
		i++;
	}

	return (0);
}