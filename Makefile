# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galy <galy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 10:01:02 by galy              #+#    #+#              #
#    Updated: 2018/01/04 21:00:44 by galy             ###   ########.fr        #
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
				malloc.c			dev_funcs.c			\
				vault_funcs.c		meta_data_funcs.c	\
				find_zone.c			map_zone_funcs.c	\
				free.c				tab_free_funcs.c	\
				

####FUNC####

OBJP		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))


####RULEZ####

all			:	make_lib OBJD $(NAME)

$(NAME)		: $(OBJP)
	@$(CC) $(CFLAGS) -shared -I$(INCDIR) $(LIBFLAG) $^ -o $(NAME)
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

OBJD		:
	@mkdir -p $(OBJDIR)