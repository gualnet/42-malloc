/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_tab_show.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:15:09 by galy              #+#    #+#             */
/*   Updated: 2018/02/15 17:28:51 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	interv_blocs(t_meta_data *tab_show, long i)
{
	void		*h_adr;
	t_meta_size	h_capacity;
	size_t		h_size;

	h_adr = tab_show[i].adr;
	h_capacity = tab_show[i].capacity;
	h_size = tab_show[i].size;
	tab_show[i].adr = tab_show[i + 1].adr;
	tab_show[i].capacity = tab_show[i + 1].capacity;
	tab_show[i].size = tab_show[i + 1].size;
	tab_show[i + 1].adr = h_adr;
	tab_show[i + 1].capacity = h_capacity;
	tab_show[i + 1].size = h_size;
}

void	order_tab_show(t_meta_data *tab_show)
{
	int		again;
	long	i;

	again = 1;
	i = 0;
	while (again == 1)
	{
		if (i < vault.meta_items_max - 1)
		{
			if (tab_show[i].type != FREE_BLOCK && \
			tab_show[i + 1].type != FREE_BLOCK && \
			tab_show[i].adr > tab_show[i + 1].adr)
			{
				interv_blocs(tab_show, i);
				again = 1;
				i = 0;
			}
		}
		else
			break ;
		i++;
	}
}
