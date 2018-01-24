/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:34:17 by galy              #+#    #+#             */
/*   Updated: 2018/01/24 19:24:38 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

unsigned int	get_ptr_idx(void *ptr)
{
	unsigned int i;

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

void			*go_realloc(size_t size, unsigned int old_idx)
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

void			*realloc(void *ptr, size_t size)
{
	// ft_putstr("CALL REALLOC\n");

	unsigned int	old_idx;
	// void			*old_ptr;
	
	if ((long long)(old_idx = get_ptr_idx(ptr)) == -1)
		return (NULL);
	// old_ptr = vault.tab_meta[old_idx].adr;
	if (vault.tab_meta[old_idx].size == size)
		return (ptr);
	else
		return (go_realloc(size, old_idx));
}