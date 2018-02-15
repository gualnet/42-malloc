/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:34:17 by galy              #+#    #+#             */
/*   Updated: 2018/02/15 17:33:27 by galy             ###   ########.fr       */
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
			return (i);
		i++;
	}
	return (-1);
}

void	*go_realloc(size_t size, long old_idx)
{
	void	*new_ptr;

	if (vault.tab_meta[old_idx].size < size)
	{
		if ((new_ptr = malloc(size)) == NULL)
			return (NULL);
		ft_memcpy(new_ptr, vault.tab_meta[old_idx].adr, \
		vault.tab_meta[old_idx].size);
	}
	else if (vault.tab_meta[old_idx].size > size)
	{
		if ((new_ptr = malloc(size)) == NULL)
			return (NULL);
		ft_memcpy(new_ptr, vault.tab_meta[old_idx].adr, size);
	}
	else
		new_ptr = NULL;
	free(vault.tab_meta[old_idx].adr);
	return (new_ptr);
}

void	*realloc(void *ptr, size_t size)
{
	long	old_idx;

	if ((long)(old_idx = get_ptr_idx(ptr)) == -1)
	{
		if (ft_strcmp(getenv("DEBUG_MALLOC"), "TRUE") == 0)
		{
			ft_printf("\033[31mError for object [%p]: \
			pointer being realloc'd was not allocated\n\033[0m", ptr);
			exit(-1);
		}
		return (NULL);
	}
	if (vault.tab_meta[old_idx].size == size)
	{
		ft_putstr("end2\n");
		return (ptr);
	}
	return (go_realloc(size, old_idx));
}
