/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_data_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:39:55 by galy              #+#    #+#             */
/*   Updated: 2017/12/13 20:07:44 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

/*
** Return the defined zone-type which will contain the new sub-zone.
*/
t_meta_type	size_to_zone_type(size_t size)
{
	if(size >= TINY_ALLOC_MIN && size <= TINY_ALLOC_MAX)
		return TINY_ZONE;
	else if(size >= SMALL_ALLOC_MIN && size <= SMALL_ALLOC_MAX)
		return SMALL_ZONE;
	else if(size >= LARGE_ALLOC_MIN && size <= LARGE_ALLOC_MAX)
		return LARGE_ZONE;
	else
		return CUSTOM_ZONE;
}

/*
** Return the defined zone-size which will contain the new sub-zone.
*/
t_meta_size	size_to_zone_size(size_t size)
{
	if(size >= TINY_ALLOC_MIN && size <= TINY_ALLOC_MAX)
		return TINY_ZONE_SIZE;
	else if(size >= SMALL_ALLOC_MIN && size <= SMALL_ALLOC_MAX)
		return SMALL_ZONE_SIZE;
	else if(size >= LARGE_ALLOC_MIN && size <= LARGE_ALLOC_MAX)
		return LARGE_ZONE_SIZE;
	else
		return CUSTOM_SIZE;
}

/*
** Return the defined subz-type which will contain the data.
*/
t_meta_type	size_to_subz_type(size_t size)
{
	if(size >= TINY_ALLOC_MIN && size <= TINY_ALLOC_MAX)
		return TINY_SUBZ;
	else if(size >= SMALL_ALLOC_MIN && size <= SMALL_ALLOC_MAX)
		return SMALL_SUBZ;
	else if(size >= LARGE_ALLOC_MIN && size <= LARGE_ALLOC_MAX)
		return LARGE_SUBZ;
}

/*
** return an empty struct to store meta infos
*/
t_meta_data	get_free_meta_store(t_vault *vault)
{
	int i;

	i = 0;
	while(i < vault->meta_items_max)
	{
		if(vault->tab_meta[i].meta_type == FREE_BLOCK)
			break;
	}
	if(vault->tab_meta[i].meta_type != FREE_BLOCK &&\
	i == (vault->meta_items_max - 1))
	{
		ft_printf("+_+_+_+_+ JAI BESOIN DE NOUVELLE ESPACE +_+_+_+_+_");
	}
	return vault->tab_meta[i];
}

void		*check_meta_data(t_vault *vault, size_t size)
{
	ft_printf("check_meta_data - size: %d\n", size);
	
	if (vault == NULL)
	{
		// ft_printf("*************\n");
		// ft_printf("std1 &vault: %p | std1 vault: %p\n", &vault, vault);
		// ft_printf("*************\n");
		vault = create_vault(vault);
		// ft_printf("std2 &vault: %p | std2 vault: %p\n", &vault, vault);
		// ft_printf("*************\n\n");
	}
	// ft_printf("std3 &vault: %p | std3 vault: %p\n", &vault, vault);
	// ft_printf("*************\n\n");

	// return find_free_subz(vault, size);
	return vault;
}

void	meta_set_new_size(t_meta_data meta_block, size_t size)
{
	meta_block.size = meta_block.size;
}