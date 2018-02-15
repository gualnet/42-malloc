/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_show.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:29:28 by galy              #+#    #+#             */
/*   Updated: 2018/02/15 18:37:07 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ptsn_2(long i, t_meta_data *tab_show, int large)
{
	if (tab_show[i].adr != NULL)
	{
		if (tab_show[i].type == 1)
			ft_printf("TINY ZONE : %p\n", tab_show[i].adr);
		else if (tab_show[i].type == 2)
			ft_printf("SMALL ZONE : %p\n", tab_show[i].adr);
		if (tab_show[i].type == 5 || tab_show[i].type == 7)
			ft_printf("%p - %p : %ld octet(s)\n", tab_show[i].adr, \
			tab_show[i].adr + tab_show[i].size, tab_show[i].size);
		if (large == 0 && tab_show[i].type == 3)
		{
			ft_printf("LARGE ZONE\n");
			large = 1;
		}
		if (tab_show[i].type == 3)
			ft_printf("%p - %p : %ld octet(s)\n", tab_show[i].adr, \
			tab_show[i].adr + tab_show[i].size, tab_show[i].size);
	}
}

long	print_tab_show_nfo(t_meta_data *tab_show)
{
	long	i;
	long	total;
	int		large;

	i = 0;
	large = 0;
	total = 0;
	while (i < vault.meta_items_max)
	{
		ptsn_2(i, tab_show);
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
