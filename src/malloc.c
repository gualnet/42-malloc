/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:45:52 by galy              #+#    #+#             */
/*   Updated: 2017/12/16 22:04:42 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

// mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

void    *ft_malloc(size_t size)
{
	ft_printf("\n\t***CALL ft_malloc(size=%d)***\n", size);
	pthread_mutex_t mutex_lock; //??
	void			*adr;
	static t_vault	vault;
	
	adr = NULL;
	if(size <= 0)
		return (NULL);
	pthread_mutex_lock(&mutex_lock); //??

	if(check_meta_data(&vault, size) == NULL) // check/create meta-data tab
		return (NULL);
	// ft_printf("Adr de tab_meta [%p]\n", &(vault.tab_meta));
// ---------------------
	adr = check_meta_find_space(&vault, size);
	// adr = check_meta_find_space(&vault, size);
// ---------------------
	
	pthread_mutex_unlock(&mutex_lock); //??
	printAllTabMetaInfo(&vault, 20);
	return adr;
}

int main()
{
	char *str;
	
	ft_printf("(getpagesize(%d) * nbrPages(%d)) / t_meta_data(%d) = %d\n",\
	getpagesize(), META_INCRE_ALLOC_PAGE, sizeof(t_meta_data),\
	getpagesize() * META_INCRE_ALLOC_PAGE / sizeof(t_meta_data));

	//>>TINY TESTS<<
	// str = ft_malloc(0);
	// ft_printf("\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
	// str = ft_malloc(1111);
	// ft_printf("\n\t-->\ttest malloc (1111)\nmain adr: %p\n\n", str);
	// str = ft_malloc(TINY_ALLOC_MAX);
	// ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MAX)\nmain adr: %p\n\n", str);
	// str = ft_malloc(TINY_ALLOC_MAX);
	// ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MAX)\nmain adr: %p\n\n", str);
	// str = ft_malloc(TINY_ALLOC_MIN + 910);
	// ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MIN + 911)\nmain adr: %p\n\n", str);
	// str = ft_malloc(TINY_ALLOC_MAX);
	// ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MAX)\nmain adr: %p\n\n", str);

	//>>SMALL TESTS<<
	str = ft_malloc(SMALL_ALLOC_MIN);
	ft_printf("\n\t-->\ttest malloc (SMALL_ALLOC_MIN)\nmain adr: %p\n\n", str);
	str = ft_malloc(SMALL_ALLOC_MAX);
	ft_printf("\n\t-->\ttest malloc (SMALL_ALLOC_MAX)\nmain adr: %p\n\n", str);
	str = ft_malloc(TINY_ALLOC_MAX);
	ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MAX)\nmain adr: %p\n\n", str);
	str = ft_malloc(SMALL_ALLOC_MIN + 910);
	ft_printf("\n\t-->\ttest malloc (SMALL_ALLOC_MIN + 911)\nmain adr: %p\n\n", str);
	str = ft_malloc(SMALL_ALLOC_MAX);
	ft_printf("\n\t-->\ttest malloc (SMALL_ALLOC_MAX)\nmain adr: %p\n\n", str);
	

	// str = ft_malloc(TINY_ALLOC_MAX + 1);
	// ft_printf("\n\t-->\ttest malloc (TINY_ALLOC_MAX + 1)\nmain adr: %p\n\n", str);
	// str = ft_malloc(0);
	// ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
	// str = ft_malloc(0);
	// ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
	// str = ft_malloc(0);
	// ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
	// str = ft_malloc(0);
	// ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
	// str = ft_malloc(0);
	// ft_printf("\n\t-->\ttest malloc (0)\nmain adr: %p\n\n", str);
}