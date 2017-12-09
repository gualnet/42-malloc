/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_zone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 21:18:20 by galy              #+#    #+#             */
/*   Updated: 2017/12/08 21:39:30 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

/*
** return a ptr on a zone matching the type needed
** 
*/
void	*find_zone_space(t_vault *vault, size_t size)
{
	int			i;
	t_meta_type want_type;
	
	i = 0;
	want_type = size_to_zone_type(size);
	//si want_type == CUSTOM -> map_custom_zone()
	while(i < vault->meta_items_max)
	{
		if(vault->tab_meta[i].meta_type == want_type)
		{
			//jexplore en cherchant une subz
		}
		// ft_printf("vault->tab_meta[%d]: %ld\n", i, vault->tab_meta[i].meta_type);
		i++;
	}
	//si j'arrive a la fin avec i < mex-elem -1
		//j'alloue une nouvelle zone -> map_new_zone()
	//si i == max-elem - 1
		//j'etend tab-meta et je boucle
	return NULL;
}