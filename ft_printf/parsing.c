/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:51:27 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/06 00:26:36 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"
#include <stdarg.h>

size_t	ft_double_percent(char *str)
{
	size_t i;

	i = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '%')
		return (i);
	return (0);
}

int		take_ap(char *format, t_lol *lol, va_list ap)
{
	t_opt	opt;

	opt = (t_opt){0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (!(take_opt(format, &opt, lol)))
		return (0);
	ft_convert(opt, lol, ap);
	return (1);
}

int		ft_parse(char *format, t_lol *lol, va_list ap)
{
	size_t	k;

	if ((k = ft_double_percent(format)) > 0)
	{
		ft_cpy_buf("%", lol, 1);
		lol->cur += k + 1;
		return (1);
	}
	else if (take_ap(format, lol, ap))
		return (1);
	return (0);
}
