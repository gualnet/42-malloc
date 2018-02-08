
#include "../inc/malloc.h"
#define M (1024 * 1024)
void print(char *s)
{
	write(1, s, strlen(s));
}


void test_realloc_00(void)
{
	char	*adr1;
	char	*adr3;

	int i = 0;
	while (i < 1)
	{
		adr1 = (char*)ft_malloc(16 * M);
		strcpy(adr1, "Bonjour\n");
		print(adr1);

		adr3 = (char*)ft_realloc(adr1, 128 * M);
		adr3[15 * M] = 42;
		print(adr3);
		i++;
	}
}

void test_realloc_01(void)
{
	char	*adr1;
	char	*adr2;
	char	*adr3;

	int i = 0;
	while (i < 1)
	{
		adr1 = (char*)ft_malloc(16 * M);
		strcpy(adr1, "Bonjour\n");
		print(adr1);

		adr2 = (char*)ft_malloc(16 * M);

		adr3 = (char*)ft_realloc(adr1, 128 * M);
		adr3[127 * M] = 42;
		print(adr3);
		i++;
	}
}

int main(void)
{
	test_realloc_00();
	ft_putstr("test realloc   : OK\n");
	test_realloc_01();
	ft_putstr("test realloc++ : OK\n");
	return (0);
}

// void print(char *s)
// {
// 	write(1, s, strlen(s));
// }
// int main(void)
// {
// 	char	*adr1;
// 	char	*adr3;

// 	adr1 = (char*)malloc(16 * M);
// 	strcpy(adr1, "Bonjour\n");
// 	print(adr1);

// 	adr3 = (char*)realloc(adr1, 128 * M);
// 	adr3[127 * M] = 42;
// 	print(adr3);
// 	return (0);
// }