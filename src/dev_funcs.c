/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:41:19 by galy              #+#    #+#             */
/*   Updated: 2017/12/14 15:09:06 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	printAllTabMetaInfo(t_vault *vault, int interMax)
{
	int i = 0;
	if (interMax == 0)
		interMax = vault->meta_items_max;

	while (i < interMax - 1)
	{
		ft_printf("\ntab_meta[%d] : ", i);
		if (vault->tab_meta[i].meta_type == FREE_BLOCK)
		ft_printf("Type: FREE_BLOCK - ");
		if (vault->tab_meta[i].meta_type == TINY_ZONE)
		ft_printf("Type: TINY_ZONE - ");
		if (vault->tab_meta[i].meta_type == SMALL_ZONE)
		ft_printf("Type: SMALL_ZONE - ");
		if (vault->tab_meta[i].meta_type == LARGE_ZONE)
		ft_printf("Type: LARGE_ZONE - ");
		if (vault->tab_meta[i].meta_type == CUSTOM_ZONE)
		ft_printf("Type: CUSTOM_ZONE - ");
		if (vault->tab_meta[i].meta_type == TINY_SUBZ)
		ft_printf("Type: TINY_SUBZ - ");
		if (vault->tab_meta[i].meta_type == SMALL_SUBZ)
		ft_printf("Type: SMALL_SUBZ - ");
		if (vault->tab_meta[i].meta_type == LARGE_SUBZ)
		ft_printf("Type: LARGE_SUBZ - ");

		ft_printf("MetaSize: %d", vault->tab_meta[i].meta_size);

		i++;
	}
	ft_printf("************* END Of dev func *************");
}
