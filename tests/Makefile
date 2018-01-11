
CC			=	gcc
# CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address
CFLAGS		=	-Wall -Werror -Wextra

LIBFLAG		=	-L../libft -lftall

DIRLIBFT	=	../libft
DIRGNL		=	../get_next_line
DIRFTPRINTF	=	../ft_printf

####DIRECTORY####

SRCDIR		=	../src
OBJDIR		=	objs
INCDIR		=	../inc
LIBDIR		=	../libft


all		:
	@$(CC) $(CFLAGS) -o test0 ./test0.c
	@$(CC) $(CFLAGS) -o test1 ./test1.c
	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./unit_test_meta_data_initializer.c ../src/meta_data_init.c ../src/dev_func.c -o unit_test_meta_data_initializer
	

fclean	:
	rm test0
	rm test1