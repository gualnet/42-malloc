/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_subz_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:10:45 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 16:18:49 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

// t_vault vault = {};
int 	test0();


int		main(void)
{
	//init
	free(malloc(12));

	int ret;

	ret = 0;

	test0();

	ft_putstr("THE END\n");
	return (1);
}


int 	test0()
{
	return (1);
}