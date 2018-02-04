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

#include "malloc.h"

t_vault vault = {};

void    *ft_malloc(size_t size)
{
	// ft_putstr("call malloc\n");
	pthread_mutex_t	mutex;
	void			*adr;
	long			idx;

	idx = 0;
	adr = NULL;
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
	check_tabmeta_usage();
	tab_free_cleaner(); // mef a virer
//----------//----------//----------//----------//
	// pthread unlock
//----------//----------//----------//----------//
	// printAllTabMetaInfo(5);
	// ft_putstr("end call malloc\n");
	return adr;
}