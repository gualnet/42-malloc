/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_tiny_small.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:26:00 by galy              #+#    #+#             */
/*   Updated: 2018/01/12 14:30:40 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

int		map_new_zone(size_t size)
{
	t_meta_type	req_zone_type;
	void		*new_zone;
	int			i;

	i = 0;
	new_zone = NULL;
	req_zone_type = size_to_zone_type(size);
	


}

int		request_tiny_small(size_t size)
{
	unsigned int	i;
	t_meta_type		req_type;
	
	req_type = size_to_subz_type(size, 1);
	
	while (1)
	{
		i = 0;
		while (i < vault.meta_items_max)
		{
			if (vault.tab_meta[i].type == req_type && vault.tab_meta[i].size = size)
			{
				//si une subzone du bon type est libre et d'une taille egale
				// a la taille demandee.
				ft_putstr("recherche de zone cas 1\n");
				return (i);
			}
			if (vault.tab_meta[i].type == req_type && vault.tab_meta[i].size > size)
			{
				//si une subzone du bon type est libre et d'une taille plus grande
				// que la taille demandee.
				ft_putstr("recherche de zone cas 2\n");
				exit (0); // replace return (i);
			}
			i++;
		}
		map_new_zone();
	}
	return (1);
}