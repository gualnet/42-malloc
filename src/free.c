/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:49:52 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 18:19:08 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free(void *ptr)
{
	if (ptr == NULL)
		return ;
	pthread_mutex_lock(&g_vault.mutex);
	if (g_vault.tab_free == NULL)
	{
		if (ft_strcmp(getenv("DEBUG_MALLOC"), "TRUE") == 0)
			ft_putstr("\033[33mWARNING - g_vault.tab_free = NULL !!!\n\033[0m");
		return ;
	}
	if (search_and_free_subz(ptr) != 1 && \
	ft_strcmp(getenv("DEBUG_MALLOC"), "TRUE") == 0)
	{
		ft_printf("\033[31mError for object [%p]: \
		pointer being freed was not allocated\n\033[0m", ptr);
		exit(-1);
	}
	tab_free_cleaner();
	check_tabmeta_usage();
	pthread_mutex_unlock(&g_vault.mutex);
}

void	tab_free_cleaner(void)
{
	long	i;
	int		found;

	found = 0;
	i = 0;
	while (i < g_vault.free_items_max)
	{
		if (g_vault.tab_free[i].ptr != NULL)
		{
			if (g_vault.tab_free[i].ptr->type != TINY_SUBZ_FREE \
			&& g_vault.tab_free[i].ptr->type != SMALL_SUBZ_FREE)
			{
				g_vault.tab_free[i].ptr = NULL;
			}
		}
		i++;
	}
}
