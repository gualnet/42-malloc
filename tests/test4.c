#include <unistd.h>
#include "../inc/malloc.h"

void print(char *s)
{
	write(1, s, strlen(s));
}

// int	main(void)
// {
// 	char *adr;

// 	adr = ft_malloc(16);
// 	ft_putstr("adr = ft_malloc(16) : Ok\n");
// 	ft_free(NULL);
// 	ft_putstr("ft_free(NULL) : Ok\n");
// 	free((void*)adr + 5);
// 	ft_free((void*)adr + 5);
// 	ft_putstr("ft_free((void*)adr + 5) : Ok\n");
// 	if (ft_realloc((void*)adr + 5, 10) == NULL)
// 	{
// 		ft_putstr("Bonjour\n");
// 	}
// }

// #include <stdlib.h>
int	main(void)
{
	char *adr;

	adr = malloc(16);
	// ft_putstr("adr = ft_malloc(16) : Ok\n");
	free(NULL);
	// ft_putstr("ft_free(NULL) : Ok\n");
	free((void*)adr + 5);
	// ft_putstr("ft_free((void*)adr + 5) : Ok\n");
	if (realloc((void*)adr + 5, 10) == NULL)
	{
		ft_putstr("Bonjour\n");
	}
}