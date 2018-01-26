/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:13:58 by galy              #+#    #+#             */
/*   Updated: 2018/01/26 18:59:19 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

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
	if (vault.tab_free == NULL)
	{
		if (create_tab_free() != 1)
			return (-1);
	}	
	return (1);
}

int		resize_meta_data()
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
	if (newtab == MAP_FAILED)
		return (-1);
	ft_memcpy(newtab, curtab, curtabsize);
	munmap(curtab, curtabsize);
	vault.tab_meta = newtab;
	vault.tab_meta_npage += META_INCRE_ALLOC_PAGE;
	vault.meta_items_max = \
	(getpagesize() * vault.tab_meta_npage) / sizeof(t_meta_data);
	// ft_printf("New max meta items[%d]\n", vault.meta_items_max);
	return (1);
}

/*
** return an empty struct to store meta infos
*/
long	get_free_meta_block()
{
	long i;

	i = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].type == FREE_BLOCK)
			break;
		i++;
	}
	if (i != 0 && i == vault.meta_items_max && vault.tab_meta[i - 1].type != FREE_BLOCK)
	{
		// ft_putstr("\n\n+_+_+_+_+ JAI BESOIN DE NOUVELLE ESPACE tabmeta+_+_+_+_+_\n\n");
		if (resize_meta_data() != 1)
			return (-1);
		if (vault.tab_meta[i + 1].type == FREE_BLOCK)
			return (i + 1);
		else
			return (-1);
	}
	return (i);
}

/*
**	extends tab_free
**	return 1 if ok or -1 if Nok
*/
int		resize_free_data()
{
	void	*newtab;
	void	*curtab;
	long	cur_npage;
	long	curtabsize;

	cur_npage = vault.tab_free_npage;
	curtab = vault.tab_free;
	curtabsize = getpagesize() * cur_npage;

	newtab = mmap(NULL, curtabsize + (getpagesize() * META_INCRE_ALLOC_PAGE),\
	PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (newtab == MAP_FAILED)
		return (-1);
	ft_memcpy(newtab, curtab, curtabsize);
	munmap(curtab, curtabsize);

	vault.tab_free = newtab;
	vault.tab_free_npage += META_INCRE_ALLOC_PAGE;
	vault.free_items_max = \
	(getpagesize() * vault.tab_free_npage) / sizeof(t_free_block);
	// ft_printf("New max free items[%d]\n", vault.meta_items_max);
	return (1);
}

long	get_free_free_block()
{
	long	i;

	i = 0;
	while (i < vault.free_items_max)
	{
		// ft_printf("i:%d - vault.tab_free[i].ptr {%p}\n", i, vault.tab_free[i].ptr);
		if (vault.tab_free[i].ptr == NULL)
			break;
		i++;
	}
	if (i != 0 && i == vault.free_items_max && vault.tab_free[i - 1].ptr != NULL && vault.tab_free[i - 1].ptr->type != FREE_BLOCK)
	{
		ft_putstr("\n\n+_+_+_+_+ JAI BESOIN DE NOUVELLE ESPACE tabfree+_+_+_+_+_\n\n");
		if (resize_free_data() != 1)
		{
			ft_printf("\ncas1\n");
			return (-1);
		}
		ft_printf("i = %d\n", i);
		printAllTabFreeInfo(520);
		if (vault.tab_free[i + 1].ptr != NULL && vault.tab_free[i + 1].ptr->type == FREE_BLOCK)
		{
			ft_printf("\ncas2\n");
			return (i + 1);
		}
		else
		{
			ft_printf("\ncas3\n");
			return (-1);
		}
	}
	return (i);
}




