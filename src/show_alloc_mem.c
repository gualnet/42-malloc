/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:13:25 by galy              #+#    #+#             */
/*   Updated: 2018/02/09 18:54:50 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

long	print_tab_show_nfo(t_meta_data *tab_show)
{
	long	i;
	long	total;
	int		large;

	i = 0;
	total = 0;
	large = 0;
	while (i < vault.meta_items_max)
	{
		if (tab_show[i].adr != NULL)
		{
			if (tab_show[i].type == 1)
				ft_printf("TINY ZONE : %p\n", tab_show[i].adr);
			else if (tab_show[i].type == 2)
				ft_printf("SMALL ZONE : %p\n", tab_show[i].adr);
			if (tab_show[i].type == 5 || tab_show[i].type == 7)
				ft_printf("%p - %p : %ld octet(s)\n", \
				tab_show[i].adr, tab_show[i].adr + tab_show[i].size, tab_show[i].size);
			if (large == 0 && tab_show[i].type == 3)
			{
				ft_printf("LARGE ZONE\n");
				large = 1;
			}
			if (tab_show[i].type == 3)
				ft_printf("%p - %p : %ld octet(s)\n", \
				tab_show[i].adr, tab_show[i].adr + tab_show[i].size, tab_show[i].size);
			
		}
		total += tab_show[i].size;
		tab_show[i].adr = NULL;
		tab_show[i].idx = 0;
		tab_show[i].type = FREE_BLOCK;
		tab_show[i].size = 0;
		tab_show[i].capacity = 0;
		i++;
	}
	return (total);
}

void	duplic_bloc(t_meta_data *tab_show, long id_meta)
{
	long	i;

	i = 0;
	while (i < vault.meta_items_max && tab_show[i].type != FREE_BLOCK)
		i++;

	// ft_printf("MON I %d\n", i);
	// if (i == 1 && tab_show[2].type == FREE_BLOCK)
	// 	i = 2;
	// else if (i == 2 && tab_show[1].type == FREE_BLOCK)
	// 	i = 1;
	// ft_printf("MON I %d\n", i);
	tab_show[i].adr = vault.tab_meta[id_meta].adr;
	tab_show[i].idx = i;
	tab_show[i].type = vault.tab_meta[id_meta].type;
	tab_show[i].size = vault.tab_meta[id_meta].size;
	tab_show[i].capacity = vault.tab_meta[id_meta].capacity;	
}

/*
** flag_ts : 1 = tiny | 2 = small
*/
int		loop_tiny_small(t_meta_data *tab_show, void *z_start, long id_start, int flag_ts)
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

void	show_alloc_mem(void)
{
	// ft_printf("CALL show_alloc_mem\n\n");
	int			s_state;
	long		i;
	long		total;
	t_meta_data	*tab_show;

	s_state = 1;
	i = 0;
	total = 0;
	tab_show = mmap(NULL, (getpagesize() * vault.tab_meta_npage), \
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].type == TINY_ZONE && s_state == 1)
			s_state = loop_tiny_small(tab_show, vault.tab_meta[i].adr, i, 1);
		else if (vault.tab_meta[i].type == SMALL_ZONE && s_state == 2)
			s_state = loop_tiny_small(tab_show, vault.tab_meta[i].adr, i, 2);
		if (i == vault.meta_items_max - 1)
		{
			total += print_tab_show_nfo(tab_show);
			if (s_state == 2)
				break;
			s_state += 1;
			i = -1;
		}
		i++;
	}
	loop_large(tab_show);
	total += print_tab_show_nfo(tab_show);
	ft_printf("Total : %ld octet(s)\n", total);
	munmap(tab_show, getpagesize() * vault.tab_meta_npage);
}