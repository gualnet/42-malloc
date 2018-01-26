/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:02:14 by galy              #+#    #+#             */
/*   Updated: 2018/01/26 17:59:24 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

// unsigned int	request_large(size_t size)
void	*request_large(size_t size)
{
	long	bloc_idx;

	bloc_idx = get_free_meta_block();
	vault.tab_meta[bloc_idx].adr = mmap(NULL, size_to_zone_size(size), \
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	
	vault.tab_meta[bloc_idx].capacity = 0;
	vault.tab_meta[bloc_idx].size = size;
	vault.tab_meta[bloc_idx].type = LARGE_ZONE;
	return (vault.tab_meta[bloc_idx].adr);
}

void	unmap_large(void *ptr)
{
	long	i;
	int		found;

	i = 0;
	found = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].adr == ptr)
		{
			found = 1;
			break;
		}
		i++;
	}
	if (found == 1)
	{
		munmap(ptr, vault.tab_meta[i].size);
		vault.tab_meta[i].adr = NULL;
		vault.tab_meta[i].size = 0;
		vault.tab_meta[i].type = FREE_BLOCK;
	}
}