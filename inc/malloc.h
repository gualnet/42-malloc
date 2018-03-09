/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:01:34 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 16:01:10 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#	define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"


// #define DEBUG_MALLOC 1 - replaced by varenv

// #define META_INCRE_ALLOC_PAGE 1 // pour test sur la liberation des espace inutiles des tab_meta
#define META_INCRE_ALLOC_PAGE 8 //size tab-meta = META_ALLOC_STEP * pagesize

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
}						t_meta_type;

/*
** TINY => 256*TINY_ALLOC_MAX
*/
typedef enum			e_meta_size
{
	NULL_SIZE			= 0,
	TINY_ALLOC_MIN		= 1,
	TINY_ALLOC_MAX		= 4096,
	TINY_ZONE_SIZE		= 1048576,
	SMALL_ALLOC_MIN		= 4097,
	SMALL_ALLOC_MAX		= 131072,
	SMALL_ZONE_SIZE		= 16777216,
	LARGE_ALLOC_MIN		= 131073,
}						t_meta_size;

/*
** size of struct 24 octets --> align @ XX o
*/
typedef struct			s_meta_data
{
	void				*adr;
	long				idx;
	t_meta_type			type;
	t_meta_size			capacity; //zone: max cap - subz: not applic.
	size_t				size; //zone: size occupied - subz: max cap
}						t_meta_data;

typedef struct			s_free_block
{
	t_meta_data			*ptr;
}						t_free_block;

typedef struct			s_vault
{
	pthread_mutex_t		mutex;
	t_meta_data			*tab_meta;
	t_free_block		*tab_free;
	long				tab_meta_npage;
	long				meta_items_max;
	long				tab_free_npage;
	long				free_items_max;
}						t_vault;

//global
extern t_vault	vault;

//malloc.c
void    *malloc(size_t size);
void	*my_mmap(size_t size);

//meta_data_init.c
int		meta_data_initializer();
int		create_tab_meta(void);	//interne - test
int		create_tab_free(void);	//interne - test
long	get_free_meta_block();
long	get_free_free_block();

//tabs_resizers.c
int		resize_free_data();
int		resize_meta_data();
void	rebuild_tab_free(void);

//request_tiny_small.c
long	request_tiny_small(size_t size);

//converter.c
t_meta_type	size_to_subz_type(size_t size, int flag_free);
t_meta_type	size_to_zone_type(size_t size);
t_meta_size	size_to_zone_size(size_t size);
size_t	    size_to_subz_size(size_t size);
size_t		zone_type_to_size(t_meta_type type);

//subz_func.c
long		split_subz(long idx_1, size_t size);

//request_large.c
void	*request_large(size_t size);
void	unmap_large(long i);

//tabs_usage_funcs.c
void	check_tabmeta_usage();

//free.c
void	free(void *ptr);
void	tab_free_cleaner(void);

//free_func.c
int		search_and_free_subz(void *ptr);

//realloc.c
void	*realloc(void *ptr, size_t size);

//show_alloc_mem.c
void	show_alloc_mem(void);

//print_tab_show.c
long	print_tab_show_nfo(t_meta_data *tab_show);

//order_tab_show.c
void	order_tab_show(t_meta_data *tab_show);




//dev_func.c
void	printCreateMetaTabCR();
void	printCreateFreeTabCR();
void	printMetaBlocInfo(long id);
void	printAllTabMetaInfo(long interMax);
void	printAllTabFreeInfo(long interMax);
void	printFreeBlocInfo(long id);


#endif