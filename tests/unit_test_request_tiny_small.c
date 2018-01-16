/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_request_tiny_small.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:38:24 by galy              #+#    #+#             */
/*   Updated: 2018/01/16 11:55:35 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

t_vault vault = {};
int test_0_request_tiny();
int test_1_request_small();

int	main()
{
	int ret;

	ret = 0;

	//params dinitialisaton du test
	if (meta_data_initializer() != 1)
	{
		ft_putstr("\033[31mInitialisation du test: Erreur \033[0m\n");
		exit(-1);
	}
		//------//
	ft_putstr("Init : OK\n");
	
	// ret = test_0_request_tiny();
	// if (ret == 1)
	// 	ft_putstr("\033[32mtest_0_request_tiny: ok\033[0m\n");

	ret = test_1_request_small();
	if (ret == 1)
		ft_putstr("\033[32mtest_1_request_small: ok\033[0m\n\n");
}

int test_0_request_tiny()
{
	if (request_tiny_small(10) != 1)
		return (-1);
	ft_putstr("\033[32mrequest tiny 1 x 10 : ok\033[0m\n");
	
	int i = 0;
	while (i < 1024)
	{
		if (request_tiny_small(10) == (unsigned int)-1)
			return (-1);
		i++;
	}
	ft_putstr("\033[32mrequest tiny 1024 x 10 : ok\033[0m\n");
	
	return (1);
}

int test_1_request_small()
{
	
	if (request_tiny_small(SMALL_ALLOC_MIN + 10) != 1)
		return (-1);
	ft_putstr("\033[32mrequest small 1 x SMALL_ALLOC_MIN + 10 : ok\033[0m\n");
	
	int i = 0;
	while (i < 1024)
	{

		if (request_tiny_small(SMALL_ALLOC_MIN + 10) == (unsigned int)-1)
			return (-1);
		i++;
	}
	ft_putstr("\033[32mrequest small 1024 x SMALL_ALLOC_MIN + 10 : ok\033[0m\n");
	
	return (1);
}