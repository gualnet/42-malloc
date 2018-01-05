/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:41:19 by galy              #+#    #+#             */
/*   Updated: 2018/01/04 21:06:01 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	printAllTabMetaInfo(t_vault *vault, int interMax)
{
	// printf("\n****META TABLE INFO****\n");
	int i = 0;
	if (interMax == 0)
		interMax = vault->meta_items_max;

	while (i < interMax - 1)
	{
		// printf("[%p]tab_meta[%d] : adr:%p - ", &vault->tab_meta[i], i, vault->tab_meta[i].adr);
		if (vault->tab_meta[i].meta_type == FREE_BLOCK)
		// printf("Type: FREE_BLOCK - ");
		if (vault->tab_meta[i].meta_type == TINY_ZONE)
		// printf("Type: TINY_ZONE - ");
		if (vault->tab_meta[i].meta_type == SMALL_ZONE)
		// printf("Type: SMALL_ZONE - ");
		if (vault->tab_meta[i].meta_type == LARGE_ZONE)
		// printf("Type: LARGE_ZONE - ");
		if (vault->tab_meta[i].meta_type == TINY_SUBZ_FREE)
		// printf("Type: TINY_SUBZ_FREE - ");
		if (vault->tab_meta[i].meta_type == TINY_SUBZ)
		// printf("Type: TINY_SUBZ - ");
		if (vault->tab_meta[i].meta_type == SMALL_SUBZ_FREE)
		// printf("Type: SMALL_SUBZ_FREE - ");
		if (vault->tab_meta[i].meta_type == SMALL_SUBZ)
		// printf("Type: SMALL_SUBZ - ");

		// printf("MetaSize: %u", vault->tab_meta[i].meta_size);
		// printf(" - Size: %zu\n", vault->tab_meta[i].size);

		i++;
	}
	// printf("\t****************\t****************\t****************\n\n");
	// // printf("\n************* END Of dev func *************\n");
}

void	printTabFree(int interMax)
{
	// printf("\n****TAB FREE INFO****\n");
	int i;

	i = 0;
	if (interMax == 0)
		interMax = vault.tabfree_items_max;
	
	while (i < interMax)
	{
		// printf("[%p]tab_free[%i] - ", &vault.tab_free[i], i);
		// printf("ptr [%p] - ", vault.tab_free[i].ptr);
		if (vault.tab_free[i].ptr != NULL)
		{
			// printf("adr-ptr [%p] - ", vault.tab_free[i].ptr->adr);
			// if (vault.tab_free[i].ptr->meta_type == FREE_BLOCK)
			// printf("Type: FREE_BLOCK - ");
			// if (vault.tab_free[i].ptr->meta_type == TINY_ZONE)
			// printf("Type: TINY_ZONE - ");
			// if (vault.tab_free[i].ptr->meta_type == SMALL_ZONE)
			// printf("Type: SMALL_ZONE - ");
			// if (vault.tab_free[i].ptr->meta_type == LARGE_ZONE)
			// printf("Type: LARGE_ZONE - ");
			// if (vault.tab_free[i].ptr->meta_type == TINY_SUBZ_FREE)
			// printf("Type: TINY_SUBZ_FREE - ");
			// if (vault.tab_free[i].ptr->meta_type == TINY_SUBZ)
			// printf("Type: TINY_SUBZ - ");
			// if (vault.tab_free[i].ptr->meta_type == SMALL_SUBZ_FREE)
			// printf("Type: SMALL_SUBZ_FREE - ");
			// if (vault.tab_free[i].ptr->meta_type == SMALL_SUBZ)
			// printf("Type: SMALL_SUBZ - ");
			// printf("size [%zu]", vault.tab_free[i].ptr->size);
		}
		// printf("\n");
		i++;
	}
}

void	printBlockMetaInfo(t_meta_data *block)
{
	block = NULL;
	// printf("Block Info {%p}: ", block);
	// printf("adr{%p} | ", block->adr);
	// if (block->meta_type == FREE_BLOCK)
		// printf("Type: FREE_BLOCK | ");
	// if (block->meta_type == TINY_ZONE)
		// printf("Type: TINY_ZONE | ");
	// if (block->meta_type == SMALL_ZONE)
		// printf("Type: SMALL_ZONE | ");
	// if (block->meta_type == LARGE_ZONE)
		// printf("Type: LARGE_ZONE | ");
	// if (block->meta_type == TINY_SUBZ)
		// printf("Type: TINY_SUBZ | ");
	// if (block->meta_type == TINY_SUBZ_FREE)
		// printf("Type: TINY_SUBZ_FREE | ");
	// if (block->meta_type == SMALL_SUBZ)
		// printf("Type: SMALL_SUBZ | ");
	// if (block->meta_type == SMALL_SUBZ_FREE)
		// printf("Type: SMALL_SUBZ_FREE | ");
	// // printf("type{%d} | ", block->meta_type);
	// printf("metasize{%d} | ", block->meta_size);
	// printf("size{%zu}", block->size);
	// printf("\n****************\n");
}

void	printfreeBlockInfo(t_free_block block)
{
	(void)block;
	// printf("Block Info {%p}: ", &block);
	// // printf("metadata_num{%p} | ", block.metadata_num);
	// // printf("adr{%p} | ", block.adr);
	// if (block.meta_type == FREE_BLOCK)
	// 	// printf("Type: FREE_BLOCK | ");
	// if (block.meta_type == TINY_ZONE)
	// 	// printf("Type: TINY_ZONE | ");
	// if (block.meta_type == SMALL_ZONE)
	// 	// printf("Type: SMALL_ZONE | ");
	// if (block.meta_type == LARGE_ZONE)
	// 	// printf("Type: LARGE_ZONE | ");
	// if (block.meta_type == TINY_SUBZ)
	// 	// printf("Type: TINY_SUBZ | ");
	// if (block.meta_type == SMALL_SUBZ)
	// 	// printf("Type: SMALL_SUBZ | ");
	// // // printf("type{%d} | ", block->meta_type);
	// // printf("size{%d}", block.size);
	// printf("\n****************\n");
}

