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

NAME =	lem-in

SRC =	main.c						\
		lem-in.c					\
		get_rooms.c					\
		get_links.c				\

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
