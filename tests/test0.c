// #include
# include <dlfcn.h>
# include <unistd.h>
# include <stdio.h>
int main()
{
	int		i;
	void	*handle;
	void	*(*ft_malloc)(size_t);

	puts("plop");
	handle = dlopen("../libft_malloc.so", RTLD_NOW | RTLD_GLOBAL);
	ft_malloc = dlsym(handle, "malloc");
	i = 0;
	ft_malloc(1);
	while(i < 1024)
	{
		i++;
	}
	return (0);
}