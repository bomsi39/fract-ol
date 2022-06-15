# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 18:24:09 by dfranke           #+#    #+#              #
#    Updated: 2022/06/15 15:06:01 by dfranke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= fractol
FILES:= drw \
		evnts \
		frctls \
		init_clrs \
		main \

#-------libft--------
LIBFT_DIR:=./libft/

#------minilibx------
MINILIBX_DIR:=./minilibx_opengl/


CC:=gcc
SOURCES_DIR:=srcs/
HEADER_DIR:=includes/
OBJECTS_DIR:=objs/
IFLAGS:=-I $(HEADER_DIR) -I $(LIBFT_DIR)includes -I $(MINILIBX_DIR)
LFLAGS:=-lft -L $(LIBFT_DIR) -lmlx -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
CFLAGS:=-Wall -Werror -Wextra $(IFLAGS)

#------Paths---------
SOURCES:=$(addprefix $(SOURCES_DIR),$(addsuffix .c,$(FILES)))
OBJECTS:=$(addprefix $(OBJECTS_DIR),$(addsuffix .o,$(FILES)))
#====================

#------Colors--------
BLACK:="\033[1;30m"
RED:="\033[1;31m"
BGREEN:="\033[1;32m"
GREEN:="\033[0;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
#====================
CACHE:=.cache_exists


all: $(NAME)

$(NAME): $(OBJECTS)
	@cd $(LIBFT_DIR) && $(MAKE)
	@cd $(MINILIBX_DIR) && $(MAKE)
	@echo $(PURPLE) " -> Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(SOURCES) -o $@ $(LFLAGS)
	@echo $(BGREEN) " -> OK" $(EOC)
	
$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c | $(CACHE)
	@echo $(CYAN) " -> Compiling $< into $@" $(EOC)
	@$(CC) $(CFLAGS) -c $< -o $@

$(CACHE):
	@mkdir -p $(OBJECTS_DIR)
	@touch $(CACHE)
	
clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(MINILIBX_DIR) clean
	@rm -f $(CACHE)
	@rm -rf $(OBJECTS_DIR)
	@echo $(GREEN) " -> $(NAME) cache cleaned"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@echo $(RED)"  -> $(NAME) deleted"

re:
	@$(MAKE) fclean
	@$(MAKE) all

bonus: all

.PHONY:		all clean fclean re

norm:
	@norminette -R CheckForbiddenSourceHeader $(SOURCES) $(HEADER_DIR)