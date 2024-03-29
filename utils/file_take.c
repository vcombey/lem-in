/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_take.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:28:40 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/08 14:48:14 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

int		file_take(t_room **r)
{
	t_room		*tmp;

	tmp = *r;
	*r = (*r)->next;
	free(tmp);
	return (tmp->n);
}
