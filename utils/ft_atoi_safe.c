/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbadia <rbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:45:00 by rbadia            #+#    #+#             */
/*   Updated: 2017/03/07 18:02:01 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_result(int *result)
{
	*result = -2147483648;
	return (1);
}

int			ft_atoi_safe(const char *str, int *result)
{
	int			is_neg;
	long long	res;

	res = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (set_result(result));
	is_neg = (*str == '-') ? 1 : 0;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while ('0' <= *str && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		if (res > 2147483647)
			return (0);
		str++;
	}
	res = is_neg ? -(res) : res;
	*result = (int)res;
	return (*str == '\0') ? 1 : 0;
}
