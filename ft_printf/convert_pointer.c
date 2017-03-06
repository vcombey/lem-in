/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 21:19:32 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/05 23:34:02 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

void	ft_convert_pointer(t_opt opt, t_lol *lol, va_list ap)
{
	char			*s;
	unsigned long	n;

	n = va_arg(ap, unsigned long);
	s = ft_uitoa_base(n, 16);
	if (opt.prec > 0 && (opt.prec > (int)ft_strlen(s)))
		s = ft_width(s, opt.prec, '0');
	if ((opt.prec == 0) && (s[0] == '0'))
		s[0] = '\0';
	s = ft_strjoin_free("0x", s, 2);
	s = ft_handle_width_char(s, opt);
	ft_cpy_buf(s, lol, ft_strlen(s));
	free(s);
}
