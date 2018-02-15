// #include "unistd.h"

#include "../inc/malloc.h"
// int main(void)
// {
// 	int		i;
// 	int		max;
// 	char	*adr;
	
// 	i = 0;
// 	max = 1024;
// 	while(i < max)
// 	{
// 		adr = (char*)ft_malloc(1024);
// 		adr[0] = 42;
// 		// printAllTabMetaInfo(0);
// 		// printAllTabFreeInfo(10);
// 		i++;
// 	}

// 	return (0);
// }

// #include "stdlib.h"
int main(void)
{
	int		i;
	int		max;
	char	*adr;
	
	i = 0;
	max = 1024;
	while(i < max)
	{
		adr = (char*)malloc(1024);
		adr[0] = 42;
		i++;
	}
	return (0);
}