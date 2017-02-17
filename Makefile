# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#    Updated: 2017/02/14 02:25:37 by vcombey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	vcombey.filler

SRC =	main.c						\
		quadrature_of_the_piece.c	\

INCLUDE = libft/

OBJS = $(addprefix objs/, $(SRC:.c=.o))

CFLAGS += -Wall -g -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	gcc -g $(OBJS) -L libft -lft -o $(NAME)

clean:
	make clean -C ./libft/
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f ./libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all

objs/%.o : %.c
	@/bin/mkdir -p objs
	gcc -g $(CFLAGS) -I $(INCLUDE) -c -o $@ $<

.PHONY: all clean fclean re
