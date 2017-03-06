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

LIBS = libft/libft.a

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

LIBFT_FUN =	ft_dtoa.c \
		ft_fill_str.c \
		ft_is_one_of.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isblanckspace.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strcat.c \
		ft_strcpy.c \
		ft_strcmp.c \
		ft_strequ.c \
		ft_strstr.c \
		ft_strncat.c \
		ft_strncpy.c \
		ft_strncmp.c \
		ft_strnequ.c \
		ft_strnstr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_bzero.c \
		ft_strlcat.c \
		ft_strnew.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strclr.c \
		ft_strsub.c \
		ft_strdel.c \
		ft_strjoin.c \
		ft_strjoin_free.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strtrim.c \
		ft_islower.c \
		ft_isupper.c \
		get_next_line.c \
		ft_strstrlen.c \
		tab_free.c \
		ft_uitoa.c \
		ft_strjoin3_free.c \
		ft_printmemory_bin.c \
		ft_putstrij.c \
		error.c \
		ft_itoa_base.c \
		ft_str_capitalize.c \
		ft_uitoa_base.c \
		ft_strchri.c \
		ft_putnstr.c \
		ft_strdup_char.c\
		ft_memcpy.c \

INCLUDE = libft/include

SRC_LIBFT = $(addprefix libft/, $(LIBFT_FUN))

OBJS_LIBFT = $(addprefix objs/libft/, $(LIBFT_FUN:.c=.o))

OBJS = $(addprefix objs/, $(SRC:.c=.o))

FLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIBFT)
	#gcc $(OBJS) $(OBJS_LIBFT)
	ar rc $(NAME) $(OBJS) $(OBJS_LIBFT)

clean:
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

objs/libft/%.o : libft/%.c
	gcc $(FLAGS) -I $(INCLUDE) -c $< -o $@

objs/%.o : %.c
	@/bin/mkdir -p objs
	/bin/mkdir -p objs/libft
	gcc $(FLAGS) -g -I $(INCLUDE) -c -o $@ $<

.PHONY: all clean fclean re
