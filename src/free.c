/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:43:59 by galy              #+#    #+#             */
/*   Updated: 2017/12/28 19:41:52 by galy             ###   ########.fr       */
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
	// ft_printf("\nmax items = %d\n", vault.meta_items_max);
	while (i < vault.meta_items_max)
	{
		// ft_printf("vault.tab_meta[%d].adr [%p] -- ptr [%p]\n", i, vault.tab_meta[i].adr, ptr);
		if (vault.tab_meta[i].adr == ptr &&\
		(vault.tab_meta[i].meta_type == TINY_SUBZ ||\
		 vault.tab_meta[i].meta_type == SMALL_SUBZ ||\
		 vault.tab_meta[i].meta_type == LARGE_ZONE))
		{
			// ft_printf("bingo\n");
			return (i);
		}
		i++;
	}
	return -1;
}

int check_defrag(int index)
{
	// ft_printf("\tCALL DEFRAG\n");
	int i;

	i = 0;
	index = 0 + index;
	while (i < vault.tabfree_items_max)
	{
		// ft_printf("\tDEFRAG LOOP[%d]: [%d]+[%d]=[%d]\n",\
		// vault.tab_free[i].ptr.adr);
		if (vault.tab_free[i].ptr != NULL &&\
		(vault.tab_free[i].ptr->adr == vault.tab_meta[index].adr + vault.tab_meta[index].size + 1))
		{
			// ft_printf("defrag bingoooooooooo\n");
			merge_free_subz(i, index);
			return (1);
		}
		i++;
	}
	return -1;
}

void	change_metadata_status(int i)
{
	int free_id;
	
	if (vault.tab_meta[i].meta_type == TINY_SUBZ)
		vault.tab_meta[i].meta_type = TINY_SUBZ_FREE;
	else if (vault.tab_meta[i].meta_type == SMALL_SUBZ)
		vault.tab_meta[i].meta_type = SMALL_SUBZ_FREE;
	
	free_id = get_tabfree_free_block();
	vault.tab_free[free_id].ptr = &vault.tab_meta[i];
	
	if (check_defrag(i) == 1)
		return;
}

/*
** unmap d'une zone
*/
void	throw_zone(t_meta_data	*meta_block)
{
	// ft_printf("CALL TRHOW ZONE\n");
	// printBlockMetaInfo(meta_block);
	munmap(meta_block->adr, meta_block->size);
	meta_block->meta_size = NULL_SIZE;
	meta_block->size = 0;
	meta_block->meta_type = FREE_BLOCK;
	meta_block->adr = NULL;
	// exit (0);

}

void	create_tab_free(void)
{
	vault.tab_free = mmap(NULL, (getpagesize() * (META_INCRE_ALLOC_PAGE / 2)),\
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	vault.tabfree_items_max = (getpagesize() * (META_INCRE_ALLOC_PAGE / 2))\
	/ sizeof(t_free_block);
	// ft_printf("tab_free max items %d\n", vault.tabfree_items_max);
}

void	ft_free(void *ptr)
{
	int index;
	// ft_printf("\n\tCALL FREEE ptr[%p]\n", ptr);
	// ft_printf("00INSPECTOR tab_free [%p]\n", vault.tab_free);
	// printAllTabMetaInfo(vault, 10);
	if (vault.tab_free == NULL)
		create_tab_free();
	if (ptr != NULL && vault.tab_free != NULL)
	{
		//parcours de ma liste de meta donnees à la recherche du ptr
		//si le ptr est trouve -> changement du status dans le bloc de meta donnees +
		// + parcours de ma liste d'espace free
		// ...si espace free connex trouve, j'accroche les deux espaces libre au niveau de ma meta data et je raz le block non occupé
		// ...sinon ajout de la zone libre dans ma liste d'espace free.
		//-------------------
		if ((index = verif_ptr_validity(ptr)) == -1)
			return ;
		// ft_printf("\nAV:");
		// printAllTabMetaInfo(&vault, 8);
		// printTabFree(8);
		if (vault.tab_meta[index].meta_type != LARGE_ZONE)
			change_metadata_status(index);
		else
			throw_zone(&vault.tab_meta[index]);

		tab_free_cleaner();
	}
	// ft_printf("\n\nAP:");
	// printAllTabMetaInfo(&vault, 8);
	// printTabFree(8);
	// ft_printf("\n\tEND FREEE ptr[%p]\n", ptr);
}