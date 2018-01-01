#include "../inc/malloc.h"

int main(void)
{
	char	*str;
	char	*str2;
	
	str = NULL;
	str2 = NULL;
	// ft_printf("(getpagesize(%d) * nbrPages(%d)) / t_meta_data(%d) = %d\n",\
	// getpagesize(), META_INCRE_ALLOC_PAGE, sizeof(t_meta_data),\
	// getpagesize() * META_INCRE_ALLOC_PAGE / sizeof(t_meta_data));

	//>>TINY TESTS<<
	str = ft_malloc(0);
	ft_printf("\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
	// ft_printf("TEST--> %p\n", &vault);
	// str = ft_malloc(1111);
	// ft_printf("TEST--> %p\n", &vault);
	// ft_printf("\n\t-->\ttest malloc (1111)\nmain adr: %p\n\n", str);
	// ft_printf("TEST--> %p\n", &vault);
	// ft_free(str);
	// str = ft_malloc(TINY_ALLOC_MAX);
	// ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MAX)\nmain adr: %p\n\n", str);
	// ft_free(str);
	// str = ft_malloc(TINY_ALLOC_MAX);
	// ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MAX)\nmain adr: %p\n\n", str);
	// str = ft_malloc(TINY_ALLOC_MIN + 910);
	// ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MIN + 911)\nmain adr: %p\n\n", str);
	// str = ft_malloc(TINY_ALLOC_MAX);
	// ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MAX)\nmain adr: %p\n\n", str);

	//>>SMALL TESTS<<
	// str = ft_malloc(SMALL_ALLOC_MIN);
	// ft_printf("\n\t-->\ttest malloc (SMALL_ALLOC_MIN)\nmain adr: %p\n\n", str);
	// str = ft_malloc(SMALL_ALLOC_MAX);
	// ft_printf("\n\t-->\ttest malloc (SMALL_ALLOC_MAX)\nmain adr: %p\n\n", str);
	// str = ft_malloc(TINY_ALLOC_MAX);
	// ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MAX)\nmain adr: %p\n\n", str);
	// str = ft_malloc(SMALL_ALLOC_MIN + 910);
	// ft_printf("\n\t-->\ttest malloc (SMALL_ALLOC_MIN + 911)\nmain adr: %p\n\n", str);
	// str = ft_malloc(SMALL_ALLOC_MAX);
	// ft_printf("\n\t-->\ttest malloc (SMALL_ALLOC_MAX)\nmain adr: %p\n\n", str);
	
	//>>LARGE TESTS<<
	// str = ft_malloc(SMALL_ALLOC_MIN + 1000);
	// ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);

	// str2 = ft_malloc(SMALL_ALLOC_MAX + 1);
	// ft_printf("\n\t-->\ttest malloc (SMALL_ALLOC_MAX + 1)\nmain adr: %p\n\n", str2);
	// ft_printf("STR2[%s]\n", str2);
	// str2 = "coucou";
	// ft_printf("STR2[%s]\n", str2);
	// ft_free(str2);
	// str2 = "fin";
	// ft_printf("STR2[%s]\n", str2);
	// str = ft_malloc(SMALL_ALLOC_MIN + 500);
	// ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
	// str = ft_malloc(0);
	// ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
	// str = ft_malloc(0);
	// ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
	// str = ft_malloc(0);
	// ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);

	// TEST FREE
	// str = ft_malloc(1111);
	// ft_printf("\n\t-->\ttest malloc (1111)\nmain adr: %p\n\n", str);
	// str2 = ft_malloc(1234);
	// ft_printf("\n\t-->\ttest malloc (1234)\nmain adr: %p\n\n", str);
	// ft_free(str2);
	// ft_free(str);
	// str2 = ft_malloc(2222);
	// ft_printf("\n\t-->\ttest malloc (1234)\nmain adr: %p\n\n", str);
	// ft_free(str);

}