/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:01:34 by galy              #+#    #+#             */
/*   Updated: 2018/01/11 18:32:26 by galy             ###   ########.fr       */
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
void    *malloc(size_t size);

//meta_data_init.c
int		meta_data_initializer();
int		create_tab_meta(void);
int		create_tab_free(void);

//dev_func.c
void	printCreateMetaTabCR();
void	printCreateFreeTabCR();


#endif