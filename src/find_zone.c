/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_zone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 21:18:20 by galy              #+#    #+#             */
/*   Updated: 2017/12/13 20:00:12 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

/*
** Check in meta data if there is a subzone avalaible
** Return the index of the mata data stuct, or -1
*/
int		check_meta_if_space_avalaible(t_vault *vault, size_t size)
{
	int			i;
	t_meta_type want_type;
	
	i = 0;
	want_type = size_to_zone_type(size);
	//si want_type == CUSTOM -> map_custom_zone()
	while (i < vault->meta_items_max)
	{
		if (vault->tab_meta[i].meta_type == want_type &&\
		vault->tab_meta[i].meta_size == size)
		{
			//si le type et la taille matchent..je renvoi l'index
			return (i);
		}
		else if (vault->tab_meta[i].meta_type == want_type &&\
		vault->tab_meta[i].meta_size == size)
		{
			// si la taille de la subz est > que la taille demandee
			//je reduis la capacity dans le meta_block et je renvoi l'index
			meta_set_new_size(vault->tab_meta[i], size);
		}
		// ft_printf("vault->tab_meta[%d]: %ld\n", i, vault->tab_meta[i].meta_type);
		i++;
	}
	return (-1);
}
/*
** return a ptr on a zone matching the type needed
** 
*/
// void	*find_zone_space(t_vault *vault, size_t size)
// {
	
// 	//si j'arrive ici je refais une passe pour trouver 
// 	//un emplacement de meta libre ou etendre mon espace de meta data.
// 	if ((i = parse_step_2(vault, size)) != -1)
		
// 	return NULL;
// }

/*
** Look for free meta data block
** return the index of a free meta data block or -1 if no block is free
*/
// int		parse_step_2(t_vault *vault, size_t size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < vault->meta_items_max)
// 	{
// 		if (vault->tab_meta[i].meta_type == FREE_BLOCK)
// 		{
// 			map_new_zone(vault->tab_meta[i], size);
// 			return (i);
// 		}
// 	}
// 	return (-1);
// }