/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:22:46 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/06 23:22:48 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*dst;

	if (s == NULL)
		return (NULL);
	if (!(dst = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	if (dst == NULL)
		return (NULL);
	ft_strncpy(dst, s, n);
	dst[n] = 0;
	return (dst);
}
