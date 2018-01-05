/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_zone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 21:18:20 by galy              #+#    #+#             */
/*   Updated: 2018/01/04 21:00:34 by galy             ###   ########.fr       */
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
	// // printf("--------->want type: %d\n", wanted_type);
	//si wanted_type == CUSTOM -> map_custom_zone()
	puts("plop000");

	while(1)
	{
		while (i < vault->meta_items_max)
		{
			// printf("plop001[%d]\n", i);

			if (vault->tab_meta[i].meta_type == wanted_type &&\
			vault->tab_meta[i].size == size)
			{
				//si le type et la taille matchent..je renvoi l'index
				// // printf("find space cas 1\n");
				// printf("return 001\n");
				sleep(1);
				return (vault->tab_meta[i].adr);
			}
			else if (vault->tab_meta[i].meta_type == wanted_type &&\
			vault->tab_meta[i].size > size)
			{
				// si la taille de la subz est > que la taille demandee
				//je reduis la capacity dans le meta_block et je renvoi l'index
				// // printf("find space cas 2\n");
				meta_set_new_size(vault, &vault->tab_meta[i], size);
				// printf("return 002\n");
				sleep(1);
				return (vault->tab_meta[i].adr);
			}
			// // printf("vault->tab_meta[%d]: %ld\n", i, vault->tab_meta[i].meta_type);
			i++;
		}
		printAllTabMetaInfo(vault, 0);
		// printf("plop00===========[%d]\n", wanted_type);
		//Pas de subz assez grande en stock -> je map une nouvelle zone
		// // printf("find space cas 3\n");
		// // printf("\nInfo:\tTAB_META Begin at: [%p]\n", &(vault->tab_meta[0]));
		meta_block = get_free_meta_block(vault);
		// // printf("++Adr de meta_block [%p]\n", meta_block);
		map_new_zone(vault, meta_block, size);
		// meta_set_new_size(vault, meta_block, size);
		// return (meta_block->adr);
		i = 0;
		sleep(1);
	}
	

}

void	*check_meta_find_custom(size_t size)
{
	void	*adr;

	adr = map_large_zone(&vault, size);

	return (adr);
}