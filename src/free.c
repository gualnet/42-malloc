/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:43:59 by galy              #+#    #+#             */
/*   Updated: 2017/12/21 19:17:17 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

/*
**	return the index of the tab_meta_block where is ref ptr
**	else return -1
*/
int		verif_ptr_validity(void *ptr)
{
	int i;

	i = 0;
	ft_printf("\nmax items = %d\n", vault.meta_items_max);
	while (i < vault.meta_items_max)
	{
		// ft_printf("vault.tab_meta[%d].adr [%p] -- ptr [%p]\n", i, vault.tab_meta[i].adr, ptr);
		if (vault.tab_meta[i].adr == ptr &&\
		(vault.tab_meta[i].meta_type == TINY_SUBZ ||\
		vault.tab_meta[i].meta_type == SMALL_SUBZ ||\
		vault.tab_meta[i].meta_type == LARGE_SUBZ))
		{
			ft_printf("bingo\n");
			return (i);
		}
		i++;
	}
	return -1;
}

int check_defrag(int index)
{
	ft_printf("\tCALL DEFRAG\n");
	int i;

	i = 0;
	while (i < vault.tabfree_items_max)
	{
		// ft_printf("\tDEFRAG LOOP[%d]: [%d]+[%d]=[%d]\n",\
		// i, vault.tab_free[i].adr, vault.tab_free[i].size, vault.tab_meta[index].adr);
		if (vault.tab_free[i].adr + vault.tab_free[i].size + 1 == vault.tab_meta[index].adr)
		{
			vault.tab_free[i].size += vault.tab_meta[index].size;
			vault.tab_meta[vault.tab_free[i].metadata_num].size = vault.tab_free[i].size;
			vault.tab_meta[index].adr = NULL;
			vault.tab_meta[index].meta_type = FREE_BLOCK;
			vault.tab_meta[index].meta_size = NULL_SIZE;
			vault.tab_meta[index].size = 0;
			return (1);
		}
		i++;
	}
	return -1;
}

void	change_metadata_status(int i)
{
	t_free_block	*tabfree_block;
	
	if (vault.tab_meta[i].meta_type == TINY_SUBZ)
		vault.tab_meta[i].meta_type = TINY_SUBZ_FREE;
	else if (vault.tab_meta[i].meta_type == SMALL_SUBZ)
		vault.tab_meta[i].meta_type = SMALL_SUBZ_FREE;
	if (check_defrag(i) == 1)
		return;
	tabfree_block = get_tabfree_free_block();
	tabfree_block->metadata_num = i;
	tabfree_block->adr = vault.tab_meta[i].adr;
	tabfree_block->meta_type = vault.tab_meta[i].meta_type;
	tabfree_block->size = vault.tab_meta[i].size;
	
	// else if (vault.tab_meta[i].meta_type == LARGE_SUBZ)
}

void	create_tab_free(void)
{
	vault.tab_free = mmap(NULL, (getpagesize() * (META_INCRE_ALLOC_PAGE / 2)),\
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	vault.tabfree_items_max = (getpagesize() * (META_INCRE_ALLOC_PAGE / 2))\
	/ sizeof(t_free_block);
	ft_printf("tab_free max items %d\n", vault.tabfree_items_max);
}

void	ft_free(void *ptr)
{
	int index;
	ft_printf("\n\tCALL FREEE ptr[%p]\n", ptr);
	ft_printf("\n\t00INSPECTOR tab_free [%p]\n", vault.tab_free);
	// printAllTabMetaInfo(vault, 10);
	if (vault.tab_free == NULL)
		create_tab_free();
	if (ptr != NULL && vault.tab_free != NULL)
	{
		ft_printf("\n\t11INSPECTOR tab_free [%p]\n", vault.tab_free);
		//parcours de ma liste de meta donnees à la recherche du ptr
		//si le ptr est trouve -> changement du status dans le bloc de meta donnees +
		// + parcours de ma liste d'espace free
		// ...si espace free connex trouve, j'accroche les deux espaces libre au niveau de ma meta data et je raz le block non occupé
		// ...sinon ajout de la zone libre dans ma liste d'espace free.
		//-------------------
		if ((index = verif_ptr_validity(ptr)) == -1)
			return ;
		change_metadata_status(index);

	}
	printAllTabMetaInfo(&vault, 10);
	printTabFree(10);
	ft_printf("\n\tEND FREEE ptr[%p]\n", ptr);
}


