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

// t_vault vault = {};

void    *malloc(size_t size)
{
	pthread_mutex_t	mutex;
	void			*adr;

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
		request_tiny_small(size);
	}
	else
	{
		//goto large zone mapping
	}
//----------//----------//----------//----------//
	//free cleaner pass
//----------//----------//----------//----------//
	// pthread unlock
//----------//----------//----------//----------//
	return adr;
}