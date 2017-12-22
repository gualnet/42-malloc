/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_free_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:22:53 by galy              #+#    #+#             */
/*   Updated: 2017/12/22 16:40:39 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

int		get_tabfree_free_block(void)
{
	int i;

	i = 0;
	while (i < vault.tabfree_items_max)
	{
		ft_printf("recherche...");
		// ft_printf("%p\n", vault.tab_free[i].ptr);
		if (vault.tab_free[i].ptr == NULL)
		{
			ft_printf("(get tab free block)return i[%d]: ", i);
			return (i);
		}
		i++;
	}
	ft_printf("+_+_+_+_+ JAI BESOIN DE NOUVELLE ESPACE +_+_+_+_+_");
	// printFreeBlockInfo(vault.tab_free[i]);
	// return (&vault.tab_free[i]);
	return (-1);
}