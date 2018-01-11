/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_tiny_small.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:26:00 by galy              #+#    #+#             */
/*   Updated: 2018/01/11 20:59:59 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

int		request_tiny_small(size_t size)
{
	unsigned int	i;
	t_meta_type		req_type;
	
	size += 1 - 1;//////////////
	ft_putnbr((int)size);
	ft_putendl("");
	while (1)
	{
		i = 0;
		while (i < vault.meta_items_max)
		{
			if (vault.tab_meta[i] == )
			i++;
		}
		break;
	}
	

	return (1);
}