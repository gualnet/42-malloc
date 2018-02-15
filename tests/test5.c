// #include <unistd.h>
#include "malloc.h"
// int main(void)
// {
// 	ft_malloc(1024);
// 	ft_malloc(1024 * 32);
// 	ft_malloc(1024 * 1024);
// 	ft_malloc(1024 * 1024 * 16);
// 	ft_malloc(1024);
// 	ft_malloc(1024 * 1024 * 16);
// 	ft_malloc(1024 * 1024 * 128);
// 	ft_malloc(1024);
	
// 	show_alloc_mem();
// 	// printAllTabMetaInfo(15);
// 	// printAllTabFreeInfo(8);
// 	return (0);
// }

// #include <stdlib.h>
int main(void)
{
	char *adr;

	adr = malloc(1024);
	adr = malloc(1024 * 32);
	adr = malloc(1024 * 1024);
	adr = malloc(1024 * 1024 * 16);
	adr = malloc(1024);
	adr = malloc(1024 * 1024 * 16);
	adr = malloc(1024 * 1024 * 128);
	adr = malloc(1024);
	
	show_alloc_mem();
	// printAllTabMetaInfo(15);
	// printAllTabFreeInfo(8);
	return (0);
}