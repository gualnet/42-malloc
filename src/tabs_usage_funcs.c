/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_usage_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:05:34 by galy              #+#    #+#             */
/*   Updated: 2018/03/05 15:41:06 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	check_tabmeta_usage(void)
{
	long	i;
	long	nb_used;

	i = 0;
	nb_used = 0;
	while (i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].type != FREE_BLOCK)
		{
			nb_used++;
		}
		i++;
	}
}
