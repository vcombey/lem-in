# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#    Updated: 2017/03/06 20:27:02 by vcombey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	lem-in

SRC =	main.c						\
		lem-in.c					\
		get_rooms.c					\
		get_links.c					\
		display_solus.c				\
		free_all_the_shit.c			\
		utils/ft_exit_err.c			\
		utils/room_len.c			\
			debug.c					\

INCLUDE = -I libft/ -I ./ft_printf/ -I ./include

LIBS = -L ./libft -lft -L ./ft_printf/ -lftprintf

OBJS = $(addprefix objs/, $(SRC:.c=.o))

CFLAGS += -Wall -g -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	make -C ./ft_printf/
	gcc -g $(OBJS) $(LIBS) -o $(NAME)

clean:
	make clean -C ./libft/
	make clean -C ./ft_printf/
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f ./libft/libft.a
	/bin/rm -f ./ft_printf/libft.a
	/bin/rm -f $(NAME)

re: fclean all

objs/%.o : %.c
	@/bin/mkdir -p objs
	@/bin/mkdir -p objs/utils
	gcc -g $(CFLAGS) $(INCLUDE) -c -o $@ $<

.PHONY: all clean fclean re
