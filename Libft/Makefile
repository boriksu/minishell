# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#              #
#    Updated: 2019/10/04 17:31:46 by dholiday         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a

CFLAGS = -Wall -Wextra -Werror -I.
CC = gcc
SRC = ft_sum_w.c ft_list_push_back.c ft_bzero.c \
	  ft_isascii.c ft_list_size.c \
	  ft_isalpha.c ft_list_last.c \
	  ft_isalnum.c ft_str_is_alpha.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memset.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_strchr.c \
	  ft_tolower.c \
	  ft_strrchr.c \
	  ft_toupper.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_strcpy.c \
	  ft_strcat.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_strncat.c \
	  ft_strncpy.c \
	  ft_strlcat.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_itoa.c ft_strnew.c \
	  ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_memalloc.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strdel.c ft_memdel.c \
	  ft_memmove.c ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c \
	  ft_lstdel.c ft_lstmap.c get_next_line.c \
	  all_types.c convert.c find_null_d_sharp.c format.c ft_printf.c \
	  helper_2.c helpers.c info.c new_printf.c null.c sharp.c swap_str.c type_f.c wide_dioux.c \
	  wide_p.c wide_s.c ft_splitwhitespaces.c ft_clean_mass.c 
#SRC := $(addprefix , $(SRC))
OBJ = $(SRC:%.c=%.o)

NAME = $(LIBFT)

all: $(NAME)

$(OBJ) : libft.h

$(LIBFT) : $(OBJ) libft.h
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
