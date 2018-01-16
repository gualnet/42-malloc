#include "../inc/malloc.h"

t_vault vault = {};
int	test_free_without_initialization(void);

int	main(void)
{
	ft_putstr("\n\t --====UNIT_TEST_FREE====--\n");

	//test 1
	ft_putstr("START TEST 1\n");
	test_free_without_initialization();
	ft_putstr("END TEST 1\n");



	return (1);
}

int	test_free_without_initialization(void)
{
	void *adr = (void*)12;

	adr = ft_malloc(123);
	ft_free(adr);
	return (0);
}