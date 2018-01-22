/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:34:17 by galy              #+#    #+#             */
/*   Updated: 2018/01/22 19:24:34 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

unsigned int	get_ptr_info(ptr)
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

void			*go_realloc(size_t size, void *old_ptr, size_t old_size)
{
	void	*new_ptr;
	
	if (old_ptr.size < size)
	{
		if ((new_ptr = malloc(size)) == NULL)
			return (NULL);
		ft_memcpy(new_ptr, old_ptr, size);
	}
	else (old_ptr.size > size)
	{
		if ((new_ptr = malloc(size)) == NULL)
			return (NULL);
		ft_memcpy(new_ptr, old_ptr, old_size);
	}
	free(old_ptr);
	return (new_ptr);
}

void			*realloc(void *ptr, size_t size)
{
	ft_putstr("CALL REALLOC\n");

	unsigned int	old_idx;
	void			*old_ptr;
	
	old_idx = get_ptr_info(ptr);
	if (old_idx == -1)
		return (NULL);
	old_ptr = vault.tab_meta[old_idx].adr;
	if (old_ptr.size == size)
		return (ptr);
	else
		return (go_realloc(size, old_ptr, vault.tab_meta[old_idx].size));
}