/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 21:15:37 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/05 23:36:23 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/include/libft.h"

void	ft_convert_str(t_opt opt, t_lol *lol, va_list ap)
{
	char	*s;

	if ((s = ft_strdup(va_arg(ap, char*))) == NULL)
		s = ft_strdup("(null)");
	if (opt.prec != -1 && (opt.prec < (int)ft_strlen(s)))
		s[opt.prec] = '\0';
	s = ft_handle_width_char(s, opt);
	ft_cpy_buf(s, lol, ft_strlen(s));
	free(s);
}

char	*ft_handle_precision_wstr(wchar_t *str, int prec)
{
	char	*s;
	int		len;
	char	*tmp;
	int		i;

	s = ft_strnew(1);
	s[0] = '\0';
	tmp = ft_wchartoa(str[0]);
	len = ft_strlen(tmp);
	if (prec - len >= 0)
	{
		free(s);
		s = tmp;
	}
	prec -= len;
	i = 0;
	while (str[0] && str[++i] && (prec > 0))
	{
		tmp = ft_wchartoa(str[i]);
		len = ft_strlen(tmp);
		if (prec - len >= 0)
			s = ft_strjoin_free(s, tmp, 3);
		prec -= len;
	}
	return (s);
}

void	ft_convert_wstr(t_opt opt, t_lol *lol, va_list ap)
{
	wchar_t		*str;
	char		*s;
	int			i;

	i = 1;
	if ((str = va_arg(ap, wchar_t*)) == NULL)
		s = ft_strdup("(null)");
	else if (opt.prec == -1)
	{
		s = ft_wchartoa(str[0]);
		while (str[0] && str[i])
		{
			s = ft_strjoin_free(s, ft_wchartoa(str[i]), 3);
			i++;
		}
	}
	else
		s = ft_handle_precision_wstr(str, opt.prec);
	s = ft_handle_width_char(s, opt);
	ft_cpy_buf(s, lol, ft_strlen(s));
	free(s);
}
