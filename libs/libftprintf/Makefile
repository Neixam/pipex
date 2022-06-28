# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambouren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 14:43:04 by ambouren          #+#    #+#              #
#    Updated: 2021/12/07 15:35:43 by ambouren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

# VARIABLE
NAME	=	libftprintf.a
CC		=	gcc
LC		=	ar crs
CFLAGS	=	-Wall \
			-Wextra \
			-Werror
U_NAME	=	$(shell uname -s)
ifeq ($(U_NAME), Linux)
	CFLAGS += -DLINUX
endif
INC_PATH=	includes/
INCLUDES=	ft_printf.h
BONUS_I	=	ft_printf_bonus.h
SRC		=	ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putmajhex.c \
			ft_puthex.c \
			ft_putadd.c \
			ft_printf.c \
			ft_strichr.c \
			ft_putuns.c
BONUS_S	=	ft_putchar_bonus.c \
			ft_putstr_bonus.c \
			ft_putnbr_bonus.c \
			ft_putmajhex_bonus.c \
			ft_puthex_bonus.c \
			ft_putadd_bonus.c \
			ft_printf_bonus.c \
			ft_strichr.c \
			ft_putuns_bonus.c \
			ft_len.c \
			ft_flag.c
SRC_PATH=	$(shell find srcs -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))

OBJ_PATH=	obj/
BONUS_O	=	$(addprefix $(OBJ_PATH),$(BONUS_S:.c=.o))
OBJ 	=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

# COMPILATION
$(NAME)		:	$(OBJ)
	$(LC) $@ $^

$(OBJ)		:	$(INC_PATH)$(INCLUDES)

$(BONUS_O)	:	$(INC_PATH)$(BONUS_I)

$(OBJ_PATH)%.o		:	%.c
	@mkdir -p obj
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH)

# RULES
all		:	$(NAME)

clean	:
	rm -rf $(OBJ_PATH)

fclean	:	clean
	rm -rf $(NAME)

bonus	:	$(BONUS_O)
	rm -rf $(NAME)
	$(LC) $(NAME) $^

install	:	bonus
	mv $(NAME) ../$(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus install
