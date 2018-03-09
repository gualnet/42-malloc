/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_resizers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:15:06 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 18:20:52 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**	extends tab_free
**	return 1 if ok or -1 if Nok
*/

int		resize_free_data(void)
{
	void	*newtab;
	void	*curtab;
	long	cur_npage;
	long	curtabsize;

	cur_npage = g_vault.tab_free_npage;
	curtab = g_vault.tab_free;
	curtabsize = getpagesize() * cur_npage;
	newtab = my_mmap(curtabsize + (getpagesize() * META_INCRE_ALLOC_PAGE));
	if (newtab == MAP_FAILED)
		return (-1);
	ft_memcpy(newtab, curtab, curtabsize);
	munmap(curtab, curtabsize);
	g_vault.tab_free = newtab;
	g_vault.tab_free_npage += META_INCRE_ALLOC_PAGE;
	g_vault.free_items_max = \
	(getpagesize() * g_vault.tab_free_npage) / sizeof(t_free_block);
	return (1);
}

void	rebuild_tab_free(void)
{
	long			i;

	i = 0;
	while (i < g_vault.free_items_max)
	{
		g_vault.tab_free[i].ptr = NULL;
		i++;
	}
	i = 0;
	while (i < g_vault.meta_items_max)
	{
		if (g_vault.tab_meta[i].type == TINY_SUBZ_FREE ||\
		g_vault.tab_meta[i].type == SMALL_SUBZ_FREE)
		{
			g_vault.tab_free[get_free_free_block()].ptr = &g_vault.tab_meta[i];
		}
		i++;
	}
}

int		resize_meta_data(void)
{
	int		cur_npage;
	void	*curtab;
	int		curtabsize;
	void	*newtab;

	cur_npage = g_vault.tab_meta_npage;
	curtab = g_vault.tab_meta;
	curtabsize = getpagesize() * cur_npage;
	newtab = my_mmap(curtabsize + (getpagesize() * META_INCRE_ALLOC_PAGE));
	if (newtab == MAP_FAILED)
		return (-1);
	ft_memcpy(newtab, curtab, curtabsize);
	munmap(curtab, curtabsize);
	g_vault.tab_meta = newtab;
	g_vault.tab_meta_npage += META_INCRE_ALLOC_PAGE;
	g_vault.meta_items_max = \
	(getpagesize() * g_vault.tab_meta_npage) / sizeof(t_meta_data);
	rebuild_tab_free();
	return (1);
}
