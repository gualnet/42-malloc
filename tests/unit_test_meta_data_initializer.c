/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_meta_data_initializer.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:24:29 by galy              #+#    #+#             */
/*   Updated: 2018/01/11 19:31:51 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

t_vault vault = {};
int test1();
int test2();
int test3();

//test des fonctions d'initialisation du vault ()
int main()
{
	if (test1() != 1)
	{
		ft_printf("\033[31mtest 1: Erreur dans l'initialisation de tab_meta\033[0m\n");
		exit(-1);
	}
	else
		ft_printf("\n\033[32mtest 1 OK\033[0m\n");

	if (test2() != 1)
	{
		ft_printf("\033[31mtest 2: Erreur dans l'initialisation de tab_free\033[0m\n");
		exit(-1);
	}
	else
		ft_printf("\033[32mtest 2 OK\033[0m\n");

	if (test3() != 1)
	{
		ft_printf("\033[31mtest 3: Erreur dans l'initialisation du vault\033[0m\n");
		exit(-1);
	}
	else
		ft_printf("\033[32mtest 3 OK\033[0m\n");

	return 1;
}

// test1: appel de create_tab_meta()
int test1()
{
	
	//params dinitialisaton du test
	vault.tab_meta = NULL;
		//------//
		
	// ft_printf("tab adress : %p\n", vault.tab_meta);
	if (create_tab_meta() != 1)
		return (-1);
	if (vault.tab_meta == NULL)
		return (-1);
	if (DEBUG_MALLOC)
		printCreateMetaTabCR();
	// ft_printf("tab adress : %p\n", vault.tab_meta);
	
	return (1);
}

// test2: appel de create_tab_free()
int test2()
{
	//params dinitialisaton du test
	vault.tab_free = NULL;
		//------//
	if (create_tab_free() != 1)
		return (-1);
	if (vault.tab_free == NULL)
		return (-1);
	if (DEBUG_MALLOC)
		printCreateFreeTabCR();
	return (1);
}

// test3: appel de meta_data_initializer()
int test3()
{
	vault.tab_meta = NULL;
	if (meta_data_initializer() != 1)
		return (-1);
	return (1);
}