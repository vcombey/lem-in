/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_solus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:12:39 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/08 16:46:19 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include <unistd.h>

int		display_move(t_room *solus)
{
	int		has_moved;

	if (solus->next == NULL)
		return (0);
	has_moved = (solus->n != -1);
	has_moved |= display_move(solus->next);
	if (solus->n == -1)
		return (has_moved);
	ft_printf("L%d-%s ", solus->n, solus->next->name);
	solus->next->n = solus->n;
	solus->n = -1;
	return (has_moved);
}

void	display_solus(t_room *solus, t_anthill a)
{
	int		i;
	int		n;

	i = 1;
	n = room_len(solus);
	while (i <= a.nb_ant)
	{
		display_move(solus);
		ft_printf("L%d-%s ", i, solus->name);
		solus->n = i;
		write(1, "\n", 1);
		i++;
	}
	i = 1;
	while (i < room_len(solus))
	{
		display_move(solus);
		write(1, "\n", 1);
		i++;
	}
}

void	display_multi_solus_end(t_ways *ways)
{
	int		i;
	int		has_moved;
	t_ways	*tmp;

	i = 1;
	while (i < room_len(ways->solus))
	{
		has_moved = 0;
		tmp = ways;
		while (tmp)
		{
			has_moved |= display_move(tmp->solus);
			tmp = tmp->next;
		}
		if (has_moved)
			write(1, "\n", 1);
		i++;
	}
}

void	display_multi_solus(t_ways *ways, t_anthill a)
{
	int		i;
	int		n;
	t_ways	*tmp;

	n = room_len(ways->solus);
	i = 1;
	while (i <= a.nb_ant)
	{
		tmp = ways;
		while (tmp && (i <= a.nb_ant))
		{
			display_move(tmp->solus);
			if (tmp->nb_ant > 0)
			{
				tmp->solus->n = i;
				ft_printf("L%d-%s ", i, tmp->solus->name);
				tmp->nb_ant--;
				i++;
			}
			tmp = tmp->next;
		}
		write(1, "\n", 1);
	}
	display_multi_solus_end(ways);
}
