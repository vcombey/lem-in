/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 21:31:30 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/05 23:45:38 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

char	*ft_type_di(t_opt opt, va_list ap)
{
	if (opt.type == 'a')
		return (ft_wchartoa(va_arg(ap, long long)));
	else if (opt.type == 'h')
		return (ft_itoa_base((short)va_arg(ap, int), 10));
	else if (opt.type == 'l')
		return (ft_itoa_base(va_arg(ap, long), 10));
	else if (opt.type == 'b')
		return (ft_itoa_base((char)va_arg(ap, int), 10));
	else if (opt.type == 'j')
		return (ft_itoa_base(va_arg(ap, intmax_t), 10));
	else if (opt.type == 'z')
		return (ft_itoa_base(va_arg(ap, size_t), 10));
	else
		return (ft_itoa_base(va_arg(ap, int), 10));
}

char	*ft_type_u(t_opt opt, va_list ap)
{
	if (opt.type == 'a')
		return (ft_wchartoa(va_arg(ap, long long)));
	else if (opt.type == 'h')
		return (ft_uitoa_base((unsigned short)va_arg(ap, int), 10));
	else if (opt.type == 'l')
		return (ft_uitoa_base(va_arg(ap, unsigned long), 10));
	else if (opt.type == 'b')
		return (ft_uitoa_base((unsigned char)va_arg(ap, unsigned long long),
					10));
	else if (opt.type == 'j')
		return (ft_uitoa_base(va_arg(ap, uintmax_t), 10));
	else if (opt.type == 'z')
		return (ft_uitoa_base(va_arg(ap, size_t), 10));
	else
		return (ft_uitoa_base(va_arg(ap, unsigned int), 10));
}

char	*ft_type_o(t_opt opt, va_list ap)
{
	if (opt.type == 'a')
		return (ft_wchartoa(va_arg(ap, wchar_t)));
	else if (opt.type == 'h')
		return (ft_uitoa_base((unsigned short)va_arg(ap, int), 8));
	else if (opt.type == 'l')
		return (ft_uitoa_base(va_arg(ap, unsigned long), 8));
	else if (opt.type == 'b')
		return (ft_uitoa_base((unsigned char)va_arg(ap, unsigned long long),
					8));
	else if (opt.type == 'j')
		return (ft_uitoa_base(va_arg(ap, uintmax_t), 8));
	else if (opt.type == 'z')
		return (ft_uitoa_base(va_arg(ap, size_t), 8));
	else
		return (ft_uitoa_base(va_arg(ap, unsigned int), 8));
}

char	*ft_type_x(t_opt opt, va_list ap)
{
	if (opt.type == 'a')
		return (ft_wchartoa(va_arg(ap, wchar_t)));
	else if (opt.type == 'h')
		return (ft_uitoa_base((unsigned short)va_arg(ap, int), 16));
	else if (opt.type == 'l')
		return (ft_uitoa_base(va_arg(ap, unsigned long), 16));
	else if (opt.type == 'b')
		return (ft_uitoa_base((unsigned char)va_arg(ap, unsigned long long),
					16));
	else if (opt.type == 'j')
		return (ft_uitoa_base(va_arg(ap, uintmax_t), 16));
	else if (opt.type == 'z')
		return (ft_uitoa_base(va_arg(ap, size_t), 16));
	else
		return (ft_uitoa_base(va_arg(ap, unsigned int), 16));
}
