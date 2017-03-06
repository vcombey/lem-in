/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undefind_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 21:09:27 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/05 23:26:14 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

void	ft_convert_undefined_conv(char c, t_opt opt, t_lol *lol)
{
	char	*s;

	s = ft_strdup_char(c);
	s = ft_handle_width_char(s, opt);
	ft_cpy_buf(s, lol, ft_strlen(s));
	free(s);
}
