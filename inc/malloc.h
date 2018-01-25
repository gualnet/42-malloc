/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:01:34 by galy              #+#    #+#             */
/*   Updated: 2018/01/25 18:55:49 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#	define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

#include "../inc/ft_printf.h"
#include "../inc/get_next_line.h"
#include "../inc/libft.h"


#define DEBUG_MALLOC 1
#define META_INCRE_ALLOC_PAGE 1 //size tab-meta = META_ALLOC_STEP * pagesize

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

/*
** size of struct 24 octets --> align @ XX o
*/
typedef struct			s_meta_data
{
	void				*adr;
	unsigned int		idx;
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
	t_meta_data			*tab_meta;
	t_free_block		*tab_free;
	unsigned int		tab_meta_npage;
	unsigned int		meta_items_max;
	unsigned int		tab_free_npage;
	unsigned int		free_items_max;
}						t_vault;

//global
extern t_vault	vault;

//malloc.c
void    *ft_malloc(size_t size);

//meta_data_init.c
int		meta_data_initializer();
int		create_tab_meta(void);	//interne - test
int		create_tab_free(void);	//interne - test
unsigned int	get_free_meta_block();
int		resize_free_data();
unsigned int	get_free_free_block();

//request_tiny_small.c
unsigned int	request_tiny_small(size_t size);

//converter.c
t_meta_type	size_to_subz_type(size_t size, int flag_free);
t_meta_type	size_to_zone_type(size_t size);
t_meta_size	size_to_zone_size(size_t size);
size_t	    size_to_subz_size(size_t size);

//subz_func.c
unsigned int	split_subz(unsigned int idx_1, size_t size);

//request_large.c
void	*request_large(size_t size);


//free.c
void	ft_free(void *ptr);
void	tab_free_cleaner(void);
int		search_and_free_subz(void *ptr);

//realloc.c
void	*realloc(void *ptr, size_t size);



//dev_func.c
void	printCreateMetaTabCR();
void	printCreateFreeTabCR();
void	printMetaBlocInfo(unsigned int id);
void	printAllTabMetaInfo(unsigned int interMax);
void	printAllTabFreeInfo(unsigned int interMax);
void	printFreeBlocInfo(unsigned int id);


#endif