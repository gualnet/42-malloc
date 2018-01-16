/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:49:52 by galy              #+#    #+#             */
/*   Updated: 2018/01/16 19:01:13 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

int		search_and_erase(void *ptr)
{
	unsigned int	i;

	i = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].adr == ptr)
		{
			//unmap
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
	printAllTabFreeInfo(5);

	if (search_and_erase(ptr) != 1)
	{
		ft_printf("Error for object [%p]: pointer being freed was not allocated\n", ptr);
		exit(-1);
	}

	
	printAllTabFreeInfo(5);
	
}