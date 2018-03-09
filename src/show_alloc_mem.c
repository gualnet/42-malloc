/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:13:25 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 19:15:27 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_2(t_meta_data *tab_show, long total)
{
	loop_large(tab_show);
	total += print_tab_show_nfo(tab_show);
	ft_printf("Total : %ld octet(s)\n", total);
	munmap(tab_show, getpagesize() * g_vault.tab_meta_npage);
	pthread_mutex_unlock(&g_vault.mutex);
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
	pthread_mutex_lock(&g_vault.mutex);
	tab_show = my_mmap(getpagesize() * g_vault.tab_meta_npage);
	if (tab_show == MAP_FAILED)
		sam_err();
	while (i < g_vault.meta_items_max && s_state < 3)
	{
		s_state = sam_inner_loop(i, s_state, tab_show);
		if (i == g_vault.meta_items_max - 1)
		{
			total += print_tab_show_nfo(tab_show);
			s_state += 1;
			i = -1;
		}
		i++;
	}
	sam_2(tab_show, total);
}
