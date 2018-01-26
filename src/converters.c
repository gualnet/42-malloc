/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:33:26 by galy              #+#    #+#             */
/*   Updated: 2018/01/26 15:29:12 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** Return the defined subz-type which will contain the data.
*/
t_meta_type	size_to_subz_type(size_t size, int flag_free)
{
	if (size >= TINY_ALLOC_MIN && size <= TINY_ALLOC_MAX)
	{
		if (flag_free == 1)
			return TINY_SUBZ_FREE;
		return TINY_SUBZ;
	}
	else if (size >= SMALL_ALLOC_MIN && size <= SMALL_ALLOC_MAX)
	{
		if (flag_free == 1)
			return SMALL_SUBZ_FREE;
		return SMALL_SUBZ;
	}
	else
		return LARGE_ZONE;
}

/*
** Return the defined zone-type which will contain the new sub-zone.
*/
t_meta_type	size_to_zone_type(size_t size)
{
	if (size >= TINY_ALLOC_MIN && size <= TINY_ALLOC_MAX)
		return TINY_ZONE;
	else if (size >= SMALL_ALLOC_MIN && size <= SMALL_ALLOC_MAX)
		return SMALL_ZONE;
	return LARGE_ZONE;
}

/*
** Return the defined zone-size which will contain the new sub-zone.
*/
t_meta_size	size_to_zone_size(size_t size)
{
	if (size >= TINY_ALLOC_MIN && size <= TINY_ALLOC_MAX)
		return TINY_ZONE_SIZE;
	if (size >= SMALL_ALLOC_MIN && size <= SMALL_ALLOC_MAX)
        return SMALL_ZONE_SIZE;
    return NULL_SIZE;
}

size_t	    size_to_subz_size(size_t size)
{
    if (size >= TINY_ALLOC_MIN && size <= TINY_ALLOC_MAX)
		return ((size_t)2097152);//2097152
    if (size >= SMALL_ALLOC_MIN && size <= SMALL_ALLOC_MAX)
		return ((size_t)16777216);//16777216
    if (DEBUG_MALLOC)
        ft_putstr("\n\n\033[31mError convert size_to_subz_size\033[0m\n\n");
    exit(-1);
    return (0);
}