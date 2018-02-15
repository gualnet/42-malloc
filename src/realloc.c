/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:34:17 by galy              #+#    #+#             */
/*   Updated: 2018/02/15 13:58:18 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

long	get_ptr_idx(void *ptr)
{
	long i;

	i = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].adr == ptr)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void			*go_realloc(size_t size, long old_idx)
{
	void	*new_ptr;
	
	// ft_printf("go realloc size [%d]\n", size);
	if (vault.tab_meta[old_idx].size < size)
	{
		// ft_putstr("A001\n");
		if ((new_ptr = malloc(size)) == NULL)
		{
			// ft_printf("realloc new_ptr[%p]\n", new_ptr);
			return (NULL);
		}
		// ft_putstr("A001+\n");
		// printAllTabMetaInfo(5);
		// ft_printf("new_ptr[%p] - vault.tab_meta[old_idx].adr[%p] - size[%d]\n", new_ptr, vault.tab_meta[old_idx].adr, size);
		ft_memcpy(new_ptr, vault.tab_meta[old_idx].adr, vault.tab_meta[old_idx].size);
		// ft_putstr("A001++\n");
	}
	else if (vault.tab_meta[old_idx].size > size)
	{
		// ft_putstr("A002\n");
		if ((new_ptr = malloc(size)) == NULL)
			return (NULL);
		// printAllTabMetaInfo(5);
		// ft_printf("new_ptr[%p] - vault.tab_meta[old_idx].adr[%p] - size[%d]\n", new_ptr, vault.tab_meta[old_idx].adr, size);
		ft_memcpy(new_ptr, vault.tab_meta[old_idx].adr, size);
	}
	else
	{
		new_ptr = NULL;
	}
	free(vault.tab_meta[old_idx].adr);
	return (new_ptr);
}

void			*realloc(void *ptr, size_t size)
{
	// ft_putstr("CALL REALLOC\n");

	long	old_idx;
	
	// if ((long long)(old_idx = get_ptr_idx(ptr)) == -1)
	// ft_putstr("step1\n");
	if ((long)(old_idx = get_ptr_idx(ptr)) == -1)
	{
		if (getenv("DEBUG_MALLOC"))
		{
			ft_printf("\033[31mError for object [%p]: pointer being realloc'd was not allocated\n\033[0m", ptr);
			exit (-1);
		}
		return (NULL);
	}
	// ft_putstr("step2\n");
	if (vault.tab_meta[old_idx].size == size)
	{
		ft_putstr("end2\n");
		return (ptr);
	}
	// ft_putstr("step3\n");
	return (go_realloc(size, old_idx));
}