/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamoure <mlamoure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:10:01 by mlamoure          #+#    #+#             */
/*   Updated: 2017/02/02 19:11:47 by mlamoure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		write(1, str + i, 1);
		i++;
	}
}
