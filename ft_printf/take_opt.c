/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 00:24:32 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/06 00:26:31 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

size_t	ft_while_type(size_t i, char *format, t_opt *opt)
{
	while (ft_is_one_of(format[i], "hljz"))
	{
		if (format[i] == 'l' && format[i + 1] == 'l')
			opt->type = 'a';
		else if (format[i] == 'h' && format[i + 1] == 'h')
			opt->type = 'b';
		else if (format[i] == 'h' && format[i - 1] != 'h')
			opt->type = 'h';
		else if (format[i] == 'l' && format[i - 1] != 'h')
			opt->type = 'l';
		else if (format[i] == 'j')
			opt->type = 'j';
		else if (format[i] == 'z')
			opt->type = 'z';
		i++;
	}
	return (i);
}

int		ft_take_conv(char c, size_t i, t_opt *opt, t_lol *lol)
{
	if (ft_is_one_of(c, "sSpdDioOuUxXcC"))
	{
		opt->conv = c;
		lol->cur += (i + 1);
		return (1);
	}
	else if (c)
	{
		ft_convert_undefined_conv(c, *opt, lol);
		lol->cur += (i + 1);
	}
	else
		lol->cur += i;
	return (0);
}

int		take_opt(char *format, t_opt *opt, t_lol *lol)
{
	size_t i;

	i = 1;
	while (ft_is_one_of(format[i], " -+#0"))
	{
		opt->minus = (format[i] == '-') ? 1 : opt->minus;
		opt->plus = (format[i] == '+') ? 1 : opt->plus;
		opt->diese = (format[i] == '#') ? 1 : opt->diese;
		opt->zero = (format[i] == '0') ? 1 : opt->zero;
		opt->space = (format[i] == ' ') ? 1 : opt->space;
		i++;
	}
	opt->width = ft_is_one_of(format[i], "0123456789") ?
		ft_atoi(format + i) : -1;
	while (ft_is_one_of(format[i], "0123456789"))
		i++;
	opt->prec = format[i] == '.' ? ft_atoi(format + i + 1) : -1;
	while (ft_is_one_of(format[i], ".0123456789)"))
		i++;
	i = ft_while_type(i, format, opt);
	return (ft_take_conv(format[i], i, opt, lol));
}
