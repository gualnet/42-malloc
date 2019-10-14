# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galy <galy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 12:59:30 by galy              #+#    #+#              #
#    Updated: 2018/05/07 18:35:02 by galy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE	= $(shell uname -m)_$(shell uname -s)
endif

NAME		=	libft_malloc_$(HOSTTYPE).so
SYMLINK		=	libft_malloc.so
CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

LIBFLAG		=	-L./libft -lftall

DIRLIBFT	=	./libft
DIRGNL		=	./get_next_line
DIRFTPRINTF	=	./ft_printf

####DIRECTORY####

SRCDIR		=	./src
OBJDIR		=	./objs
INCDIR		=	./inc
LIBDIR		=	./libft

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
				converters.c         order_tab_show.c     show_alloc_mem2.c \
				meta_data_init.c     print_tab_show.c \
				free.c               realloc.c            subz_func.c \
				free_func.c          request_large.c      tabs_resizers.c \
				malloc.c             request_tiny_small.c tabs_usage_funcs.c \
				show_alloc_mem.c


####FUNC####

OBJP		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))


####RULEZ####

all			:	reset_cursor make_lib OBJD $(NAME)

$(NAME)		: $(OBJP)
	@$(CC) $(CFLAGS) -shared -I$(INCDIR) $(LIBFLAG) $^ -o $(NAME) -lpthread
	@ln -sf $(NAME) $(SYMLINK)
	@printf "$(CUR_RST)$(CGREEN)BUILD MALLOC		: SUCCESS$(CRESET)$(CUR_CLR)\n"

clean		:
	@make clean -C $(LIBDIR)
	@$(RM) -f $(OBJP)
	@$(RM) -rf $(OBJDIR)
	@printf "$(CYELLOW)MALLOC	: CLEANED$(CRESET)\n"

mini_clean	:
	@$(RM) -f $(OBJP)
	@$(RM) -rf $(OBJDIR)

fclean		: mini_clean
	@make fclean -C $(LIBDIR)
	@printf "$(CYELLOW)RAZ MALLOC	: Ok$(CRESET)\n"
	@$(RM) $(SYMLINK)
	@$(RM) $(NAME)

re			: fclean all


####MORE_RULEZ####

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
	@printf "$(CUR_RST)$(CUR_SVE)$(CYELLOW)BUILD MALLOC		: $<$(CRESET)$(CUR_CLR)"

make_lib	:
	@make -C $(LIBDIR)

reset_cursor :
	@printf "$(CUR_SVE)"

OBJD		:
	@mkdir -p $(OBJDIR)
