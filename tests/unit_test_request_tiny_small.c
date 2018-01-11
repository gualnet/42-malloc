/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_request_tiny_small.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:38:24 by galy              #+#    #+#             */
/*   Updated: 2018/01/11 20:57:19 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

t_vault vault = {};
int test_0_request_tiny();
int test_1_request_small();

int	main()
{
	ft_putchar('X');

	//params dinitialisaton du test
	if (meta_data_initializer() != 1)
	{
		ft_putstr("\033[31mInitialisation du test: Erreur \033[0m\n");
		exit(-1);
	}
		//------//
	ft_putstr("Init : OK\n");
	test_0_request_tiny();
}

int test_0_request_tiny()
{
	if (request_tiny_small(10) != 1)
		return (-1);
	
	return (1);
}

int test_1_request_small()
{
	return (-1);
}