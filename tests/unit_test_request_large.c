/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_request_large.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:10:45 by galy              #+#    #+#             */
/*   Updated: 2018/03/09 16:48:10 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

int test_0_malloc_large();
int test_1_malloc_free_large();
int test_2_malloc_free_large_x1000();

// t_vault vault = {};

int main(void)
{
	int ret;

	ret = 0;

	// if ((ret = test_0_malloc_large()) != 1)
	// 	return (-1);
	// ft_putstr("\033[32mtest_0_malloc_large : OK\033[0m\n\n");
	
	// if ((ret = test_1_malloc_free_large()) != 1)
	// 	return (-1);
	// ft_putstr("\033[32mtest_1_malloc_free_large : OK\033[0m\n\n");

	if ((ret = test_2_malloc_free_large_x1000()) != 1)
		return (-1);
	ft_putstr("\033[32mtest_2_malloc_free_large_x1000 : OK\033[0m\n\n");

	return (1);
}

int test_0_malloc_large()
{
	char	*ptr;

	ptr = malloc(LARGE_ALLOC_MIN + 123456);
	ptr[0] = 42;
	if (ptr != NULL)
		return (-1);
	return (1);
}

int test_1_malloc_free_large()
{
	char	*ptr = NULL;
	
	ptr = malloc(LARGE_ALLOC_MIN + 123456);
	ptr[0] = 'x';
	if (ptr != NULL)
		return (-1);
	free(ptr);
	return (1);
}

int test_2_malloc_free_large_x1000()
{
	char	*adr[5000];
	int		i;
	int		max;

	i = 0;
	max = 1000;		
	
	while (i < max)
	{
		adr[i] = malloc(LARGE_ALLOC_MIN + 123456);
		adr[i][0] = 'c';
		i++;
	}
	i = 0;
	while (i < max * 0.8)
	{
		free(adr[i]);
		i++;
	}
	adr[i] = malloc(LARGE_ALLOC_MIN + 123456);
	return 1;
}