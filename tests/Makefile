
CC			=	gcc
# CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address
CFLAGS		=	-Wall -Werror -Wextra

LIBFLAG		=	-L../libft -lftall

DIRLIBFT	=	../libft
DIRGNL		=	../get_next_line
DIRFTPRINTF	=	../ft_printf

####DIRECTORY####

SRCDIR		=	../src
OBJDIR		=	./testobjs
INCDIR		=	../inc
LIBDIR		=	../libft


####FUNC####

OBJP		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))


all		: OBJD tests

tests	:

# ../src/malloc.c ../src/free.c ../src/realloc.c ../src/converters.c\
../src/meta_data_init.c ../src/subz_func.c ../src/request_tiny_small.c\
../src/request_large.c ../src/dev_func.c ../src/tabs_usage_funcs.c \


	@$(CC) $(CFLAGS) -o _test0 ./test0.c
	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./test1.c \
../src/malloc.c ../src/free.c ../src/realloc.c ../src/converters.c \
../src/meta_data_init.c ../src/subz_func.c ../src/request_tiny_small.c \
../src/request_large.c ../src/dev_func.c ../src/tabs_usage_funcs.c \
-o _test1
	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./test2.c \
../src/malloc.c ../src/free.c ../src/realloc.c ../src/converters.c \
../src/meta_data_init.c ../src/subz_func.c ../src/request_tiny_small.c \
../src/request_large.c ../src/dev_func.c ../src/tabs_usage_funcs.c \
-o _test2
#	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./unit_test_meta_data_initializer.c \
../src/malloc.c ../src/free.c ../src/realloc.c ../src/converters.c \
../src/meta_data_init.c ../src/subz_func.c ../src/request_tiny_small.c \
../src/request_large.c ../src/dev_func.c ../src/tabs_usage_funcs.c \
-o _test_meta_data_initializer
#	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./unit_test_malloc.c \
../src/malloc.c ../src/free.c ../src/realloc.c ../src/converters.c \
../src/meta_data_init.c ../src/subz_func.c ../src/request_tiny_small.c \
../src/request_large.c ../src/dev_func.c ../src/tabs_usage_funcs.c \
-o _test_malloc
#	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./unit_test_request_tiny_small.c \
../src/malloc.c ../src/free.c ../src/realloc.c ../src/converters.c \
../src/meta_data_init.c ../src/subz_func.c ../src/request_tiny_small.c \
../src/request_large.c ../src/dev_func.c ../src/tabs_usage_funcs.c \
-o _test_request_tiny_small
#	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./unit_test_free.c \
../src/malloc.c ../src/free.c ../src/realloc.c ../src/converters.c \
../src/meta_data_init.c ../src/subz_func.c ../src/request_tiny_small.c \
../src/request_large.c ../src/dev_func.c ../src/tabs_usage_funcs.c \
-o _test_free
#	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./unit_test_request_large.c \
../src/malloc.c ../src/free.c ../src/realloc.c ../src/converters.c \
../src/meta_data_init.c ../src/subz_func.c ../src/request_tiny_small.c \
../src/request_large.c ../src/dev_func.c ../src/tabs_usage_funcs.c \
-o _test_request_large
#	@$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFLAG) ./unit_test_subz_func.c \
../src/malloc.c ../src/free.c ../src/realloc.c ../src/converters.c \
../src/meta_data_init.c ../src/subz_func.c ../src/request_tiny_small.c \
../src/request_large.c ../src/dev_func.c ../src/tabs_usage_funcs.c \
-o _test_subz_func



fclean	:
	rm -rf $(OBJDIR)
	@rm		_test0		_test1		_test2			_test_meta_data_initializer	\
	_test_malloc		_test_request_tiny_small	_test_free		_test_request_large	_test_subz_func

####MORE_RULEZ####

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
	@printf "$(CUR_RST)$(CUR_SVE)$(CYELLOW)BUILD ASM OBJECTS : $<$(CRESET)$(CUR_CLR)"

OBJD		:
	@mkdir -p $(OBJDIR)