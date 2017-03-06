/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 00:22:11 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/05 23:37:13 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"
#include <stdarg.h>

t_lol	*ft_init_lol(void)
{
	t_lol	*lol;

	if (!(lol = ft_memalloc(sizeof(t_lol))))
		return (NULL);
	if (!(lol->buf = ft_memalloc(sizeof(char) * (BUFFSIZE + 1))))
		return (NULL);
	lol->len = BUFFSIZE;
	return (lol);
}

int		bufferise(t_lol *lol, char *format, va_list ap)
{
	long	i;

	i = -1;
	if ((i = ft_strchri(format, '%')) == -1)
	{
		ft_cpy_buf(format, lol, ft_strlen(format));
		return (0);
	}
	else if (i >= 0)
	{
		lol->cur += i;
		ft_cpy_buf(format, lol, i);
		ft_parse(format + i, lol, ap);
		return (1);
	}
	return (1);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_lol		*lol;

	if (!(lol = ft_init_lol()))
		return (-1);
	va_start(ap, format);
	while (bufferise(lol, (char *)(format + lol->cur), ap))
		;
	va_end(ap);
	ft_putnstr(lol->buf, lol->i);
	free(lol->buf);
	free(lol);
	return (lol->i);
}
