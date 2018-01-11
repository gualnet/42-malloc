/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_request_tiny_small.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:38:24 by galy              #+#    #+#             */
/*   Updated: 2018/01/11 20:44:17 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

int test_0_request_tiny();
int test_1_request_small();

int	main()
{
	//params dinitialisaton du test
	if (meta_data_initializer() != 1)
	{
		ft_putstr("\033[31mInitialisation du test: Erreur \033[0m\n");
		exit(-1);
	}
		//------//

	test_request_tiny_0();
}

int test_0_request_tiny_0()
{
	
}

int test_1_request_small()
{
	
}