/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:13:58 by galy              #+#    #+#             */
/*   Updated: 2018/03/08 20:38:55 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

int		create_tab_meta(void)
{
	long	i;

	vault.tab_meta = my_mmap(getpagesize() * 1);
	if (vault.tab_meta == MAP_FAILED)
		return (-1);
	vault.tab_meta_npage = 1;
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
	long	i;

	vault.tab_free = my_mmap(getpagesize() * 1);
	if (vault.tab_free == MAP_FAILED)
		return (-1);
	vault.tab_free_npage = 1;
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

int		meta_data_initializer(void)
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

/*
** return an empty struct to store meta infos
*/

long	get_free_meta_block(void)
{
	long i;

	i = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].type == FREE_BLOCK)
			break ;
		i++;
	}
	if (i != 0 && i == vault.meta_items_max && \
	vault.tab_meta[i - 1].type != FREE_BLOCK)
	{
		if (resize_meta_data() != 1)
			return (-1);
		if (vault.tab_meta[i + 1].type == FREE_BLOCK)
			return (i + 1);
		else
			return (-1);
	}
	return (i);
}

long	get_free_free_block(void)
{
	long	i;

	i = 0;
	while (i < vault.free_items_max)
	{
		if (vault.tab_free[i].ptr == NULL)
			break ;
		i++;
	}
	if (i != 0 && i == vault.free_items_max && \
	vault.tab_free[i - 1].ptr != NULL && \
	vault.tab_free[i - 1].ptr->type != FREE_BLOCK)
	{
		if (resize_free_data() != 1)
			return (-1);
		if (vault.tab_free[i].ptr == NULL)
			return (i + 1);
		else
			return (-1);
	}
	return (i);
}
