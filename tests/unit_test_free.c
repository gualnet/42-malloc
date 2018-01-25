#include "../inc/malloc.h"

// t_vault vault = {};
int	test_free_basic(void);
int test_free_02(void);
int test_defrag_merging_bf();
int test_defrag_merging_af();

int	main(void)
{
	ft_putstr("\n\t --====UNIT_TEST_FREE====--\n");

	//test 1
	ft_putstr("START TEST 1\n");
	test_free_basic();
	ft_putstr("END TEST 1\n");

	// test 2
	ft_putstr("START TEST 2\n");
	test_free_02();
	ft_putstr("END TEST 2\n");

	// test 3
	ft_putstr("START TEST defrag merging_bf\n");
	if (test_defrag_merging_bf() != 1)
	{
		ft_printf("Error test_defrag_merging_bf\n");
		exit (0);
	}
	ft_putstr("END TEST defrag merging_bf\n");

	// test 4
	ft_putstr("START TEST defrag merging_af\n");
	if (test_defrag_merging_af() != 1)
	{
		ft_printf("Error test_defrag_merging_af\n");
		exit (0);
	}
	ft_putstr("END TEST defrag merging_af\n");


	return (1);
}

int	test_free_basic(void)
{
	void *adr = (void*)12;

	adr = malloc(123);
	free(adr);

	return (1);
}

int test_free_02(void)
{
	void *adr[8];
	int i;
	int nbr;//nombre d'iterations

	i = 0;
	nbr = 3;
	while (i < nbr)
	{
		adr[i] = malloc(123);
		i++;
	}
	// printAllTabMetaInfo(12);
	// printAllTabFreeInfo(12);
	i = 0;
	while (i < nbr)
	{
		if (i % 2 == 0)
		{
			free(adr[i]);
			ft_printf("0-->%d - %p\n", i, adr[i]);
			adr[i] = NULL;
		}
		i++;
	}
	// printAllTabMetaInfo(12);
	// printAllTabFreeInfo(12);
	i = 0;
	while (i < nbr)
	{
		if (adr[i] != NULL)
		{
			free(adr[i]);
			ft_printf("1-->%d - %p\n", i, adr[i]);
			adr[i] = NULL;
		}
		i++;
	}
	// printAllTabMetaInfo(12);
	// printAllTabFreeInfo(12);
	return (1);
}

int test_defrag_merging_bf()
{
	int i;
	int max;
	void *adr[4];
	
	i = 0;
	max = 4;
	while (i < max)
	{
		adr[i] = malloc(28);
		i++;
	}
	// printAllTabMetaInfo(max + 4);
	// printAllTabFreeInfo(max + 4);
	free(adr[1]);
	// printAllTabMetaInfo(max + 4);
	// printAllTabFreeInfo(max + 4);
	ft_printf("0000\n");

	adr[1] = malloc(4);
	free(adr[1]);
	adr[1] = NULL;
	free(adr[2]);
	adr[2] = NULL;
	// printAllTabMetaInfo(max + 4);
	// printAllTabFreeInfo(max + 4);
	i = 0;
	while (i < max)
	{
		free(adr[i]);
		i++;
	}
	return (1);
}
int test_defrag_merging_af()
{
	ft_printf("0000\n");
	int i;
	int max;
	void *adr[4];
	
	i = 0;
	max = 4;
	
	adr[0] = malloc(1);
	adr[1] = malloc(2);
	adr[2] = malloc(3);
	adr[3] = malloc(4);
	
	free(adr[1]);
	free(adr[2]);
	// printAllTabMetaInfo(max + 4);
	// printAllTabFreeInfo(max + 4);
	
	free(adr[0]);
	// printAllTabMetaInfo(max + 4);
	// printAllTabFreeInfo(max + 4);
	free(adr[3]);
	// printAllTabMetaInfo(max + 4);
	// printAllTabFreeInfo(max + 4);
	return (1);
}