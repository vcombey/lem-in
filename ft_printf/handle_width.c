/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 21:07:21 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/05 23:42:40 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

char	*ft_handle_width_int(char *s, t_opt opt)
{
	if ((opt.width != -1) && (opt.minus == 0) && !(opt.zero))
		s = ft_width(s, opt.width, ' ');
	if ((opt.width != -1) && (opt.minus == 1))
		s = ft_width_right(s, opt.width, ' ');
	if ((opt.width != -1) && (opt.minus == 0) && opt.zero && (opt.prec == -1))
		s = ft_width(s, opt.width, '0');
	if ((opt.width != -1) && (opt.minus == 0) && opt.zero && (opt.prec != -1))
		s = ft_width(s, opt.width, ' ');
	return (s);
}

char	*ft_handle_width_char(char *s, t_opt opt)
{
	if ((opt.width != -1) && (opt.minus == 0) && !(opt.zero))
		s = ft_width(s, opt.width, ' ');
	if ((opt.width != -1) && (opt.minus == 1))
		s = ft_width_right(s, opt.width, ' ');
	if ((opt.width != -1) && (opt.minus == 0) && opt.zero)
		s = ft_width(s, opt.width, '0');
	return (s);
}

char	*ft_handle_width_backslash(char *s, t_opt opt)
{
	if ((opt.width != -1) && (opt.minus == 0) && !(opt.zero))
		s = ft_width_backslash(s, opt.width, ' ');
	if ((opt.width != -1) && (opt.minus == 1))
		s = ft_width_backslash_right(s, opt.width, ' ');
	if ((opt.width != -1) && (opt.minus == 0) && opt.zero)
		s = ft_width_backslash(s, opt.width, '0');
	return (s);
}
