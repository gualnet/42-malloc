/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:34:17 by galy              #+#    #+#             */
/*   Updated: 2018/01/29 18:26:23 by galy             ###   ########.fr       */
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
	
	if (vault.tab_meta[old_idx].size < size)
	{
		if ((new_ptr = malloc(size)) == NULL)
			return (NULL);
		ft_memcpy(new_ptr, vault.tab_meta[old_idx].adr, size);
	}
	else if (vault.tab_meta[old_idx].size > size)
	{
		if ((new_ptr = malloc(size)) == NULL)
			return (NULL);
		ft_memcpy(new_ptr, vault.tab_meta[old_idx].adr, vault.tab_meta[old_idx].size);
	}
	else
		new_ptr = NULL;
	free(vault.tab_meta[old_idx].adr);
	return (new_ptr);
}

void			*ft_realloc(void *ptr, size_t size)
{
	// ft_putstr("CALL REALLOC\n");

	long	old_idx;
	
	if ((long long)(old_idx = get_ptr_idx(ptr)) == -1)
		return (NULL);
	if (vault.tab_meta[old_idx].size == size)
		return (ptr);
	else
		return (go_realloc(size, old_idx));
}