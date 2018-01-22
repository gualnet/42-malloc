/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adr.c                                           	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:14:26 by galy              #+#    #+#             */
/*   Updated: 2018/01/11 14:57:48 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

t_vault vault = {};

void    *malloc(size_t size)
{
	pthread_mutex_t	mutex;
	void			*adr;
	int				idx;

	adr = NULL;
	idx = 0;
	if (pthread_mutex_init(&mutex, 0) != 0 || size <= 0)
		return (adr);
//----------//----------//----------//----------//
	pthread_mutex_lock(&mutex);
//----------//----------//----------//----------//
	//meta data create
	if (meta_data_initializer() != 1)
		return (NULL);
//----------//----------//----------//----------//
	if (size <= SMALL_ALLOC_MAX)
	{
		// goto tiny / small zone + subzone mapping
		if ((idx = request_tiny_small(size)) == -1)
			return (NULL);
		adr = vault.tab_meta[idx].adr;
	}
	else
	{
		//goto large zone mapping
		adr = request_large(size);
	}
//----------//----------//----------//----------//
	tab_free_cleaner();
//----------//----------//----------//----------//
	// pthread unlock
//----------//----------//----------//----------//
	// printAllTabMetaInfo(5);
	return adr;
}