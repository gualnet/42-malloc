/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_tiny_small.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:26:00 by galy              #+#    #+#             */
/*   Updated: 2018/01/18 16:22:42 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"


int		map_new_zone(size_t size)
{
	ft_putstr("MAP NEW ZONE\n");
	unsigned int	zone_bloc_idx;
	unsigned int	subz_bloc_idx;
	unsigned int	free_subz_bloc_idx;
	void			*new_zone;

	new_zone = mmap(NULL, size_to_zone_size(size), PROT_READ | PROT_WRITE,\
	MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (new_zone == MAP_FAILED)
	{
		if (DEBUG_MALLOC)
			ft_putstr("mmap error 000: in request_tiny_small.c line 21\n");
		return (-1);
	}
	zone_bloc_idx = get_free_meta_block();
	vault.tab_meta[zone_bloc_idx].adr = new_zone;
	vault.tab_meta[zone_bloc_idx].type = size_to_zone_type(size);
	vault.tab_meta[zone_bloc_idx].capacity = size_to_zone_size(size);
	vault.tab_meta[zone_bloc_idx].size = 0;
	subz_bloc_idx = get_free_meta_block();
	vault.tab_meta[subz_bloc_idx].adr = new_zone;
	vault.tab_meta[subz_bloc_idx].type = size_to_subz_type(size, 1);
	vault.tab_meta[subz_bloc_idx].capacity = NULL_SIZE;
	
	vault.tab_meta[subz_bloc_idx].size = size_to_subz_size(size);
	free_subz_bloc_idx = get_free_free_block();
	vault.tab_free[free_subz_bloc_idx].ptr = &vault.tab_meta[subz_bloc_idx];
	return (1);
}

unsigned int	request_tiny_small(size_t size)
{
	unsigned int	i;
	t_meta_type		req_type;
	
	req_type = size_to_subz_type(size, 1);
	
	while (1)
	{
		i = 0;
		while (i < vault.meta_items_max)
		{
			if (vault.tab_meta[i].type == req_type && vault.tab_meta[i].size == size)
			{
				//si une subzone du bon type est libre et d'une taille egale
				// a la taille demandee.
				ft_putstr("recherche de zone cas 1\n");
				//virer la zone de tab_free
				return (i);
			}
			if (vault.tab_meta[i].type == req_type && vault.tab_meta[i].size > size)
			{
				//si une subzone du bon type est libre et d'une taille plus grande
				// que la taille demandee.
				// ft_printf("i = %d - recherche de zone cas 2\n", i);
				i = split_subz(i, size);
				return (i);
			}
			i++;
		}
		if (map_new_zone(size) == -1)
			return (-1);
	}
	return (-1);
}