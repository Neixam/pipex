# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 17:08:30 by ambouren          #+#    #+#              #
#    Updated: 2022/06/26 16:59:58 by ambouren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  Variable
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

CC      =	gcc

CFLAGS  =	-Wall -Wextra -Werror -g
IFLAGS	=	-I includes/ -I libs/libft/includes/ -I libs/libftprintf/includes/
LDFLAGS	=	-L libs/ -lft -lftprintf
EXEC	=	pipex

INC_PATH=	includes/
DEP_PATH=	deps/
OBJ_PATH=	objs/
LIB_PATH=	libs/
SRC_PATH=	$(shell find srcs -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
vpath %.a $(LIB_PATH)
LIB		=	libft.a \
			libftprintf.a
SRC		=	main.c \
            cmd.c \
            parsing.c \
            data.c \
			ft_error.c
DEP		=	$(addprefix $(DEP_PATH), $(SRC:.c=.d))
OBJ		=	$(addprefix $(OBJ_PATH), $(SRC:.c=.o))

#	Compilation
all		:	$(EXEC)

$(EXEC)			:	$(OBJ) $(addprefix $(LIB_PATH), $(LIB))
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.a				:
	@make -C $(@:.a=) install 

$(OBJ_PATH)%.o	:	%.c
	@mkdir -p $(OBJ_PATH) $(DEP_PATH)
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS) -MMD
	@mv $(@:.o=.d) $(DEP_PATH)

-include $(DEP)

#	Rule
clean	:
	rm -rf $(OBJ_PATH)
	rm -rf $(DEP_PATH)

fclean	:	clean
	rm -rf $(EXEC)
	rm -rf $(addprefix $(LIB_PATH), $(LIB))
	$(foreach lib, $(LIB), $(shell make -C $(LIB_PATH)$(lib:.a=) fclean))

re		:	fclean all

.PHONY	:	all clean fclean re
