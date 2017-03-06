/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 21:23:44 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/05 23:49:26 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"
#include <wchar.h>
#include <locale.h>
#include <unistd.h>

char	*ft_case1(wchar_t wc)
{
	char *a;

	if (!(a = ft_strnew(1)))
		return (NULL);
	a[0] = (char)wc;
	return (a);
}

char	*ft_case2(wchar_t wc)
{
	char *a;

	if (!(a = ft_strnew(2)))
		return (NULL);
	a[1] = (char)((wc & 0x3F) | 0x80);
	wc >>= 6;
	a[0] = (char)((wc & 0x1F) | 0xC0);
	return (a);
}

char	*ft_case3(wchar_t wc)
{
	char *a;

	if (!(a = ft_strnew(3)))
		return (NULL);
	a[2] = (char)((wc & 0x3F) | 0x80);
	wc >>= 6;
	a[1] = (char)((wc & 0x3F) | 0x80);
	wc >>= 6;
	a[0] = (char)((wc & 0xF) | 0xE0);
	return (a);
}

char	*ft_case4(wchar_t wc)
{
	char *a;

	if (!(a = ft_strnew(4)))
		return (NULL);
	a[3] = (char)((wc & 0x3F) | 0x80);
	wc >>= 6;
	a[2] = (char)((wc & 0x3F) | 0x80);
	wc >>= 6;
	a[1] = (char)((wc & 0x3F) | 0x80);
	wc >>= 6;
	a[0] = (char)((wc & 0x7) | 0xF0);
	return (a);
}

char	*ft_wchartoa(wchar_t wc)
{
	int	nb;

	nb = calc_nb_bits(wc);
	if (nb <= 7)
		return (ft_case1(wc));
	else if (nb <= 11)
		return (ft_case2(wc));
	else if (nb <= 16)
		return (ft_case3(wc));
	else if (nb <= 21)
		return (ft_case4(wc));
	else
		return (NULL);
}
