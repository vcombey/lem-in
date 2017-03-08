/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:26:12 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/08 14:48:14 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	file_add(int n, t_room **r)
{
	t_room	*tmp;
	t_room	*new;

	tmp = *r;
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		ft_exit_err("malloc error", NULL);
	new->n = n;
	new->name = NULL;
	new->next = NULL;
	if (!(tmp))
	{
		*r = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
