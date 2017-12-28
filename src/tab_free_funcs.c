/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_free_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:22:53 by galy              #+#    #+#             */
/*   Updated: 2017/12/28 17:44:49 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

int		get_tabfree_free_block(void)
{
	int i;

	i = 0;
	while (i < vault.tabfree_items_max)
	{
		ft_printf("recherche...");
		// ft_printf("%p\n", vault.tab_free[i].ptr);
		if (vault.tab_free[i].ptr == NULL)
		{
			ft_printf("(get tab free block)return i[%d]: ", i);
			return (i);
		}
		i++;
	}
	ft_printf("+_+_+_+_+ JAI BESOIN DE NOUVELLE ESPACE +_+_+_+_+_");
	// printFreeBlockInfo(vault.tab_free[i]);
	// return (&vault.tab_free[i]);
	return (-1);
}

void	tab_free_cleaner()
{
	int i;

	i = 0;
	while (i < vault.tabfree_items_max)
	{
		// ft_printf("check %p\n", vault.tab_free[i].ptr);
		if (vault.tab_free[i].ptr != NULL &&\
		(vault.tab_free[i].ptr->meta_type !=  TINY_SUBZ_FREE &&\
		 vault.tab_free[i].ptr->meta_type !=  SMALL_SUBZ_FREE))
		{
			ft_printf("VUUUUUU %p\n", vault.tab_free[i].ptr);
			vault.tab_free[i].ptr = NULL;
		}
		i++;
	}
}


void	merge_free_subz(int free_idx, int meta_idx)
{
	t_meta_data	*blksrc;
	t_meta_data	*blkdst;
	
	if (vault.tab_free[free_idx].ptr->adr < vault.tab_meta[meta_idx].adr)
	{
		ft_printf("DEFRAG MERGIN CAS 1\n");
		blksrc = vault.tab_free[free_idx].ptr;
		blkdst = &vault.tab_meta[meta_idx];

		blkdst->size += blksrc->size;
		blkdst->meta_size = NULL_SIZE;
		blkdst->meta_type = blksrc->meta_type;
		blksrc->meta_size = NULL_SIZE;
		blksrc->size = 0;
		blksrc->meta_type = FREE_BLOCK;
		blksrc->adr = NULL;
	}
	else
	{
		ft_printf("DEFRAG MERGIN CAS 2\n");
		blksrc = &vault.tab_meta[meta_idx];
		blkdst = vault.tab_free[free_idx].ptr;

		blkdst->size += blksrc->size;
		blkdst->meta_size = NULL_SIZE;
		blkdst->adr = blksrc->adr;
		blksrc->meta_size = NULL_SIZE;
		blksrc->size = 0;
		blksrc->meta_type = FREE_BLOCK;
		blksrc->adr = NULL;
	}
}