/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_data_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:39:55 by galy              #+#    #+#             */
/*   Updated: 2017/12/26 16:19:42 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

/*
** Return the defined zone-type which will contain the new sub-zone.
*/
t_meta_type	size_to_zone_type(size_t size)
{
	if (size >= TINY_ALLOC_MIN && size <= TINY_ALLOC_MAX)
		return TINY_ZONE;
	else if (size >= SMALL_ALLOC_MIN && size <= SMALL_ALLOC_MAX)
		return SMALL_ZONE;
	else if (size >= LARGE_ALLOC_MIN)
		return LARGE_ZONE;
}

/*
** Return the defined zone-size which will contain the new sub-zone.
*/
t_meta_size	size_to_zone_size(size_t size)
{
	if (size >= TINY_ALLOC_MIN && size <= TINY_ALLOC_MAX)
		return TINY_ZONE_SIZE;
	else if (size >= SMALL_ALLOC_MIN && size <= SMALL_ALLOC_MAX)
		return SMALL_ZONE_SIZE;
	// else if (size >= LARGE_ALLOC_MIN)
	// 	return LARGE_ZONE_SIZE;
}

/*
** Return the defined subz-type which will contain the data.
*/
t_meta_type	size_to_subz_type(size_t size, int flag_free)
{
	if (size >= TINY_ALLOC_MIN && size <= TINY_ALLOC_MAX)
	{
		if (flag_free == 1)
			return TINY_SUBZ_FREE;
		return TINY_SUBZ;
	}
	else if (size >= SMALL_ALLOC_MIN && size <= SMALL_ALLOC_MAX)
	{
		if (flag_free == 1)
			return SMALL_SUBZ_FREE;
		return SMALL_SUBZ;
	}
	else
		return LARGE_ZONE;
}

/*
** return an empty struct to store meta infos
*/
t_meta_data	*get_free_meta_block(t_vault *vault)
{
	int i;

	i = 0;
	while(i < vault->meta_items_max)
	{
		if (vault->tab_meta[i].meta_type == FREE_BLOCK)
			break;
		i++;
	}
	if (vault->tab_meta[i].meta_type != FREE_BLOCK &&\
	i == vault->meta_items_max)
	{
		ft_printf("\n\n+_+_+_+_+ JAI BESOIN DE NOUVELLE ESPACE +_+_+_+_+_\n\n");
	}
	// ft_printf("(get free meta block)return: ");
	// printBlockMetaInfo(&vault->tab_meta[i]);
	return (&(vault->tab_meta[i]));
}

/*
** set a meta-block-size to the new assigned size
*/
void	meta_set_new_size(t_vault *vault, t_meta_data *meta_block, size_t size)
{
	int 		old_size;
	t_meta_data	*free_block;
	t_free_block	*tabfree_block;

	
	ft_printf("\n\tCALL META_SET_NEW_SIZE\n");
	// ft_printf("bf old block data: ");
	printBlockMetaInfo(meta_block);
	old_size = meta_block->size;
	meta_block->size = size;
	meta_block->meta_type = size_to_subz_type(size, 0);
	// ft_printf("af old block data: ");
	printBlockMetaInfo(meta_block);
	// --------------------
	//à verifier..
	free_block = get_free_meta_block(vault);
	free_block->adr = meta_block->adr + meta_block->size + 1;////////////////////////////
	free_block->meta_type = size_to_subz_type(size, 1);
	free_block->size = old_size - meta_block->size;

	tabfree_block = &vault->tab_free[get_tabfree_free_block()];
	tabfree_block->ptr = free_block;
	// printAllTabMetaInfo(vault, 8);
	// printTabFree(8);
	// ft_printf("af old block data: ");
	// printBlockMetaInfo(free_block);
	//-----------------..
}

void		*check_meta_data(t_vault *vault, size_t size)
{
	ft_printf("check_meta_data - size: %d\n", size);
	
	if (vault->tab_meta == NULL)
	{
		// ft_printf("*************\n");
		// ft_printf("std1 &vault: %p | std1 vault: %p\n", &vault, vault);
		// ft_printf("*************\n");
		vault = create_tab_meta(vault);
		// ft_printf("std2 &vault: %p | std2 vault: %p\n", &vault, vault);
		// ft_printf("*************\n\n");
		if (vault->tab_free == NULL)
			create_tab_free();
	}
	// ft_printf("std3 &vault: %p | std3 vault: %p\n", &vault, vault);
	// ft_printf("*************\n\n");

	// return find_free_subz(vault, size);
	return vault;
}