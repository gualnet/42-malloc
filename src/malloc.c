/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:14:26 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 19:04:56 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_vault g_vault;

void	*malloc(size_t size)
{
	void			*adr;
	long			idx;

	idx = 0;
	adr = NULL;
	if (pthread_mutex_init(&g_vault.mutex, 0) != 0 || size <= 0)
		return (adr);
	pthread_mutex_lock(&g_vault.mutex);
	if (meta_data_initializer() != 1)
		return (NULL);
	if (size <= SMALL_ALLOC_MAX)
	{
		if ((idx = request_tiny_small(size)) == -1)
			return (NULL);
		adr = g_vault.tab_meta[idx].adr;
	}
	else
	{
		adr = request_large(size);
	}
	tab_free_cleaner();
	pthread_mutex_unlock(&g_vault.mutex);
	return (adr);
}

void	*my_mmap(size_t size)
{
	void *adr;

	adr = NULL;
	adr = mmap(NULL, size, \
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	return (adr);
}
