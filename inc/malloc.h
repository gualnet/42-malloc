/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:45:54 by galy              #+#    #+#             */
/*   Updated: 2017/12/26 16:13:28 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

#include "../inc/ft_printf.h"
#include "../inc/get_next_line.h"
#include "../inc/libft.h"

#define META_INCRE_ALLOC_PAGE 2 //size tab-meta = META_ALLOC_STEP * pagesize

typedef enum			e_meta_type
{
	FREE_BLOCK,
	TINY_ZONE,
	SMALL_ZONE,
	LARGE_ZONE,
	TINY_SUBZ_FREE,
	TINY_SUBZ,
	SMALL_SUBZ_FREE,
	SMALL_SUBZ,
	// LARGE_SUBZ_FREE,
	// LARGE_SUBZ,
	// CUSTOM_ZONE,
	// CUSTOM_SUBZ
}						t_meta_type;

typedef enum			e_meta_size //from osx implem
{
	NULL_SIZE			= 0,
	TINY_ALLOC_MIN		= 1,
	TINY_ALLOC_MAX		= 992, //(xx% of zone size -> 992o)
	TINY_ZONE_SIZE		= 2097152, //(256 * 4096 -> 2mo)
	SMALL_ALLOC_MIN		= 993,
	SMALL_ALLOC_MAX		= 130048, //(xx% of zone size->127ko)
	SMALL_ZONE_SIZE		= 16777216, //(128 * 16384 -> 16mo)
	LARGE_ALLOC_MIN		= 1572865,
}						t_meta_size;
// typedef enum			e_meta_size
// {
// 	NULL_SIZE			= 0,
// 	TINY_ALLOC_MIN		= 1,
// 	TINY_ALLOC_MAX		= 393216, //(75% of zone size -> 384ko)
// 	TINY_ZONE_SIZE		= 524288, //(128 * 4096 -> 512ko)
// 	SMALL_ALLOC_MIN		= 393217,
// 	SMALL_ALLOC_MAX		= 1572864, //(75% of zone size->1.5mo)
// 	SMALL_ZONE_SIZE		= 2097152, //(128 * 16384 -> 2mo)
// 	LARGE_ALLOC_MIN		= 1572865,
// }						t_meta_size;


/*
** size of struct 12 octets -> align @ 16o
*/
typedef struct			s_meta_data
{
	void				*adr;
	t_meta_type			meta_type;
	t_meta_size			meta_size;
	size_t				size;
}						t_meta_data;

typedef struct			s_free_block
{
	// int					metadata_num;
	// void				*adr;
	// t_meta_type			meta_type;
	// size_t				size;
	t_meta_data			*ptr;
}						t_free_block;

typedef struct			s_vault
{
	t_meta_data			*tab_meta;
	int					tab_meta_npage;
	int					meta_items_max;
	t_free_block		*tab_free;
	int					tabfree_items_max;
}						t_vault;

//global
extern t_vault	vault;

//main
void			*ft_malloc(size_t size);

//meta_data
void			*check_meta_data(t_vault *vault, size_t size);
t_meta_type		size_to_zone_type(size_t size);
t_meta_size		size_to_zone_size(size_t size);
t_meta_type		size_to_subz_type(size_t size, int flag_free);
void			meta_set_new_size(t_vault *vault, t_meta_data *meta_block,\
size_t size);
t_meta_data		*get_free_meta_block(t_vault *vault);

//vault
void			*create_tab_meta(t_vault *vault);

//zone
void			*check_meta_find_space(t_vault *vault, size_t size);
void			*find_zone_space(t_vault *vault, size_t size);

//subz
void			*find_free_subz(t_vault *vault, size_t size);

//map
void			*map_new_zone(t_vault *vault, t_meta_data *meta_block, size_t size);
void			*map_tiny_zone(t_vault *vault);

//free
void			ft_free(void *ptr);
void			create_tab_free(void);

//tab_free
int				get_tabfree_free_block(void);
void			tab_free_cleaner();
void			merge_free_subz(int free_idx, int meta_idx);

//dev
void	printAllTabMetaInfo(t_vault *vault, int interMax);
void	printBlockMetaInfo(t_meta_data *block);
void	printTabFree(int interMax);
void	printFreeBlockInfo(t_free_block block);

//tests
int test0();
int test1();
int test1_1();


#endif