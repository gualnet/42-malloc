/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:45:54 by galy              #+#    #+#             */
/*   Updated: 2017/12/08 21:16:11 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>

#include "../inc/ft_printf.h"
#include "../inc/get_next_line.h"
#include "../inc/libft.h"



typedef enum			e_meta_type
{
	FREE_SPACE,
	TINY_ZONE,
	SMALL_ZONE,
	LARGE_ZONE,
	CUSTOM_ZONE,
	TINY_SUBZ,
	SMALL_SUBZ,
	LARGE_SUBZ,
	CUSTOM_SUBZ
}						t_meta_type;

typedef enum			e_meta_size
{
	NULL_SIZE			= 0,
	TINY_ALLOC_MIN		= 1,
	TINY_ALLOC_MAX		= 393216, //(75% of zone size -> 384ko)
	TINY_ZONE_SIZE		= 524288, //(128 * 4096 -> 512ko)
	SMALL_ALLOC_MIN		= 8388609,
	SMALL_ALLOC_MAX		= 1572864, //(75% of zone size->1.5mo)
	SMALL_ZONE_SIZE		= 2097152, //(128 * 16384 -> 2mo)
	LARGE_ALLOC_MIN		= 1572865,
	LARGE_ALLOC_MAX		= 10485760, //(80% of zone size->8mo)
	LARGE_ZONE_SIZE		= 10485760, //(128 *  -> 10mo)
	CUSTOM_SIZE,
}						t_meta_size;


/*
** size of struct 12 octets -> align @ 16o
*/
typedef struct			s_meta_data
{
	void				*adr;
	t_meta_type			meta_type;
	t_meta_size			meta_size; 
}						t_meta_data;

typedef struct			s_vault
{
	t_meta_data			*tab_meta;
	int					tab_meta_npage;
	int					meta_items_max;
}						t_vault;


//main
void			*malloc(size_t size);

//meta_data
void			*check_meta_data(t_vault *vault, size_t size);
t_meta_type		size_to_zone_type(size_t size);
t_meta_size		size_to_zone_size(size_t size);


//vault
void			*create_vault(t_vault *vault);

//subz
void			*find_free_subz(t_vault *vault, size_t size);

//map
void			*map_new_zone(t_vault *vault, size_t size);
void			*map_tiny_zone(t_vault *vault);
