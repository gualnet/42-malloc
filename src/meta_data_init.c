/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:13:58 by galy              #+#    #+#             */
/*   Updated: 2018/01/11 17:10:18 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	*create_tab_meta(void)
{
	int		i;
	void	*tab_adr;

	tab_adr = mmap(NULL, (getpagesize() * META_INCRE_ALLOC_PAGE), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (vault.tab_meta == MAP_FAILED)
		return (NULL);
	vault.tab_meta_npage = META_INCRE_ALLOC_PAGE;
	vault.meta_items_max = \
	(getpagesize() * vault.tab_meta_npage) / sizeof(t_meta_data);

	i = 0;
	while (i < vault.meta_items_max)
	{
		vault.tab_meta[i].idx = i;
		vault.tab_meta[i].type = FREE_BLOCK;
		vault.tab_meta[i].capacity = NULL_SIZE;
		vault.tab_meta[i].size = 0;
	}
	return (tab_adr);
}

void	meta_data_initializer()
{
	if (vault.tab_meta == NULL)
	{
		vault.tab_meta = create_tab_meta();
	}
}