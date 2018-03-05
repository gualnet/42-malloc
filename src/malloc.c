/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:14:26 by galy              #+#    #+#             */
/*   Updated: 2018/03/05 12:15:36 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_vault vault = {};

void    *malloc(size_t size)
{
	void			*adr;
	long			idx;

	idx = 0;
	adr = NULL;

	if (pthread_mutex_init(&vault.mutex, 0) != 0 || size <= 0)
		return (adr);
	pthread_mutex_lock(&vault.mutex);
	if (meta_data_initializer() != 1)
		return (NULL);
	if (size <= SMALL_ALLOC_MAX)
	{
		if ((idx = request_tiny_small(size)) == -1)
			return (NULL);
		adr = vault.tab_meta[idx].adr;
	}
	else
	{
		adr = request_large(size);
	}
	check_tabmeta_usage();
	tab_free_cleaner(); // mef a virer
	pthread_mutex_unlock(&vault.mutex);
	return adr;
}

void	*my_mmap(size_t size)
{
	void *adr;

	adr = NULL;
	adr = mmap(NULL, size, \
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (adr == NULL || adr == MAP_FAILED)
		return (NULL);
	return (adr);
}