# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#              #
#    Updated: 2020/01/11 16:02:16 by dholiday         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPATH = ./Libft
LIBFT = $(LIBFTPATH)/libft.a

CFLAGS =  -I. -I$(LIBFTPATH) -Iinc -g3
CC = gcc

SRC_PATH = ./src/

SRC_NAME = main.c identify.c echo.c help.c \
setenv.c env.c unsetenv.c apply.c cd.c \
quote.c ft_use_var.c hello_all.c print.c \
print_for_echo.c additional.c 
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(SRC:%.c=%.o)

NAME = minishell

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJ) 
	gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ) : ./ft_minishell.h

$(LIBFT) :
	make -C $(LIBFTPATH)

clean:
	make clean -C $(LIBFTPATH)
	rm -f $(OBJ) 

fclean: clean
	make fclean -C $(LIBFTPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
