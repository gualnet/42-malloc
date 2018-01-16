/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:52:42 by galy              #+#    #+#             */
/*   Updated: 2018/01/16 19:30:00 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	printCreateMetaTabCR()
{
	ft_printf("\n\tcreation de tab_meta:\n");
	ft_printf("vault.tab_meta[%p]\n", vault.tab_meta);
	ft_printf("Nombre de pages allouees[%d]\n", vault.tab_meta_npage);
	ft_printf("taille de mata struct[%d]\n", sizeof(t_meta_data));
	ft_printf("(getpagesize()[%d] * vault.tab_meta_npage[%d]) / sizeof(t_meta_data)[%d]\n", getpagesize(), vault.tab_meta_npage, sizeof(t_meta_data));
	ft_printf("Nombre d'items max[%d]\n", vault.meta_items_max);
}

void	printCreateFreeTabCR()
{
	ft_printf("\n\tcreation de tab_free:\n");
	ft_printf("vault.tab_free[%p]\n", vault.tab_free);
	ft_printf("Nombre de pages allouees[%d]\n", vault.tab_free_npage);
	ft_printf("taille de mata struct[%d]\n", sizeof(t_meta_data));
	ft_printf("(getpagesize()[%d] * vault.tab_meta_npage[%d]) / sizeof(t_free_block)[%d]\n", getpagesize(), vault.tab_free_npage, sizeof(t_free_block));
	ft_printf("Nombre d'items max[%d]\n", vault.free_items_max);

}

void	printMetaBlocInfo(unsigned int id)
{
	ft_printf("\nMeta Bloc id: %d\n", id);
	ft_printf("adr [%p] - ", vault.tab_meta[id].adr);
	if (vault.tab_meta[id].type == FREE_BLOCK)
	ft_printf("Type: FREE_BLOCK - ");
	if (vault.tab_meta[id].type == TINY_ZONE)
	ft_printf("Type: TINY_ZONE - ");
	if (vault.tab_meta[id].type == SMALL_ZONE)
	ft_printf("Type: SMALL_ZONE - ");
	if (vault.tab_meta[id].type == LARGE_ZONE)
	ft_printf("Type: LARGE_ZONE - ");
	if (vault.tab_meta[id].type == TINY_SUBZ_FREE)
	ft_printf("Type: TINY_SUBZ_FREE - ");
	if (vault.tab_meta[id].type == TINY_SUBZ)
	ft_printf("Type: TINY_SUBZ - ");
	if (vault.tab_meta[id].type == SMALL_SUBZ_FREE)
	ft_printf("Type: SMALL_SUBZ_FREE - ");
	if (vault.tab_meta[id].type == SMALL_SUBZ)
	ft_printf("Type: SMALL_SUBZ - ");

	ft_printf("capacity [%d] - ", vault.tab_meta[id].capacity);
	ft_printf("size [%d]\n", vault.tab_meta[id].size);
}

void	printFreeBlocInfo(unsigned int id)
{
	ft_printf("\nFree Bloc id: %d\n", id);
	if (vault.tab_free[id].ptr != NULL)
	{
		ft_printf("ptr [%p] - ", vault.tab_free[id].ptr->adr);
		if (vault.tab_free[id].ptr->type == FREE_BLOCK)
			ft_printf("Type: FREE_BLOCK - ");
		if (vault.tab_free[id].ptr->type == TINY_ZONE)
			ft_printf("Type: TINY_ZONE - ");
		if (vault.tab_free[id].ptr->type == SMALL_ZONE)
			ft_printf("Type: SMALL_ZONE - ");
		if (vault.tab_free[id].ptr->type == LARGE_ZONE)
			ft_printf("Type: LARGE_ZONE - ");
		if (vault.tab_free[id].ptr->type == TINY_SUBZ_FREE)
			ft_printf("Type: TINY_SUBZ_FREE - ");
		if (vault.tab_free[id].ptr->type == TINY_SUBZ)
			ft_printf("Type: TINY_SUBZ - ");
		if (vault.tab_free[id].ptr->type == SMALL_SUBZ_FREE)
			ft_printf("Type: SMALL_SUBZ_FREE - ");
		if (vault.tab_free[id].ptr->type == SMALL_SUBZ)
			ft_printf("Type: SMALL_SUBZ - ");

		ft_printf("capacity [%d] - ", vault.tab_free[id].ptr->capacity);
		ft_printf("size [%d]\n", vault.tab_free[id].ptr->size);
	}
	
}

void	printAllTabMetaInfo(unsigned int interMax)
{
	printf("\n****META TABLE INFO****\n");
	unsigned int i = 0;
	if (interMax == 0)
		interMax = vault.meta_items_max;

	while (i < interMax - 1)
	{
		printf("[%p]tab_meta[%d] : adr:%p - ", &vault.tab_meta[i], i, vault.tab_meta[i].adr);
		if (vault.tab_meta[i].type == FREE_BLOCK)
		printf("Type: FREE_BLOCK - ");
		if (vault.tab_meta[i].type == TINY_ZONE)
		printf("Type: TINY_ZONE - ");
		if (vault.tab_meta[i].type == SMALL_ZONE)
		printf("Type: SMALL_ZONE - ");
		if (vault.tab_meta[i].type == LARGE_ZONE)
		printf("Type: LARGE_ZONE - ");
		if (vault.tab_meta[i].type == TINY_SUBZ_FREE)
		printf("Type: TINY_SUBZ_FREE - ");
		if (vault.tab_meta[i].type == TINY_SUBZ)
		printf("Type: TINY_SUBZ - ");
		if (vault.tab_meta[i].type == SMALL_SUBZ_FREE)
		printf("Type: SMALL_SUBZ_FREE - ");
		if (vault.tab_meta[i].type == SMALL_SUBZ)
		printf("Type: SMALL_SUBZ - ");

		printf("Capacity: %u", vault.tab_meta[i].capacity);
		printf(" - Size: %zu\n", vault.tab_meta[i].size);

		i++;
	}
	// printf("\t****************\t****************\t****************\n\n");
	// // printf("\n************* END Of dev func *************\n");
}

void	printAllTabFreeInfo(unsigned int interMax)
{
	printf("\n****META FREE INFO****\n");
	unsigned int i = 0;
	if (interMax == 0)
		interMax = vault.free_items_max;

	while (i < interMax - 1)
	{
		ft_printf("[%p]tab_free[%d] : ptr:%p - ", &vault.tab_free[i], i, vault.tab_free[i].ptr);
		if (vault.tab_free[i].ptr != NULL)
		{
			if (vault.tab_free[i].ptr->type == FREE_BLOCK)
				ft_printf("Type: FREE_BLOCK - ");
			if (vault.tab_free[i].ptr->type == TINY_ZONE)
				ft_printf("Type: TINY_ZONE - ");
			if (vault.tab_free[i].ptr->type == SMALL_ZONE)
				ft_printf("Type: SMALL_ZONE - ");
			if (vault.tab_free[i].ptr->type == LARGE_ZONE)
				ft_printf("Type: LARGE_ZONE - ");
			if (vault.tab_free[i].ptr->type == TINY_SUBZ_FREE)
				ft_printf("Type: TINY_SUBZ_FREE - ");
			if (vault.tab_free[i].ptr->type == TINY_SUBZ)
				ft_printf("Type: TINY_SUBZ - ");
			if (vault.tab_free[i].ptr->type == SMALL_SUBZ_FREE)
				ft_printf("Type: SMALL_SUBZ_FREE - ");
			if (vault.tab_free[i].ptr->type == SMALL_SUBZ)
				ft_printf("Type: SMALL_SUBZ - ");

			printf("Capacity: %u", vault.tab_free[i].ptr->capacity);
			printf(" - Size: %zu\n", vault.tab_free[i].ptr->size);
		}
		else
			printf("No Info\n");
		i++;
	}
	printf("\t****************\t****************\t****************\n\n");
	// printf("\n************* END Of dev func *************\n");
}