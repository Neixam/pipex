# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 17:08:30 by ambouren          #+#    #+#              #
#    Updated: 2022/06/29 09:53:54 by ambouren         ###   ########.fr        #
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
IFLAGS	=	-I includes/ -I libs/libft/includes/
LDFLAGS	=	-L libs/ -lft
EXEC	=	pipex

INC_PATH=	includes/
DEP_PATH=	deps/
OBJ_PATH=	objs/
LIB_PATH=	libs/
SRC_PATH=	$(shell find srcs -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
vpath %.a $(LIB_PATH)
LIB		=	libft.a
SRC		=	main.c \
            cmd.c \
            parsing.c \
            data.c \
			ft_error.c \
			pipe.c
BONUS	=	main_bonus.c \
            cmd.c \
            parsing_bonus.c \
            data.c \
			ft_error.c \
			pipe_bonus.c
DEP		=	$(addprefix $(DEP_PATH), $(SRC:.c=.d))
OBJ		=	$(addprefix $(OBJ_PATH), $(SRC:.c=.o))
BON_OBJ	=	$(addprefix $(OBJ_PATH), $(BONUS:.c=.o))

#	Compilation
all		:	$(EXEC)

$(EXEC)			:	$(addprefix $(LIB_PATH), $(LIB)) $(OBJ)
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
	make -C $(LIB_PATH)$(LIB:.a=) fclean
# $(foreach lib, $(LIB), $(shell make -C $(LIB_PATH)$(lib:.a=) fclean))

re		:	fclean all

bonus	:	$(addprefix $(LIB_PATH), $(LIB)) $(BON_OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(BON_OBJ) $(LDFLAGS)

.PHONY	:	all clean fclean re bonus
