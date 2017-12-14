/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:45:52 by galy              #+#    #+#             */
/*   Updated: 2017/12/14 15:42:53 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

// mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

void    *ft_malloc(size_t size)
{
	ft_printf("\n\nft_malloc: %d\n", size);
	pthread_mutex_t mutex_lock; //??
	void			*adr;
	static t_vault	vault;
	
	adr = NULL;
	if(size <= 0)
		return (NULL);
	pthread_mutex_lock(&mutex_lock); //??

	ft_printf("000\n");
	if(check_meta_data(&vault, size) == NULL) // check/create meta-data tab
		return (NULL);
// ---------------------
	ft_printf("001\n");
	int i = -1;
	i = check_meta_find_space(&vault, size);
	ft_printf("002\n");
	if (i != -1)
		return (vault.tab_meta[i].adr);
	if (i == -1)
		return (NULL);
	ft_printf("003\n");
// ---------------------
	
	// pthread_mutex_unlock(&mutex_lock); //??

	return adr;
}

int main()
{
	char *str;
	
	ft_printf("(getpagesize(%d) * nbrPages(%d)) / t_meta_data(%d) = %d\n", getpagesize(), META_INCRE_ALLOC_PAGE, sizeof(t_meta_data), getpagesize() * META_INCRE_ALLOC_PAGE / sizeof(t_meta_data));

	str = ft_malloc(1);
	ft_printf("adr: %p", str);
	// str = ft_malloc(60);
	// str = ft_malloc(64);
	// str = ft_malloc(65);
	// str = ft_malloc(3000);
	// str = ft_malloc(3200);
	// str = ft_malloc(3201);
	// str = ft_malloc(1048576);
	// str = ft_malloc(12000);
}