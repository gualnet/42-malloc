/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:52:42 by galy              #+#    #+#             */
/*   Updated: 2018/01/11 19:36:08 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	printCreateMetaTabCR()
{
	ft_printf("\n\tcreation de tab_meta:\n");
	ft_printf("vault.tab_meta[%p]\n", vault.tab_meta);
	ft_printf("Nombre de pages allouees[%d]\n", vault.tab_meta_npage);
	ft_printf("taille de mata struct[%d]\n", sizeof(t_meta_data));
	ft_printf("(getpagesize()[%d] * vault.tab_meta_npage[%d]) / sizeof(t_meta_data)[%d]\n", getpagesize(), vault.tab_meta_npage, sizeof(t_meta_data));
	ft_printf("Nombre d'items max[%d]\n", vault.meta_items_max);
}

void	printCreateFreeTabCR()
{
	ft_printf("\n\tcreation de tab_free:\n");
	ft_printf("vault.tab_free[%p]\n", vault.tab_free);
	ft_printf("Nombre de pages allouees[%d]\n", vault.tab_free_npage);
	ft_printf("taille de mata struct[%d]\n", sizeof(t_meta_data));
	ft_printf("(getpagesize()[%d] * vault.tab_meta_npage[%d]) / sizeof(t_free_block)[%d]\n", getpagesize(), vault.tab_free_npage, sizeof(t_free_block));
	ft_printf("Nombre d'items max[%d]\n", vault.free_items_max);

}