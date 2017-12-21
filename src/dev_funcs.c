/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:41:19 by galy              #+#    #+#             */
/*   Updated: 2017/12/21 18:51:49 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	printAllTabMetaInfo(t_vault *vault, int interMax)
{
	ft_printf("\n****META TABLE INFO****\n");
	int i = 0;
	if (interMax == 0)
		interMax = vault->meta_items_max;

	while (i < interMax - 1)
	{
		ft_printf("[%p]tab_meta[%d] : adr:%p - ", &vault->tab_meta[i], i, vault->tab_meta[i].adr);
		if (vault->tab_meta[i].meta_type == FREE_BLOCK)
		ft_printf("Type: FREE_BLOCK - ");
		if (vault->tab_meta[i].meta_type == TINY_ZONE)
		ft_printf("Type: TINY_ZONE - ");
		if (vault->tab_meta[i].meta_type == SMALL_ZONE)
		ft_printf("Type: SMALL_ZONE - ");
		if (vault->tab_meta[i].meta_type == LARGE_ZONE)
		ft_printf("Type: LARGE_ZONE - ");
		if (vault->tab_meta[i].meta_type == CUSTOM_ZONE)
		ft_printf("Type: CUSTOM_ZONE - ");
		if (vault->tab_meta[i].meta_type == TINY_SUBZ_FREE)
		ft_printf("Type: TINY_SUBZ_FREE - ");
		if (vault->tab_meta[i].meta_type == TINY_SUBZ)
		ft_printf("Type: TINY_SUBZ - ");
		if (vault->tab_meta[i].meta_type == SMALL_SUBZ_FREE)
		ft_printf("Type: SMALL_SUBZ_FREE - ");
		if (vault->tab_meta[i].meta_type == SMALL_SUBZ)
		ft_printf("Type: SMALL_SUBZ - ");
		if (vault->tab_meta[i].meta_type == LARGE_SUBZ_FREE)
		ft_printf("Type: LARGE_SUBZ_FREE - ");
		if (vault->tab_meta[i].meta_type == LARGE_SUBZ)
		ft_printf("Type: LARGE_SUBZ - ");

		ft_printf("MetaSize: %d", vault->tab_meta[i].meta_size);
		ft_printf(" - Size: %d\n", vault->tab_meta[i].size);

		i++;
	}
	ft_printf("\t****************\t****************\t****************\n\n");
	// ft_printf("\n************* END Of dev func *************\n");
}

void	printTabFree(int interMax)
{
	ft_printf("\n****TAB FREE INFO****\n");
	int i;

	i = 0;
	if (interMax == 0)
		interMax = vault.tabfree_items_max;
	
	while (i < interMax)
	{
		ft_printf("[%p]tab_free[%i] - ", &vault.tab_free[i], i);
		ft_printf("metadata num [%d] - ", vault.tab_free[i].metadata_num);
		ft_printf("adr-ptr [%p] - ", vault.tab_free[i].adr);
		if (vault.tab_free[i].meta_type == FREE_BLOCK)
		ft_printf("Type: FREE_BLOCK - ");
		if (vault.tab_free[i].meta_type == TINY_ZONE)
		ft_printf("Type: TINY_ZONE - ");
		if (vault.tab_free[i].meta_type == SMALL_ZONE)
		ft_printf("Type: SMALL_ZONE - ");
		if (vault.tab_free[i].meta_type == LARGE_ZONE)
		ft_printf("Type: LARGE_ZONE - ");
		if (vault.tab_free[i].meta_type == CUSTOM_ZONE)
		ft_printf("Type: CUSTOM_ZONE - ");
		if (vault.tab_free[i].meta_type == TINY_SUBZ_FREE)
		ft_printf("Type: TINY_SUBZ_FREE - ");
		if (vault.tab_free[i].meta_type == TINY_SUBZ)
		ft_printf("Type: TINY_SUBZ - ");
		if (vault.tab_free[i].meta_type == SMALL_SUBZ_FREE)
		ft_printf("Type: SMALL_SUBZ_FREE - ");
		if (vault.tab_free[i].meta_type == SMALL_SUBZ)
		ft_printf("Type: SMALL_SUBZ - ");
		if (vault.tab_free[i].meta_type == LARGE_SUBZ_FREE)
		ft_printf("Type: LARGE_SUBZ_FREE - ");
		if (vault.tab_free[i].meta_type == LARGE_SUBZ)
		ft_printf("Type: LARGE_SUBZ - ");
		ft_printf("size [%d]\n", vault.tab_free[i].size);
		i++;
	}
}

void	printBlockMetaInfo(t_meta_data *block)
{
	ft_printf("Block Info {%p}: ", block);
	ft_printf("adr{%p} | ", block->adr);
	if (block->meta_type == FREE_BLOCK)
		ft_printf("Type: FREE_BLOCK | ");
	if (block->meta_type == TINY_ZONE)
		ft_printf("Type: TINY_ZONE | ");
	if (block->meta_type == SMALL_ZONE)
		ft_printf("Type: SMALL_ZONE | ");
	if (block->meta_type == LARGE_ZONE)
		ft_printf("Type: LARGE_ZONE | ");
	if (block->meta_type == CUSTOM_ZONE)
		ft_printf("Type: CUSTOM_ZONE | ");
	if (block->meta_type == TINY_SUBZ)
		ft_printf("Type: TINY_SUBZ | ");
	if (block->meta_type == SMALL_SUBZ)
		ft_printf("Type: SMALL_SUBZ | ");
	if (block->meta_type == LARGE_SUBZ)
		ft_printf("Type: LARGE_SUBZ | ");
	// ft_printf("type{%d} | ", block->meta_type);
	ft_printf("metasize{%d} | ", block->meta_size);
	ft_printf("size{%d}", block->size);
	ft_printf("\n****************\n");
}

void	printFreeBlockInfo(t_free_block block)
{
	ft_printf("Block Info {%p}: ", block);
	ft_printf("metadata_num{%p} | ", block.metadata_num);
	ft_printf("adr{%p} | ", block.adr);
	if (block.meta_type == FREE_BLOCK)
		ft_printf("Type: FREE_BLOCK | ");
	if (block.meta_type == TINY_ZONE)
		ft_printf("Type: TINY_ZONE | ");
	if (block.meta_type == SMALL_ZONE)
		ft_printf("Type: SMALL_ZONE | ");
	if (block.meta_type == LARGE_ZONE)
		ft_printf("Type: LARGE_ZONE | ");
	if (block.meta_type == CUSTOM_ZONE)
		ft_printf("Type: CUSTOM_ZONE | ");
	if (block.meta_type == TINY_SUBZ)
		ft_printf("Type: TINY_SUBZ | ");
	if (block.meta_type == SMALL_SUBZ)
		ft_printf("Type: SMALL_SUBZ | ");
	if (block.meta_type == LARGE_SUBZ)
		ft_printf("Type: LARGE_SUBZ | ");
	// ft_printf("type{%d} | ", block->meta_type);
	ft_printf("size{%d}", block.size);
	ft_printf("\n****************\n");
}

