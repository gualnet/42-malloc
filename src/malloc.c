/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:45:52 by galy              #+#    #+#             */
/*   Updated: 2017/12/28 19:45:22 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

t_vault vault = {};

// mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
void    *ft_malloc(size_t size)
{
	// ft_printf("\n\t***CALL ft_malloc(size=%zu)*** vault=>%p\n", size, &vault);
	pthread_mutex_t mutex_lock; //??
	void			*adr;
	
	
	adr = NULL;
	if (size <= 0)
		return (NULL);
	pthread_mutex_lock(&mutex_lock); //??

	if (check_meta_data(&vault) == NULL) // check/create meta-data tab
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
	// printAllTabMetaInfo(&vault, 12);
	// printTabFree(6);
	// printf("\n\t***CALL ft_malloc(size=%zu)*** vault=>%p\n", size, &vault);
	return adr;
}