
// #include <unistd.h>
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
// 		// printAllTabMetaInfo(10);
// 		// printAllTabFreeInfo(10);
// 		ft_free(adr);
// 		// printAllTabMetaInfo(10);
// 		// printAllTabFreeInfo(10);
// 		i++;
// 	}
// 	return (0);
// }

int main(void)
{
	int		i;
	int		max;
	char	*adr;
	
	i = 0;
	max = 4000;
	while(i < max)
	{
		adr = (char*)malloc(1024);
		adr[0] = 42;
		free(adr);
		i++;
	}
	return (0);
}