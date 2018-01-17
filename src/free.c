/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:49:52 by galy              #+#    #+#             */
/*   Updated: 2018/01/17 19:11:46 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	defrag(void)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < vault.free_items_max)
	{

		i++;
	}
}

void	tab_free_cleaner(void)
{
	unsigned int	i;

	i = 0;
	while (i < vault.free_items_max)
	{
		if (vault.tab_free[i].ptr != NULL && vault.tab_free[i].ptr->type != TINY_SUBZ_FREE\
		&& vault.tab_free[i].ptr->type != SMALL_SUBZ_FREE)
		{
			vault.tab_free[i].ptr = NULL;
		}
		i++;
	}
}

int		search_and_free_subz(void *ptr)
{
	unsigned int	i;

	i = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].adr == ptr)
		{
			if (vault.tab_meta[i].type == TINY_SUBZ)
				vault.tab_meta[i].type = TINY_SUBZ_FREE;
			else if (vault.tab_meta[i].type == SMALL_SUBZ)
				vault.tab_meta[i].type = SMALL_SUBZ_FREE;
			vault.tab_free[get_free_free_block()].ptr = & vault.tab_meta[i];
			return (1);
		}
		i++;
	}
	return (-1);

}

void	ft_free(void *ptr)
{
	ft_putstr("call ft_free\n");
	if (ptr == NULL)
		return;
	if (vault.tab_free == NULL)
	{
		// ft_printf("Before:\nvault.tab_free == [%p] && vault.tab_meta == [%p]\n", vault.tab_free, vault.tab_meta);
		meta_data_initializer();
		// ft_printf("After:\nvault.tab_free == [%p] && vault.tab_meta == [%p]\n", vault.tab_free, vault.tab_meta);
	}

	if (search_and_free_subz(ptr) != 1)
	{
		ft_printf("Error for object [%p]: pointer being freed was not allocated\n", ptr);
		exit(-1);
	}
	
}