# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#*   Updated: 2017/02/02 19:13:02 by mlamoure         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

LIBS = ../libft/libft.a

SRC =	ft_printf.c			\
		take_opt.c			\
		cpy_buf.c			\
		parsing.c			\
		width.c				\
		convert.c			\
		unicode.c			\
		undefined_conv.c	\
		convert_int.c		\
		convert_str.c		\
		convert_char.c		\
		convert_pointer.c	\
		handle_width.c		\
		ft_calc_nb_bit.c	\
		type_int.c			\

INCLUDE = ../libft/

SRC_LIBFT = $(addprefix libft/, $(LIBFT_FUN))

OBJS_LIBFT = $(addprefix objs/libft/, $(LIBFT_FUN:.c=.o))

OBJS = $(addprefix objs/, $(SRC:.c=.o))

FLAGS += -Wall -Wextra -Werror

all: compilib $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

compilib:
	make -C ../libft

clean:
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

objs/%.o : %.c
	@/bin/mkdir -p objs
	gcc $(FLAGS) -g -I $(INCLUDE) -c -o $@ $<

.PHONY: all clean fclean re
