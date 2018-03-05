/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:02:14 by galy              #+#    #+#             */
/*   Updated: 2018/02/15 17:34:16 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*request_large(size_t size)
{
	long	bloc_idx;

	bloc_idx = get_free_meta_block();
	vault.tab_meta[bloc_idx].adr = mmap(NULL, size, \
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (vault.tab_meta[bloc_idx].adr == MAP_FAILED)
	{
		if (ft_strcmp(getenv("DEBUG_MALLOC"), "TRUE") == 0)
			ft_putstr("\033[31mError[000]: \
			MAP_FAILED in request_large.c line 23\033[0m\n");
		return (NULL);
	}
	vault.tab_meta[bloc_idx].capacity = 0;
	vault.tab_meta[bloc_idx].size = size;
	vault.tab_meta[bloc_idx].type = LARGE_ZONE;
	return (vault.tab_meta[bloc_idx].adr);
}

void	unmap_large(long i)
{
	munmap(vault.tab_meta[i].adr, vault.tab_meta[i].size);
	vault.tab_meta[i].adr = NULL;
	vault.tab_meta[i].size = 0;
	vault.tab_meta[i].type = FREE_BLOCK;
}
