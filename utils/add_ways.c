/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:29:19 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/06 23:29:50 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdlib.h>

void	add_ways(t_ways **ways, t_room *solus, int nb_ant)
{
	t_ways	*new;

	new = (t_ways*)malloc(sizeof(t_ways));
	new->solus = solus;
	new->nb_ant = nb_ant;
	new->next = *ways;
	*ways = new;
}
