#include "../inc/malloc.h"

t_vault vault = {};
int	test_free_basic(void);
int test_free_02(void);

int	main(void)
{
	ft_putstr("\n\t --====UNIT_TEST_FREE====--\n");

	// //test 1
	// ft_putstr("START TEST 1\n");
	// test_free_basic();
	// ft_putstr("END TEST 1\n");

	//test 2
	ft_putstr("START TEST 2\n");
	test_free_02();
	ft_putstr("END TEST 2\n");


	return (1);
}

int	test_free_basic(void)
{
	void *adr = (void*)12;

	adr = ft_malloc(123);
	ft_free(adr);

	return (1);
}

int test_free_02(void)
{
	void *adr[8];
	int i;

	i = 0;
	while (i < 8)
	{
		adr[i] = ft_malloc(123);
		i++;
	}
	printAllTabMetaInfo(12);
	printAllTabFreeInfo(12);
	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
		{
			ft_free(adr[i]);
			adr[i] = NULL;
		}
		i++;
	}
	printAllTabMetaInfo(12);
	printAllTabFreeInfo(12);
	i = 0;
	while (i < 8)
	{
		if (adr[i] != NULL)
		{
			ft_free(adr[i]);
			adr[i] = NULL;
		}
		i++;
	}
	printAllTabMetaInfo(12);
	printAllTabFreeInfo(12);
	return (1);
}