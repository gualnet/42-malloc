#include <unistd.h>
#include "malloc.h"
int main(void)
{
	ft_malloc(1024);
	ft_malloc(1024 * 32);
	ft_malloc(1024 * 1024);
	ft_malloc(1024 * 1024 * 16);
	ft_malloc(1024);
	ft_malloc(1024 * 1024 * 16);
	ft_malloc(1024 * 1024 * 128);
	ft_malloc(1024);
	
	show_alloc_mem();
	// printAllTabMetaInfo(15);
	// printAllTabFreeInfo(8);
	return (0);
}

// int main(void)
// {
// 	malloc(1024);
// 	malloc(1024 * 32);
// 	malloc(1024 * 1024);
// 	malloc(1024 * 1024 * 16);
// 	malloc(1024);
// 	malloc(1024 * 1024 * 16);
// 	malloc(1024 * 1024 * 128);
// 	malloc(1024);
	
// 	show_alloc_mem();
// 	// printAllTabMetaInfo(15);
// 	// printAllTabFreeInfo(8);
// 	return (0);
// }