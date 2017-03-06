/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_is_in_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:25:01 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/06 23:25:27 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdlib.h>

int		int_is_in_lst(int n, t_room *r)
{
	t_room	*tmp;

	tmp = r;
	while (tmp)
	{
		if (n == tmp->n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
