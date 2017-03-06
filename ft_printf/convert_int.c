/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 20:54:56 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/06 00:09:15 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

int		ft_is_zero(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == '0' || ((i == 1) && (s[1] == 'x' || s[1] == 'X'))))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_type_int(t_opt opt, va_list ap)
{
	if (ft_is_one_of(opt.conv, "di"))
		return (ft_type_di(opt, ap));
	else if (opt.conv == 'D')
		return (ft_itoa_base(va_arg(ap, long), 10));
	else if (opt.conv == 'u')
		return (ft_type_u(opt, ap));
	else if (opt.conv == 'U')
		return (ft_uitoa_base(va_arg(ap, unsigned long), 10));
	else if (opt.conv == 'o')
		return (ft_type_o(opt, ap));
	else if (opt.conv == 'O')
		return (ft_uitoa_base(va_arg(ap, unsigned long), 8));
	else
		return (ft_type_x(opt, ap));
}

char	*ft_int_prec(char *s, t_opt opt)
{
	int		is_neg;

	if (opt.prec > 0)
	{
		is_neg = (s[0] == '-') && ((int)ft_strlen(s) <= opt.prec);
		s[0] = is_neg ? '0' : s[0];
		s = ft_width(s, opt.prec, '0');
		s = is_neg ? ft_strjoin_free("-", s, 2) : s;
	}
	else if ((opt.prec == 0) && ft_is_zero(s) &&
			!(ft_is_one_of(opt.conv, "oO") && opt.diese))
		s[0] = '\0';
	return (s);
}

void	ft_convert_int(t_opt opt, t_lol *lol, va_list ap)
{
	char	*s;

	if (!(s = ft_type_int(opt, ap)))
		return ;
	if (ft_is_one_of(opt.conv, "oO") && opt.diese && (s[0] != '0'))
		s = ft_strjoin_free("0", s, 2);
	s = ft_int_prec(s, opt);
	if (ft_is_one_of(opt.conv, "di") && opt.plus && s[0] != '-')
		s = ft_strjoin_free("+", s, 2);
	else if (ft_is_one_of(opt.conv, "di") && opt.space && s[0] != '-')
		s = ft_strjoin_free(" ", s, 2);
	if (ft_is_one_of(opt.conv, "xX") && opt.diese && !(ft_is_zero(s)))
		s = ft_strjoin_free("0x", s, 2);
	if (opt.conv == 'X')
		ft_str_capitalize(s);
	s = ft_handle_width_int(s, opt);
	ft_cpy_buf(s, lol, ft_strlen(s));
	free(s);
}
