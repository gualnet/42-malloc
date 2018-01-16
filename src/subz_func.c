/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subz_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:01:51 by galy              #+#    #+#             */
/*   Updated: 2018/01/16 19:34:37 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

unsigned int	split_subz(unsigned int idx_1, size_t size)
{
	unsigned int idx_2;
	unsigned int free_subz_bloc_idx;

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
	
	free_subz_bloc_idx = get_free_free_block();
	vault.tab_free[free_subz_bloc_idx].ptr = &vault.tab_meta[idx_2];
	return (idx_1);
}