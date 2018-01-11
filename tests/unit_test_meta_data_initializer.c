/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_meta_data_initializer.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:24:29 by galy              #+#    #+#             */
/*   Updated: 2018/01/11 17:01:07 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

t_vault vault = {};
int test1();

//test des fonctions d'initialisation du vault ()
int main()
{
	if (test1() != 1)
	{
		ft_printf("Erreur dans l'initialisation de tab_meta");
		exit(-1);
	}

	return 1;
}

// test1: appel de create_tab_meta()
int test1()
{
	vault.tab_meta = NULL;
	
	// ft_printf("tab adress : %p\n", vault.tab_meta);
	vault.tab_meta = create_tab_meta();
	printCreateTabCR();
	if (vault.tab_meta != NULL)
		return (1);
	// ft_printf("tab adress : %p\n", vault.tab_meta);
	return (0);
}