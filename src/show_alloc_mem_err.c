/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:13:25 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 18:56:12 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_err(void)
{
	if (ft_strcmp(getenv("DEBUG_MALLOC"), "TRUE") == 0)
		ft_putstr("\033[31mError memory mapping failed\n\033[0m");
	exit(-1);
}

int		sam_inner_loop(long i, int s_state, t_meta_data *tab_show)
{
	if (s_state == 1 && g_vault.tab_meta[i].type == TINY_ZONE)
		s_state = loop_tiny_small(tab_show, g_vault.tab_meta[i].adr, i, 1);
	else if (s_state == 2 && g_vault.tab_meta[i].type == SMALL_ZONE)
		s_state = loop_tiny_small(tab_show, g_vault.tab_meta[i].adr, i, 2);
	return (s_state);
}