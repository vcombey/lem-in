/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:14:15 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/05 21:20:19 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

void	ft_convert(t_opt opt, t_lol *lol, va_list ap)
{
	if (ft_is_one_of(opt.conv, "s") && !(opt.type == 'l'))
		ft_convert_str(opt, lol, ap);
	else if ((opt.conv == 'S') || (opt.conv == 's' && opt.type == 'l'))
		ft_convert_wstr(opt, lol, ap);
	else if (ft_is_one_of(opt.conv, "dDioOuUxX"))
		ft_convert_int(opt, lol, ap);
	else if (ft_is_one_of(opt.conv, "cC"))
		ft_convert_char(opt, lol, ap);
	else if (opt.conv == 'p')
		ft_convert_pointer(opt, lol, ap);
}
