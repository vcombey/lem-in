/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:30:27 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/27 16:31:11 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem-in.h"

void		free_lst(t_room *lst)
{
	t_room		*tmp;
	t_room		*tmp_next;

	tmp = lst;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp->name);
		free(tmp);
		tmp = tmp_next;
	}
}
