/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_zone_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:40:08 by galy              #+#    #+#             */
/*   Updated: 2017/12/08 21:11:38 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	*map_non_custom_zone(t_vault *vault, t_meta_type ztype, t_meta_size zsize);

void	*map_new_zone(t_vault *vault, size_t size)
{
	t_meta_type	need_type;
	t_meta_size	need_size;
	
	need_type = size_to_zone_type(size);
	need_size = size_to_zone_size(size);
	if(need_type != CUSTOM_ZONE)
		return map_non_custom_zone(vault, need_type, need_size);



	
	return NULL;

}

void	*map_non_custom_zone(t_vault *vault, t_meta_type ztype, t_meta_size zsize)
{
	t_meta_data	empty_store;
	void		*new_zone;
	int			i;

	i = 0;
	new_zone = mmap(NULL, ztype, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	empty_store.adr = new_zone;
	empty_store.meta_type = ztype;
	empty_store.meta_size = zsize;
	ft_printf("\n****NEW ZONE ALLOC****\n");
	ft_printf("adr: %p - TYPE: %d - SIZE: %d\n", new_zone, ztype, zsize);
	ft_printf("**********************\n\n");
	return new_zone;
}

// void	*map_custom_zone(t_vault *vault)
// {
// 	void	*new_zone;
// 	int		i;

// 	i = 0;
// 	new_zone = mmap(NULL, TINY_ZONE_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
// 	while(i < vault->meta_items_max)
// 	{
// 		if(vault->tab_meta[i].meta_type == FREE_SPACE)
// 			break;
// 		i++;
// 	}
// 	vault->tab_meta[i].adr = new_zone;
// 	vault->tab_meta[i].meta_type = TINY_ZONE;
// 	vault->tab_meta[i].meta_size = TINY_ZONE_SIZE;
// 	ft_printf("\n****NEW TINY ALLOC****\n");
// 	ft_printf("adr: %p - TYPE: TINY - SIZE: %d\n", new_zone, TINY_ZONE_SIZE);
// 	ft_printf("**********************\n\n");
// 	return new_zone;
// }