/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subz_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:01:51 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 18:20:40 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

long	split_subz(long idx_1, size_t size)
{
	long idx_2;
	long free_subz_bloc_idx;

	if ((idx_2 = get_free_meta_block()) == -1)
	{
		if (getenv("DEBUG_MALLOC"))
			ft_putstr("error: in subz_func.c line 19\n");
		return (-1);
	}
	g_vault.tab_meta[idx_2].adr = g_vault.tab_meta[idx_1].adr + size;
	g_vault.tab_meta[idx_2].type = size_to_subz_type(size, 1);
	g_vault.tab_meta[idx_2].size = g_vault.tab_meta[idx_1].size - size;
	g_vault.tab_meta[idx_1].type = size_to_subz_type(size, 0);
	g_vault.tab_meta[idx_1].size = size;
	if ((free_subz_bloc_idx = get_free_free_block()) == -1)
	{
		if (getenv("DEBUG_MALLOC"))
		{
			ft_printf("PANIC 001 idx1[%d] - \
			idx2[%d]: subz_func\n", idx_1, idx_2);
			exit(-1);
		}
	}
	g_vault.tab_free[free_subz_bloc_idx].ptr = &g_vault.tab_meta[idx_2];
	return (idx_1);
}
