/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:01:34 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 18:36:35 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

# define META_INCRE_ALLOC_PAGE 8

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
	NULL_SIZE = 0,
	TINY_ALLOC_MIN = 1,
	TINY_ALLOC_MAX = 4096,
	TINY_ZONE_SIZE = 1048576,
	SMALL_ALLOC_MIN = 4097,
	SMALL_ALLOC_MAX = 131072,
	SMALL_ZONE_SIZE = 16777216,
	LARGE_ALLOC_MIN = 131073,
}						t_meta_size;

/*
** size of struct 24 octets --> align @ XX o
*/
typedef struct			s_meta_data
{
	void				*adr;
	long				idx;
	t_meta_type			type;
	t_meta_size			capacity;
	size_t				size;
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

extern t_vault	g_vault;

void					*malloc(size_t size);
void					*my_mmap(size_t size);
int						meta_data_initializer();
int						create_tab_meta(void);
int						create_tab_free(void);
long					get_free_meta_block();
long					get_free_free_block();
int						resize_free_data();
int						resize_meta_data();
void					rebuild_tab_free(void);
long					request_tiny_small(size_t size);
t_meta_type				size_to_subz_type(size_t size, int flag_free);
t_meta_type				size_to_zone_type(size_t size);
t_meta_size				size_to_zone_size(size_t size);
size_t					size_to_subz_size(size_t size);
size_t					zone_type_to_size(t_meta_type type);
long					split_subz(long idx_1, size_t size);
void					*request_large(size_t size);
void					unmap_large(long i);
void					check_tabmeta_usage();
void					free(void *ptr);
void					tab_free_cleaner(void);
int						search_and_free_subz(void *ptr);
void					*realloc(void *ptr, size_t size);
void					show_alloc_mem(void);
void					sam_err(void);
long					print_tab_show_nfo(t_meta_data *tab_show);
void					order_tab_show(t_meta_data *tab_show);

#endif
