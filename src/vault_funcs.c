/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vault_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:09:58 by galy              #+#    #+#             */
/*   Updated: 2017/12/28 19:41:46 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	*create_tab_meta(t_vault *vault)
{
	int i;

	i = 0;
	vault->tab_meta = mmap(NULL, (getpagesize() * META_INCRE_ALLOC_PAGE),\
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	
	if (vault->tab_meta == MAP_FAILED)
		return NULL;
	vault->tab_meta_npage = META_INCRE_ALLOC_PAGE;
	vault->meta_items_max = \
	(getpagesize() * vault->tab_meta_npage) / sizeof(t_meta_data);
	// ft_printf("Max items: %d\n", vault->meta_items_max);
	while (i < vault->meta_items_max)
	{
		vault->tab_meta[i].meta_type = FREE_BLOCK;
		vault->tab_meta[i].meta_size = NULL_SIZE;
		i++;
	}
	// ft_printf("MONVAULT: %p\n", vault);
	// printAllTabMetaInfo(vault, 0);
	return vault;
}

void	extend_tab_meta(t_vault *vault)
{
	int		cur_npage;
	void	*curtab;
	int		curtabsize;
	void	*newtab;

	cur_npage = vault->tab_meta_npage;
	curtab = vault->tab_meta;
	curtabsize = getpagesize() * cur_npage;
	newtab = mmap(NULL, curtabsize + META_INCRE_ALLOC_PAGE,\
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	ft_memcpy(newtab, curtab, curtabsize);
	munmap(curtab, curtabsize);
	vault->tab_meta = newtab;
	vault->tab_meta_npage += META_INCRE_ALLOC_PAGE;
	vault->meta_items_max =\
	(getpagesize() * vault->tab_meta_npage) / sizeof(t_meta_data);
}