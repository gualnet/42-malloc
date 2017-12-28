/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:45:52 by galy              #+#    #+#             */
/*   Updated: 2017/12/28 18:16:54 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

t_vault vault = {};

// mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
void    *ft_malloc(size_t size)
{
	ft_printf("\n\t***CALL ft_malloc(size=%zu)*** vault=>%p\n", size, &vault);
	pthread_mutex_t mutex_lock; //??
	void			*adr;
	
	
	adr = NULL;
	if (size <= 0)
		return (NULL);
	pthread_mutex_lock(&mutex_lock); //??

	if (check_meta_data(&vault, size) == NULL) // check/create meta-data tab
		return (NULL);
	if (vault.meta_items_max == INT_MAX - 1)
		return NULL;
	// ft_printf("Adr de tab_meta [%p]\n", &(vault.tab_meta));
// ---------------------
	if (size <= SMALL_ALLOC_MAX)
		adr = check_meta_find_subz(&vault, size);
	else
		adr = check_meta_find_custom(size);
	
// ---------------------
	tab_free_cleaner();
// ---------------------
	pthread_mutex_unlock(&mutex_lock); //??
	printAllTabMetaInfo(&vault, 12);
	printTabFree(6);
	// printf("\n\t***CALL ft_malloc(size=%zu)*** vault=>%p\n", size, &vault);
	return adr;
}

int main(int argc, char **argv)
{
	char	*str;
	// char	*str2;
	int		i;
	
	// ft_printf("(getpagesize(%d) * nbrPages(%d)) / t_meta_data(%d) = %d\n",\
	// getpagesize(), META_INCRE_ALLOC_PAGE, sizeof(t_meta_data),\
	// getpagesize() * META_INCRE_ALLOC_PAGE / sizeof(t_meta_data));

	if (argc == 1)
	{
		//>>TINY TESTS<<
		// str = ft_malloc(0);
		// ft_printf("\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
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
		str = ft_malloc(SMALL_ALLOC_MIN + 1000);
		ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);

		str = ft_malloc(SMALL_ALLOC_MAX + 1);
		ft_printf("\n\t-->\ttest malloc (SMALL_ALLOC_MAX + 1)\nmain adr: %p\n\n", str);
		
		str = ft_malloc(SMALL_ALLOC_MIN + 500);
		ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
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
	else
	{
		i = 1;
		while (i < argc)
		{
			switch (ft_atoi(argv[i]))
			{
				case 0:
					test0();
					break;
				case 1:
					// test1();
					ft_printf("\n********************	********************\n");
					ft_printf("\n********************	********************\n");
					ft_printf("\n********************	********************\n");
					test1_1();
					break;
				default:
					ft_printf("def\n");
			}
			i++;
		}
	}
	
}