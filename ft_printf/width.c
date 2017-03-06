/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:15:48 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/06 00:31:23 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

char	*ft_reput_hex(char *s, int hex, int hexbig)
{
	if (hex)
	{
		s[0] = '0';
		s[1] = 'x';
	}
	if (hexbig)
	{
		s[0] = '0';
		s[1] = 'X';
	}
	return (s);
}

char	*ft_width(char *s, size_t width, char c)
{
	size_t	n;
	char	*space;
	char	flag;
	int		hex;
	int		hexbig;

	flag = s[0];
	hex = ((s[0] == '0') && (s[1] == 'x') && (c == '0'));
	hexbig = ((s[0] == '0') && (s[1] == 'X') && (c == '0'));
	if (ft_is_one_of(flag, "+- ") && (c == '0'))
		s[0] = c;
	if (hex || hexbig)
	{
		s[0] = c;
		s[1] = c;
	}
	n = ft_strlen(s);
	if (n < width)
	{
		space = ft_strnew(width - n);
		ft_fill_str(space, c, width - n);
		s = ft_strjoin_free(space, s, 3);
	}
	s[0] = (ft_is_one_of(flag, "+- ") && (c == '0')) ? flag : s[0];
	return (ft_reput_hex(s, hex, hexbig));
}

char	*ft_width_right(char *s, size_t width, char c)
{
	size_t	n;
	char	*space;

	n = ft_strlen(s);
	if (n < width)
	{
		space = ft_strnew(width - n);
		ft_fill_str(space, c, width - n);
		s = ft_strjoin_free(s, space, 3);
	}
	return (s);
}

char	*ft_width_backslash(char *s, int width, char c)
{
	char	*space;

	if (1 < width)
	{
		space = ft_strnew(width);
		ft_fill_str(space, c, width);
		free(s);
		s = space;
		s[width - 1] = '\0';
	}
	return (s);
}

char	*ft_width_backslash_right(char *s, int width, char c)
{
	char	*space;

	if (1 < width)
	{
		space = ft_strnew(width);
		ft_fill_str(space, c, width);
		free(s);
		s = space;
		s[0] = '\0';
	}
	return (s);
}
