// #include "stdlib.h"
// #include "unistd.h"
#include "../inc/malloc.h"

int main(void)
{
	int		i;
	char	*adr;
	
	i = 0;
	while(i < 1024)
	{
		adr = (char*)ft_malloc(1024);
		adr[0] = 42;
		i++;
	}
	return (0);
}