/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:49:52 by galy              #+#    #+#             */
/*   Updated: 2018/01/16 11:59:55 by galy             ###   ########.fr       */
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
	ft_putstr("call ft_free");
	if (ptr == NULL)
		return;
	
	if (vault.tab_free == NULL)
	{
		ft_printf("Before:\nvault.tab_free == [%p] && vault.tab_meta == [%p]", vault.tab_free, vault.tab_meta);
		meta_data_initializer();
		ft_printf("After:\nvault.tab_free == [%p] && vault.tab_meta == [%p]", vault.tab_free, vault.tab_meta);
	}



	if (search_and_erase(ptr) != 1)
	{
		ft_printf("Error for object [%p]: pointer being freed was not allocated\n", ptr);
		exit(-1);
	}



	
}