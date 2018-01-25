/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subz_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:01:51 by galy              #+#    #+#             */
/*   Updated: 2018/01/25 18:52:21 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

unsigned int	split_subz(unsigned int idx_1, size_t size)
{
	ft_putstr("01 ");

	unsigned int idx_2;
	unsigned int free_subz_bloc_idx;

	ft_putstr("02 ");
	if ((idx_2 = get_free_meta_block()) == (unsigned int)-1)
	{
		if (DEBUG_MALLOC)
			ft_putstr("error: in subz_func.c line 19\n");
		return (-1);
	}

	vault.tab_meta[idx_2].adr = vault.tab_meta[idx_1].adr + size;
	vault.tab_meta[idx_2].type = size_to_subz_type(size, 1);
	vault.tab_meta[idx_2].size = vault.tab_meta[idx_1].size - size;

	vault.tab_meta[idx_1].type = size_to_subz_type(size, 0);
	vault.tab_meta[idx_1].size = size;
	
	ft_putstr("03 ");
	free_subz_bloc_idx = get_free_free_block();
	ft_putstr("04 ");
	
	vault.tab_free[free_subz_bloc_idx].ptr = &vault.tab_meta[idx_2];
	ft_putstr("05 ");
	return (idx_1);
}