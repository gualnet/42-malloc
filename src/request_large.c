/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:02:14 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 18:20:08 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*request_large(size_t size)
{
	long	bloc_idx;

	bloc_idx = get_free_meta_block();
	g_vault.tab_meta[bloc_idx].adr = my_mmap(size);
	if (g_vault.tab_meta[bloc_idx].adr == MAP_FAILED)
	{
		if (ft_strcmp(getenv("DEBUG_MALLOC"), "TRUE") == 0)
			ft_putstr("\033[31mError[000]: \
			MAP_FAILED in request_large.c line 23\033[0m\n");
		return (NULL);
	}
	g_vault.tab_meta[bloc_idx].capacity = 0;
	g_vault.tab_meta[bloc_idx].size = size;
	g_vault.tab_meta[bloc_idx].type = LARGE_ZONE;
	return (g_vault.tab_meta[bloc_idx].adr);
}

void	unmap_large(long i)
{
	munmap(g_vault.tab_meta[i].adr, g_vault.tab_meta[i].size);
	g_vault.tab_meta[i].adr = NULL;
	g_vault.tab_meta[i].size = 0;
	g_vault.tab_meta[i].type = FREE_BLOCK;
}
