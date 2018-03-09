/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:13:25 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 19:15:34 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	duplic_bloc(t_meta_data *tab_show, long id_meta)
{
	long	i;

	i = 0;
	while (i < g_vault.meta_items_max && tab_show[i].type != FREE_BLOCK)
		i++;
	tab_show[i].adr = g_vault.tab_meta[id_meta].adr;
	tab_show[i].idx = i;
	tab_show[i].type = g_vault.tab_meta[id_meta].type;
	tab_show[i].size = g_vault.tab_meta[id_meta].size;
	tab_show[i].capacity = g_vault.tab_meta[id_meta].capacity;
}

void	loop_large(t_meta_data *tab_show)
{
	long	i;

	i = 0;
	while (i < g_vault.meta_items_max)
	{
		if (g_vault.tab_meta[i].type == LARGE_ZONE)
			duplic_bloc(tab_show, i);
		i++;
	}
	order_tab_show(tab_show);
}

/*
** flag_ts : 1 = tiny | 2 = small
*/

int		loop_tiny_small(t_meta_data *tab_show, void *z_start, \
long id_start, int flag_ts)
{
	long	i;
	size_t	z_size;

	i = 0;
	z_size = zone_type_to_size(g_vault.tab_meta[i].type);
	duplic_bloc(tab_show, id_start);
	while (i < g_vault.meta_items_max)
	{
		if (g_vault.tab_meta[i].adr >= z_start && i != id_start &&\
		g_vault.tab_meta[i].adr < z_start + z_size)
		{
			if (flag_ts == 1 && g_vault.tab_meta[i].type != TINY_SUBZ_FREE)
				duplic_bloc(tab_show, i);
			else if (flag_ts == 2 && \
			g_vault.tab_meta[i].type != SMALL_SUBZ_FREE)
				duplic_bloc(tab_show, i);
		}
		i++;
	}
	order_tab_show(tab_show);
	if (flag_ts == 1)
		return (1);
	else
		return (2);
}

int		sam_inner_loop(long i, int s_state, t_meta_data *tab_show)
{
	if (s_state == 1 && g_vault.tab_meta[i].type == TINY_ZONE)
		s_state = loop_tiny_small(tab_show, g_vault.tab_meta[i].adr, i, 1);
	else if (s_state == 2 && g_vault.tab_meta[i].type == SMALL_ZONE)
		s_state = loop_tiny_small(tab_show, g_vault.tab_meta[i].adr, i, 2);
	return (s_state);
}
