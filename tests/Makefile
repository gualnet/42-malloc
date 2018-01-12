
CC			=	gcc
# CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address
CFLAGS		=	-Wall -Werror -Wextra

LIBFLAG		=	-L../libft -lftall

DIRLIBFT	=	../libft
DIRGNL		=	../get_next_line
DIRFTPRINTF	=	../ft_printf

####DIRECTORY####

SRCDIR		=	../src
OBJDIR		=	testobjs
INCDIR		=	../inc
LIBDIR		=	../libft


####FUNC####

OBJP		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))


all		: OBJD tests

tests	:
#./unit_test_XXXXXX.c ../src/malloc.c ../src/meta_data_init.c ../src/dev_func.c ../src/request_tiny_small.c ../src/converters.c
#	@$(CC) $(CFLAGS) -o test0 ./test0.c
#	@$(CC) $(CFLAGS) -o test1 ./test1.c
#	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./unit_test_meta_data_initializer.c ../src/meta_data_init.c ../src/dev_func.c -o unit_test_meta_data_initializer
#	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./unit_test_malloc.c ../src/malloc.c ../src/meta_data_init.c ../src/dev_func.c ../src/request_tiny_small.c -o unit_test_malloc
	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./unit_test_request_tiny_small.c ../src/malloc.c ../src/meta_data_init.c ../src/dev_func.c ../src/converters.c ../src/request_tiny_small.c ../src/subz_func.c -o unit_test_request_tiny_small

fclean	:
	rm -rf $(OBJDIR)
	@rm test0 test1 unit_test_meta_data_initializer unit_test_malloc unit_test_request_tiny_small
#	@rm test1
#	@rm unit_test_meta_data_initializer
#	@rm unit_test_malloc
#	@rm unit_test_request_tiny_small

####MORE_RULEZ####

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
	@printf "$(CUR_RST)$(CUR_SVE)$(CYELLOW)BUILD ASM OBJECTS : $<$(CRESET)$(CUR_CLR)"

OBJD		:
	@mkdir -p $(OBJDIR)