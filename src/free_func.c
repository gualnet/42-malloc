/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:40:40 by galy              #+#    #+#             */
/*   Updated: 2018/02/15 16:59:06 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	defrag_merge_bf_subz(long m_id, long f_id)
{
	vault.tab_free[f_id].ptr->size += vault.tab_meta[m_id].size;
	vault.tab_meta[m_id].size = 0;
	vault.tab_meta[m_id].type = FREE_BLOCK;
	vault.tab_meta[m_id].adr = NULL;
}

void	defrag_merge_af_subz(long m_id, long f_id)
{
	vault.tab_meta[m_id].size += vault.tab_free[f_id].ptr->size;
	vault.tab_free[f_id].ptr->size = 0;
	vault.tab_free[f_id].ptr->type = FREE_BLOCK;
}

void	defrag(long m_id)
{
	long	i;

	i = 0;
	while (i < vault.free_items_max)
	{
		if (vault.tab_free[i].ptr != NULL && \
		vault.tab_free[i].ptr->adr + \
		vault.tab_free[i].ptr->size == vault.tab_meta[m_id].adr)
			defrag_merge_bf_subz(m_id, i);
		if (vault.tab_free[i].ptr != NULL && \
		vault.tab_free[i].ptr->adr - \
		vault.tab_meta[m_id].size == vault.tab_meta[m_id].adr)
			defrag_merge_af_subz(m_id, i);
		i++;
	}
}

void	safs_2(long i)
{
	if (vault.tab_meta[i].type == TINY_SUBZ)
	{
		vault.tab_meta[i].type = TINY_SUBZ_FREE;
		vault.tab_free[get_free_free_block()].ptr = &vault.tab_meta[i];
	}
	else if (vault.tab_meta[i].type == SMALL_SUBZ)
	{
		vault.tab_meta[i].type = SMALL_SUBZ_FREE;
		vault.tab_free[get_free_free_block()].ptr = &vault.tab_meta[i];
	}
}

int		search_and_free_subz(void *ptr)
{
	long	i;

	i = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].adr == ptr && \
		vault.tab_meta[i].type != TINY_ZONE && \
		vault.tab_meta[i].type != SMALL_ZONE && \
		vault.tab_meta[i].type != LARGE_ZONE)
		{
			safs_2(i);
			defrag(i);
			return (1);
		}
		if (vault.tab_meta[i].adr == ptr && \
		vault.tab_meta[i].type == LARGE_ZONE)
		{
			unmap_large(i);
			return (1);
		}
		i++;
	}
	return (-1);
}
