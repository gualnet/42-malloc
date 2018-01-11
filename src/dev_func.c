/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:52:42 by galy              #+#    #+#             */
/*   Updated: 2018/01/11 17:05:11 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	printCreateTabCR()
{
	ft_printf("vault.tab_meta[%p]\n", vault.tab_meta);
	ft_printf("Nombre de pages allouees[%d]\n", vault.tab_meta_npage);
	ft_printf("taille de mata struct[%d]\n", sizeof(t_meta_data));
	ft_printf("Nombre d'items max[%d]\n", vault.meta_items_max);
	ft_printf("(getpagesize()[%d] * vault.tab_meta_npage[%d]) / sizeof(t_meta_data)[%d]", getpagesize(), vault.tab_meta_npage, sizeof(t_meta_data));

}