/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 15:34:06 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/06 14:08:06 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# define BUFFSIZE 300

typedef struct	s_lol
{
	char		*buf;
	size_t		cur;
	size_t		i;
	size_t		len;
}				t_lol;

typedef struct	s_opt
{
	int			minus;
	int			plus;
	int			diese;
	int			zero;
	int			space;
	int			width;
	int			prec;
	char		type;
	char		conv;
}				t_opt;

int				ft_printf(const char *restrict format, ...);
void			ft_convert(t_opt opt, t_lol *lol, va_list ap);
int				take_opt(char *format, t_opt *opt, t_lol *lol);
void			ft_convert_undefined_conv(char c, t_opt opt, t_lol *lol);
int				ft_parse(char *format, t_lol *lol, va_list ap);
void			ft_cpy_buf(char *str, t_lol *lol, size_t n);
int				calc_nb_bits(wchar_t wc);
char			*ft_wchartoa(wchar_t wc);
char			*ft_width(char *s, size_t width, char c);
char			*ft_width_right(char *s, size_t width, char c);
char			*ft_width_backslash(char *s, int width, char c);
char			*ft_width_backslash_right(char *s, int width, char c);
int				ft_is_one_of(char c, char *that);
char			*ft_handle_width_int(char *s, t_opt opt);
char			*ft_handle_width_char(char *s, t_opt opt);
char			*ft_strdup_char(char c);
void			ft_convert_int(t_opt opt, t_lol *lol, va_list ap);
void			ft_convert_str(t_opt opt, t_lol *lol, va_list ap);
void			ft_convert_wstr(t_opt opt, t_lol *lol, va_list ap);
void			ft_convert_char(t_opt opt, t_lol *lol, va_list ap);
void			ft_convert_pointer(t_opt opt, t_lol *lol, va_list ap);
char			*ft_handle_width_int(char *s, t_opt opt);
char			*ft_handle_width_char(char *s, t_opt opt);
char			*ft_handle_width_backslash(char *s, t_opt opt);
char			*ft_type_di(t_opt opt, va_list ap);
char			*ft_type_di(t_opt opt, va_list ap);
char			*ft_type_u(t_opt opt, va_list ap);
char			*ft_type_o(t_opt opt, va_list ap);
char			*ft_type_x(t_opt opt, va_list ap);

#endif
