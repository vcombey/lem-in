/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_ways.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:30:39 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/06 23:40:21 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdlib.h>

void	supress_ant_in_the_first_solutions(t_ways *ways, int del)
{
	t_ways	*tmp;

	tmp = ways;
	while (tmp && del > 0)
	{
		if (tmp->nb_ant > 0)
		{
			tmp->nb_ant--;
			del--;
		}
		tmp = tmp->next;
	}
	if (del > 0)
		supress_ant_in_the_first_solutions(ways, del);
}

t_ways	*find_best_ways(t_anthill a)
{
	t_ways	*ways;
	t_room	*solus;
	int		b;
	int		ant_per_solus;

	ways = NULL;
	if (!(solus = find_best_way(a)))
		ft_exit_err("the ants say: \"there is no fucking way to the end\"",
				NULL);
	add_ways(&ways, solus, a.nb_ant);
	//display_solus(ways->solus, a);
	//display_mat(a);
	while ((solus = find_best_way(a)) != NULL)
	{
		b = ((room_len(ways->solus) - room_len(solus) + ways->nb_ant + 1) / 2);
		ant_per_solus = b / ways_len(ways);
		if ((b < 1) || (ant_per_solus < 1))
		{
			free_room(solus);
			return (ways);
		}
		supress_ant_in_the_first_solutions(ways, b);
		add_ways(&ways, solus, b);
		//display_ways(ways);
		//display_solus(ways->solus, a);
		//display_mat(a);
	}
	return (ways);
}
