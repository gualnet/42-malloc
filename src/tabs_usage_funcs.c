/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_usage_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:05:34 by galy              #+#    #+#             */
/*   Updated: 2018/02/01 19:27:23 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


void	check_tabmeta_usage()
{
	long	i;
	long	nb_used;

	// ft_putstr("AA\n");
	i = 0;
	nb_used = 0;
	while(i < vault.meta_items_max)
	{
		if (vault.tab_meta[i].type != FREE_BLOCK)
		{
			nb_used++;
		}


		i++;
	}
	// ft_putstr("BB\n");
	// ft_printf("nombre d'elements [%d]\n", nb_used);


}