/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:55:06 by vcombey           #+#    #+#             */
/*   Updated: 2016/11/15 02:43:51 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(&(s[i]));
		i++;
	}
}
