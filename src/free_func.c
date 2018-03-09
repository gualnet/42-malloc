/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:40:40 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 18:18:06 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	defrag_merge_bf_subz(long m_id, long f_id)
{
	g_vault.tab_free[f_id].ptr->size += g_vault.tab_meta[m_id].size;
	g_vault.tab_meta[m_id].size = 0;
	g_vault.tab_meta[m_id].type = FREE_BLOCK;
	g_vault.tab_meta[m_id].adr = NULL;
}

void	defrag_merge_af_subz(long m_id, long f_id)
{
	g_vault.tab_meta[m_id].size += g_vault.tab_free[f_id].ptr->size;
	g_vault.tab_free[f_id].ptr->size = 0;
	g_vault.tab_free[f_id].ptr->type = FREE_BLOCK;
}

void	defrag(long m_id)
{
	long	i;

	i = 0;
	while (i < g_vault.free_items_max)
	{
		if (g_vault.tab_free[i].ptr != NULL && \
		g_vault.tab_free[i].ptr->adr + \
		g_vault.tab_free[i].ptr->size == g_vault.tab_meta[m_id].adr)
			defrag_merge_bf_subz(m_id, i);
		if (g_vault.tab_free[i].ptr != NULL && \
		g_vault.tab_free[i].ptr->adr - \
		g_vault.tab_meta[m_id].size == g_vault.tab_meta[m_id].adr)
			defrag_merge_af_subz(m_id, i);
		i++;
	}
}

void	safs_2(long i)
{
	if (g_vault.tab_meta[i].type == TINY_SUBZ)
	{
		g_vault.tab_meta[i].type = TINY_SUBZ_FREE;
		g_vault.tab_free[get_free_free_block()].ptr = &g_vault.tab_meta[i];
	}
	else if (g_vault.tab_meta[i].type == SMALL_SUBZ)
	{
		g_vault.tab_meta[i].type = SMALL_SUBZ_FREE;
		g_vault.tab_free[get_free_free_block()].ptr = &g_vault.tab_meta[i];
	}
}

int		search_and_free_subz(void *ptr)
{
	long	i;

	i = 0;
	while (i < g_vault.meta_items_max)
	{
		if (g_vault.tab_meta[i].adr == ptr && \
		g_vault.tab_meta[i].type != TINY_ZONE && \
		g_vault.tab_meta[i].type != SMALL_ZONE && \
		g_vault.tab_meta[i].type != LARGE_ZONE)
		{
			safs_2(i);
			defrag(i);
			return (1);
		}
		if (g_vault.tab_meta[i].adr == ptr && \
		g_vault.tab_meta[i].type == LARGE_ZONE)
		{
			unmap_large(i);
			return (1);
		}
		i++;
	}
	return (-1);
}
