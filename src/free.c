/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:49:52 by galy              #+#    #+#             */
/*   Updated: 2018/02/04 18:56:41 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

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
		vault.tab_free[i].ptr->adr + vault.tab_free[i].ptr->size == vault.tab_meta[m_id].adr)
		{
			// ft_printf("DEFRAG BINGO before\n");
			defrag_merge_bf_subz(m_id, i);
		}
		if (vault.tab_free[i].ptr != NULL && \
		vault.tab_free[i].ptr->adr - vault.tab_meta[m_id].size == vault.tab_meta[m_id].adr)
		{
			// ft_printf("DEFRAG BINGO after\n");
			defrag_merge_af_subz(m_id, i);
		}
		i++;
	}
}

void	tab_free_cleaner(void)
{
	long	i;
	int		found;

	found = 0;
	i = 0;
	while (i < vault.free_items_max)
	{
		// ft_putstr("i = ");
		// ft_putnbr(i);
		// ft_putstr(" -> ");
		// printAllTabFreeInfo(10);
		if (vault.tab_free[i].ptr != NULL)
		{
			// ft_putstr("step 1");
			// ft_putstr(" -> ");
			// printAllTabMetaInfo(0);
			// ft_printf("vault.tab_free[0].ptr[%p]\n", vault.tab_free[0].ptr);
			// ft_printf("vault.tab_free[1].ptr[%p]\n", vault.tab_free[1].ptr);
			// printMetaBlocInfo(127 - 1);
			// printMetaBlocInfo(127);
			// printMetaBlocInfo(127 + 1);
			if (vault.tab_free[i].ptr->type != TINY_SUBZ_FREE \
			&& vault.tab_free[i].ptr->type != SMALL_SUBZ_FREE)
			{
				// ft_putstr("step 2");
				// ft_putstr(" -> ");
				vault.tab_free[i].ptr = NULL;
			}
		}
		// ft_putstr("step 3");
		// ft_putstr("\n");
		i++;
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
			defrag(i);
			return (1);
		}
		i++;
	}
	return (-1);
}

void	ft_free(void *ptr)
{
	// ft_putstr("call ft_free\n");
	if (ptr == NULL)
		return;
	if (vault.tab_free == NULL)
	{
		// ft_printf("Before:\nvault.tab_free == [%p] && vault.tab_meta == [%p]\n", vault.tab_free, vault.tab_meta);
		// meta_data_initializer();
		// ft_printf("After:\nvault.tab_free == [%p] && vault.tab_meta == [%p]\n", vault.tab_free, vault.tab_meta);
		return;
	}
	if (search_and_free_subz(ptr) != 1) 
	{
		// ft_putstr("0000\n");
		// ft_printf("Error for object [%p]: pointer being freed was not allocated\n", ptr);
		// exit(-1);
	}
	tab_free_cleaner();
	// ft_putstr("end call ft_free\n");
}