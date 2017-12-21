/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_free_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:22:53 by galy              #+#    #+#             */
/*   Updated: 2017/12/21 18:52:57 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_free_block	*get_tabfree_free_block(void)
{
	int i;

	i = 0;
	while (i < vault.tabfree_items_max)
	{
		ft_printf("recherche...");
		if (vault.tab_free[i].meta_type == FREE_BLOCK)
			break;
		i++;
	}
	if (vault.tab_free[i].meta_type != FREE_BLOCK &&\
	i == (vault.tabfree_items_max))
	{
		ft_printf("+_+_+_+_+ JAI BESOIN DE NOUVELLE ESPACE +_+_+_+_+_");
	}
	ft_printf("(get tab free block)return i[%d]: ", i);
	printFreeBlockInfo(vault.tab_free[i]);
	return (&vault.tab_free[i]);
}