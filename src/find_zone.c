/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_zone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 21:18:20 by galy              #+#    #+#             */
/*   Updated: 2017/12/28 18:13:05 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

/*
** Check in meta data if there is a subzone avalaible
** Return the index of the mata data stuct, or -1
*/
void	*check_meta_find_subz(t_vault *vault, size_t size)
{
	int			i;
	t_meta_type	wanted_type;
	t_meta_data	*meta_block;
	
	i = 0;
	// wanted_type = size_to_zone_type(size);
	wanted_type = size_to_subz_type(size, 1);
	// ft_printf("--------->want type: %d\n", wanted_type);
	//si wanted_type == CUSTOM -> map_custom_zone()
	while(1)
	{
		while (i < vault->meta_items_max)
		{
			if (vault->tab_meta[i].meta_type == wanted_type &&\
			vault->tab_meta[i].size == size)
			{
				//si le type et la taille matchent..je renvoi l'index
				// ft_printf("find space cas 1\n");
				return (vault->tab_meta[i].adr);
			}
			else if (vault->tab_meta[i].meta_type == wanted_type &&\
			vault->tab_meta[i].size > size)
			{
				// si la taille de la subz est > que la taille demandee
				//je reduis la capacity dans le meta_block et je renvoi l'index
				// ft_printf("find space cas 2\n");
				meta_set_new_size(vault, &vault->tab_meta[i], size);
				return (vault->tab_meta[i].adr);
			}
			// ft_printf("vault->tab_meta[%d]: %ld\n", i, vault->tab_meta[i].meta_type);
			i++;
		}
		//Pas de subz assez grande en stock -> je map une nouvelle zone
		// ft_printf("find space cas 3\n");
		// ft_printf("\nInfo:\tTAB_META Begin at: [%p]\n", &(vault->tab_meta[0]));
		meta_block = get_free_meta_block(vault);
		// ft_printf("++Adr de meta_block [%p]\n", meta_block);
		map_new_zone(vault, meta_block, size);
		// meta_set_new_size(vault, meta_block, size);
		// return (meta_block->adr);
		i = 0;
	}
}

void	*check_meta_find_custom(size_t size)
{
	void	*adr;

	adr = map_large_zone(&vault, size);

	return (adr);
}