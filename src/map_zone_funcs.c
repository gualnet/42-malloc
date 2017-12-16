/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_zone_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:40:08 by galy              #+#    #+#             */
/*   Updated: 2017/12/16 21:11:22 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

int		map_non_custom_zone(t_vault *vault, t_meta_data *meta_block, size_t size);
void	*subdiv_subz(t_vault *vault, t_meta_data *meta_block, size_t size);

void	*map_new_zone(t_vault *vault, t_meta_data *meta_block, size_t size)
{
	int			ret;
	
	ret = 0;
	if(size_to_zone_type(size) != CUSTOM_ZONE)
		ret = map_non_custom_zone(vault, meta_block, size);
	if (ret == -1)
	{
		ft_printf("map non cust cas 1: \n");
		// printBlockMetaInfo(meta_block);
		return (NULL);
	}
	ft_printf("map non cust cas 2: %d - %d\n", meta_block->size, size);
	if(meta_block->size > size)
	{
		ft_printf("INFO: taille de block plus grand que size -> subdiv_subz()\n");
		subdiv_subz(vault, meta_block, size);
	}
	// printBlockMetaInfo(meta_block);
	return (meta_block);

}

/*
**	split a subz
**	return the adress of the subz at the requested size
*/
void	*subdiv_subz(t_vault *vault, t_meta_data *meta_block, size_t size)
{
	ft_printf("vault: %p\n", vault);
	ft_printf("meta_block: %p\n", meta_block);
	ft_printf("size: %d\n", size);
	return NULL;
}

int 	map_non_custom_zone(t_vault *vault, t_meta_data *meta_block, size_t size)
{
	ft_printf("CALL map_non_custom_zone()\n");
	int			i;
	void		*new_zone;
	t_meta_data	*subz_meta_block;

	i = 0;
	new_zone = mmap(NULL, size_to_zone_type(size), PROT_READ | PROT_WRITE,\
	MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if(new_zone == MAP_FAILED)
	{
		ft_printf("err[mzf000]: mmap failure\n");
		return (-1);
	}
	meta_block->adr = new_zone;
	meta_block->meta_type = size_to_zone_type(size);
	meta_block->meta_size = size_to_zone_size(size);
	subz_meta_block = get_free_meta_block(vault);
	// printBlockMetaInfo(subz_meta_block);
	subz_meta_block->adr = new_zone;
	subz_meta_block->meta_type = size_to_subz_type(size, 1);
	subz_meta_block->size = size_to_zone_size(size);
	ft_printf("\n****NEW ZONE ALLOC****\n");
	ft_printf("*-zone meta-data-*\n");
	ft_printf("adr: %p - TYPE: %d - METASIZE: %d - SIZE\n", meta_block->adr, meta_block->meta_type, meta_block->meta_size);
	ft_printf("*-subz meta-data-*\n");
	ft_printf("adr: %p - TYPE: %d - METASIZE: %d\n", subz_meta_block->adr, subz_meta_block->meta_type, subz_meta_block->size);
	ft_printf("**********************\n\n");
	return (1);
}

// void	*map_custom_zone(t_vault *vault)
// {
// 	void	*new_zone;
// 	int		i;

// 	i = 0;
// 	new_zone = mmap(NULL, TINY_ZONE_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
// 	while(i < vault->meta_items_max)
// 	{
// 		if(vault->tab_meta[i].meta_type == FREE_BLOCK)
// 			break;
// 		i++;
// 	}
// 	vault->tab_meta[i].adr = new_zone;
// 	vault->tab_meta[i].meta_type = TINY_ZONE;
// 	vault->tab_meta[i].meta_size = TINY_ZONE_SIZE;
// 	ft_printf("\n****NEW TINY ALLOC****\n");
// 	ft_printf("adr: %p - TYPE: TINY - SIZE: %d\n", new_zone, TINY_ZONE_SIZE);
// 	ft_printf("**********************\n\n");
// 	return new_zone;
// }