# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galy <galy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 12:59:30 by galy              #+#    #+#              #
#    Updated: 2018/03/05 12:04:31 by galy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE	= $(shell uname -m)_$(shell uname -s)
endif

NAME		=	libft_malloc_$(HOSTTYPE).so
SYMLINK		=	libft_malloc.so
CC			=	gcc

# CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address
CFLAGS		=	-Wall -Werror -Wextra

LIBFLAG		=	-L./libft -lftall

DIRLIBFT	=	./libft
DIRGNL		=	./get_next_line
DIRFTPRINTF	=	./ft_printf

####DIRECTORY####

SRCDIR		=	src
OBJDIR		=	objs
INCDIR		=	./inc
LIBDIR		=	libft

####COLOR-SET####

CRESET		=	\033[0m
CRED		=	\033[31m
CGREEN		=	\033[32m
CYELLOW		=	\033[33m
CBLUE		=	\033[34m
CMAGENTA	=	\033[35m
CCYAN		=	\033[36m
CWHITE		=	\033[37m

####CURSOR-SET####
CUR_SVE		=	\033[s
CUR_RST		=	\033[u
CUR_CLR		=	\033[K

####FILES####

SRC			=	\
				malloc.c				free.c				realloc.c\
				converters.c			meta_data_init.c	subz_func.c\
				request_tiny_small.c 	request_large.c		tabs_usage_funcs.c\
				free_func.c				tabs_resizers.c		print_tab_show.c


####FUNC####

OBJP		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))


####RULEZ####

all			:	make_lib OBJD $(NAME)

$(NAME)		: $(OBJP)
	@$(CC) $(CFLAGS) -shared -I$(INCDIR) $(LIBFLAG) $^ -o $(NAME) -lpthread
	@ln -s $(NAME) $(SYMLINK)
	@printf "$(CUR_RST)$(CGREEN)BUILD MALLOC : SUCCESS$(CRESET)$(CUR_CLR)\n"

clean		:
	@make clean -C $(LIBDIR)
	@rm -f $(OBJP)
	@rm -rf $(OBJDIR)
	@printf "$(CYELLOW)ASM OBJECTS DIR CLEARED$(CRESET)\n"

fclean		: clean
	@make fclean -C $(LIBDIR)
	@rm -f $(NAME)
	@rm $(SYMLINK)
	@printf "$(CYELLOW)$(NAME) CLEARED$(CRESET)\n"

re			: fclean all


####MORE_RULEZ####

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
	@printf "$(CUR_RST)$(CUR_SVE)$(CYELLOW)BUILD ASM OBJECTS : $<$(CRESET)$(CUR_CLR)"

make_lib	:
	@make -C $(LIBDIR)

make_tests	:
	

OBJD		:
	@mkdir -p $(OBJDIR)