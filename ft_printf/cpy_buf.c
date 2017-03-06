/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_buf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 21:25:13 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/21 19:44:57 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

void	ft_realoc(t_lol *lol, size_t n)
{
	char	*tmp;

	tmp = lol->buf;
	if (!(lol->buf = ft_memalloc(sizeof(char) * n)))
		return ;
	free(tmp);
	ft_strcpy(lol->buf, tmp);
	lol->len += BUFFSIZE;
}

void	ft_cpy_buf(char *str, t_lol *lol, size_t n)
{
	size_t	k;
	char	*dest;

	if (str == NULL)
		return ;
	dest = lol->buf + lol->i;
	if ((lol->i + n) >= lol->len)
	{
		ft_realoc(lol, lol->len + BUFFSIZE);
		ft_cpy_buf(str, lol, n);
		return ;
	}
	k = 0;
	while (k < n)
	{
		dest[k] = str[k];
		k++;
	}
	lol->i += n;
}
