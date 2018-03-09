/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:13:25 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 19:11:04 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_err(void)
{
	if (ft_strcmp(getenv("DEBUG_MALLOC"), "TRUE") == 0)
		ft_putstr("\033[31mError memory mapping failed\n\033[0m");
	exit(-1);
}
