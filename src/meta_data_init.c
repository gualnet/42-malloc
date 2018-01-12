/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:13:58 by galy              #+#    #+#             */
/*   Updated: 2018/01/12 19:16:45 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

int		create_tab_meta(void)
{
	unsigned int	i;

	vault.tab_meta = mmap(NULL, (getpagesize() * META_INCRE_ALLOC_PAGE),\
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (vault.tab_meta == MAP_FAILED)
		return (-1);
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
		i++;
	}
	return (1);
}

int		create_tab_free(void)
{
	unsigned int	i;
	vault.tab_free = mmap(NULL, (getpagesize() * (META_INCRE_ALLOC_PAGE)),\
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	vault.tab_free_npage = META_INCRE_ALLOC_PAGE;
	vault.free_items_max = \
	(getpagesize() * vault.tab_free_npage) / sizeof(t_free_block);

	i = 0;
	while (i < vault.free_items_max)
	{
		vault.tab_free[i].ptr = NULL;
		i++;
	}
	
	return (1);
}

int		meta_data_initializer()
{
	if (vault.tab_meta == NULL)
	{
		if (create_tab_meta() != 1)
			return (-1);
	}
	if (vault.tab_meta == NULL)
	{
		if (create_tab_free() != 1)
			return (-1);
	}	
	return (1);
}

void	resize_meta_data()
{
	int		cur_npage;
	void	*curtab;
	int		curtabsize;
	void	*newtab;

	cur_npage = vault.tab_meta_npage;
	curtab = vault.tab_meta;
	curtabsize = getpagesize() * cur_npage;

	newtab = mmap(NULL, curtabsize + (getpagesize() * META_INCRE_ALLOC_PAGE),\
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	ft_memcpy(newtab, curtab, curtabsize);
	munmap(curtab, curtabsize);
	vault.tab_meta = newtab;
	vault.tab_meta_npage += META_INCRE_ALLOC_PAGE;
	vault.meta_items_max = \
	(getpagesize() * vault.tab_meta_npage) / sizeof(t_meta_data);
	ft_printf("New max items [%d]\n", vault.meta_items_max);
}

/*
** return an empty struct to store meta infos
*/
unsigned int	get_free_meta_block()
{
	unsigned int i;
	i = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].type == FREE_BLOCK)
			break;
		i++;
	}
	if (i == vault.meta_items_max && vault.tab_meta[i - 1].type != FREE_BLOCK)
	{
		// ft_putstr("\n\n+_+_+_+_+ JAI BESOIN DE NOUVELLE ESPACE +_+_+_+_+_\n\n");
		resize_meta_data();
		if (vault.tab_meta[i + 1].type == FREE_BLOCK)
			return (i + 1);
		else
			return (-1);
	}
	return (i);
}

