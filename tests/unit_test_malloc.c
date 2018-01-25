/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:39:52 by galy              #+#    #+#             */
/*   Updated: 2018/01/25 10:53:21 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

// t_vault vault = {};
int test_malloc_0();
int test_malloc_tiny_min_and_max();
int	main()
{
	ft_putchar('A');
	
	if (test_malloc_0() != 1)
	{
		ft_putstr("\033[31mtest_malloc_0: Erreur \033[0m\n");
		// exit(-1);
	}
	else
		ft_putstr("\n\033[32mtest_malloc_0 OK\033[0m\n");
	ft_putchar('A');

	if (test_malloc_tiny_min_and_max() == -1)
		ft_putstr("\033[31mtest_malloc_tiny_min: Erreur \033[0m\n");
	if (test_malloc_tiny_min_and_max() == -2)
		ft_putstr("\033[31mtest_malloc_tiny_max: Erreur \033[0m\n");
	else
		ft_putstr("\n\033[32mtest_malloc_tiny_min_and_max OK\033[0m\n");
	return (0);
}

int test_malloc_0()
{
	void	*ret;

	ret = malloc(0);

	if (ret != NULL)
	{
		if (DEBUG_MALLOC)
			ft_printf("malloc(0) = [%p]\n", ret);
		return (-1);
	}
	return (1);
}

int test_malloc_tiny_min_and_max()
{
	if (malloc(TINY_ALLOC_MIN) == NULL)
		return (-1);
	if (malloc(TINY_ALLOC_MAX) == NULL)
		return (-2);
	return (1);
}