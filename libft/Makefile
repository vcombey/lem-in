# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 16:54:16 by vcombey           #+#    #+#              #
#    Updated: 2017/03/07 00:24:17 by vcombey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = libft.h

NAME = libft.a

SRC = ft_dtoa.c \
	ft_mem{alloc,ccpy,chr,cmp,cpy,del,move,set}.c \
	ft_bzero.c \
	ft_strlcat.c \
	ft_strnew.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_is{alnum,alpha,blanckspace,ascii,digit,print}.c \
	ft_strlen.c \
	ft_str{cat,cpy,cmp,equ,str}.c \
	ft_strn{cat,cpy,cmp,equ,str}.c \
	ft_strdup.c \
	ft_strclr.c \
	ft_strsub.c \
	ft_strdel.c \
	ft_str{iter,iteri}.c \
	ft_strjoin.c \
	ft_strjoin_free.c \
	ft_str{map,mapi}.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strtrim.c \
	ft_to{lower,upper}.c \
	ft_put{char,char_fd,endl,endl_fd,nbr,nbr_fd,str,str_fd}.c \
	ft_lst{add,del,delone,iter,map,new}.c \
	ft_islower.c \
	ft_isupper.c \
	get_next_line.c \
	ft_strstrlen.c	\
	ft_tab_free.c	\
	ft_uitoa.c	\
	ft_itoa_base.c	\
	ft_uitoa_base.c	\
	ft_retmsg.c	\
	ft_putstrstr.c	\
	ft_strchri.c	\
	ft_strjoin3_free.c	\
	ft_error.c	\
	ft_is_one_of.c	\
	ft_putnstrstr.c	\
	ft_tab_int_free.c	\
	ft_fill_str.c		\
	ft_putnstr.c		\
	ft_str_capitalize.c	\
	ft_strdup_char.c	\

SRC_O = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDE)
	ar rcs $(NAME) $(SRC_O)

clean:
	@/bin/rm -f $(SRC_O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
