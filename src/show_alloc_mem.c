/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:13:25 by galy              #+#    #+#             */
/*   Updated: 2018/03/08 20:40:51 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	duplic_bloc(t_meta_data *tab_show, long id_meta)
{
	long	i;

	i = 0;
	while (i < vault.meta_items_max && tab_show[i].type != FREE_BLOCK)
		i++;
	tab_show[i].adr = vault.tab_meta[id_meta].adr;
	tab_show[i].idx = i;
	tab_show[i].type = vault.tab_meta[id_meta].type;
	tab_show[i].size = vault.tab_meta[id_meta].size;
	tab_show[i].capacity = vault.tab_meta[id_meta].capacity;
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
	z_size = zone_type_to_size(vault.tab_meta[i].type);
	duplic_bloc(tab_show, id_start);
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].adr >= z_start && i != id_start &&\
		vault.tab_meta[i].adr < z_start + z_size)
		{
			if (flag_ts == 1 && vault.tab_meta[i].type != TINY_SUBZ_FREE)
				duplic_bloc(tab_show, i);
			else if (flag_ts == 2 && vault.tab_meta[i].type != SMALL_SUBZ_FREE)
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

void	loop_large(t_meta_data *tab_show)
{
	long	i;

	i = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].type == LARGE_ZONE)
			duplic_bloc(tab_show, i);
		i++;
	}
	order_tab_show(tab_show);
}

void	sam_2(t_meta_data *tab_show, long total)
{
	loop_large(tab_show);
	total += print_tab_show_nfo(tab_show);
	ft_printf("Total : %ld octet(s)\n", total);
	munmap(tab_show, getpagesize() * vault.tab_meta_npage);
	pthread_mutex_unlock(&vault.mutex);
}

void	show_alloc_mem(void)
{
	int			s_state;
	long		i;
	long		total;
	t_meta_data	*tab_show;

	s_state = 1;
	i = 0;
	total = 0;
	pthread_mutex_lock(&vault.mutex);
	tab_show = my_mmap(getpagesize() * vault.tab_meta_npage);
	if (tab_show == MAP_FAILED) // a foutre au propre avec var la var env
	{
		ft_putstr("BAD MMAP IN SHOW ALLOC MEM");
		exit(-1);
	}
	while (i < vault.meta_items_max || s_state == 3)
	{
		if (vault.tab_meta[i].type == TINY_ZONE && s_state == 1)
			s_state = loop_tiny_small(tab_show, vault.tab_meta[i].adr, i, 1);
		else if (vault.tab_meta[i].type == SMALL_ZONE && s_state == 2)
			s_state = loop_tiny_small(tab_show, vault.tab_meta[i].adr, i, 2);
		if (i == vault.meta_items_max - 1)
		{
			total += print_tab_show_nfo(tab_show);
			s_state += 1;
			i = -1;
		}
		i++;
	}
	sam_2(tab_show, total);
}
