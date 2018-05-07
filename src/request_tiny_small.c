/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_tiny_small.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:26:00 by galy              #+#    #+#             */
/*   Updated: 2018/05/07 18:33:16 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	mnz_2(size_t size, void *new_zone)
{
	long	zone_bloc_idx;
	long	subz_bloc_idx;
	long	free_subz_bloc_idx;

	zone_bloc_idx = get_free_meta_block();
	g_vault.tab_meta[zone_bloc_idx].adr = new_zone;
	g_vault.tab_meta[zone_bloc_idx].type = size_to_zone_type(size);
	g_vault.tab_meta[zone_bloc_idx].capacity = size_to_zone_size(size);
	g_vault.tab_meta[zone_bloc_idx].size = 0;
	subz_bloc_idx = get_free_meta_block();
	g_vault.tab_meta[subz_bloc_idx].adr = new_zone;
	g_vault.tab_meta[subz_bloc_idx].type = size_to_subz_type(size, 1);
	g_vault.tab_meta[subz_bloc_idx].capacity = NULL_SIZE;
	g_vault.tab_meta[subz_bloc_idx].size = size_to_subz_size(size);
	free_subz_bloc_idx = get_free_free_block();
	g_vault.tab_free[free_subz_bloc_idx].ptr = &g_vault.tab_meta[subz_bloc_idx];
}

int		map_new_zone(size_t size)
{
	void	*new_zone;

	new_zone = my_mmap(size_to_zone_size(size));
	if (new_zone == MAP_FAILED)
		return (-1);
	mnz_2(size, new_zone);
	return (1);
}

/*
** rqt => requested type
*/

long	inner_loop(size_t size, long i, int step)
{
	if (step == 1)
	{
		g_vault.tab_meta[i].type = size_to_subz_type(size, 0);
		return (i);
	}
	if (step == 2)
	{
		i = split_subz(i, size);
		return (i);
	}
	return (-1);
}

long	request_tiny_small(size_t size)
{
	long			i;
	t_meta_type		rqt;

	rqt = size_to_subz_type(size, 1);
	while (1)
	{
		i = 0;
		while (i < g_vault.meta_items_max)
		{
			if (g_vault.tab_meta[i].type == rqt && \
			g_vault.tab_meta[i].size == size)
				return (inner_loop(size, i, 1));
			if (g_vault.tab_meta[i].type == rqt && \
			g_vault.tab_meta[i].size > size)
				return (inner_loop(size, i, 2));
			i++;
		}
		if (map_new_zone(size) == -1)
			return (-1);
	}
	return (-1);
}
