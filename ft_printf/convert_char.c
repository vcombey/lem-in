/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 21:17:44 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/06 14:04:14 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

void	ft_convert_char(t_opt opt, t_lol *lol, va_list ap)
{
	wchar_t		c;
	char		*s;

	c = va_arg(ap, wchar_t);
	s = (opt.conv == 'C') || ((opt.conv == 'c') && (opt.type == 'l')) ?
		ft_wchartoa(c) : ft_strdup_char((char)c);
	if (s[0] == '\0')
	{
		s = ft_handle_width_backslash(s, opt);
		if (opt.width != -1)
			ft_cpy_buf(s, lol, opt.width);
		else
			ft_cpy_buf(s, lol, 1);
	}
	else
	{
		s = ft_handle_width_char(s, opt);
		ft_cpy_buf(s, lol, ft_strlen(s));
	}
	free(s);
}
