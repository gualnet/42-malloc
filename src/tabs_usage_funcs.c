/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_usage_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:05:34 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 16:07:05 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		downsize_tab_meta(void)
{
	int		cur_npage;
	void	*curtab;
	int		curtabsize;
	void	*newtab;

	cur_npage = vault.tab_meta_npage;
	curtab = vault.tab_meta;
	curtabsize = getpagesize() * cur_npage;
	newtab = my_mmap(getpagesize() * cur_npage / 2);
	if (newtab == MAP_FAILED)
		return (-1);
	ft_memcpy(newtab, curtab, (cur_npage / 2) * getpagesize());
	munmap(curtab, curtabsize);
	vault.tab_meta = newtab;
	vault.tab_meta_npage = cur_npage / 2;
	vault.meta_items_max = \
	(getpagesize() * vault.tab_meta_npage) / sizeof(t_meta_data);
	rebuild_tab_free();
	return (1);
}

void	check_tabmeta_usage(void)
{
	long	i;
	long	nb_used;

	i = 0;
	nb_used = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].type != FREE_BLOCK)
		{
			nb_used++;
		}
		i++;
	}
	if (vault.tab_meta_npage > 1 && nb_used < vault.meta_items_max * 0.4)
		downsize_tab_meta();
}
