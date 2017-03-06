/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_solus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:12:39 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/02 16:33:50 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "ft_printf.h"
#include <unistd.h>

void	display_move(t_room *solus)
{
	if (solus->next == NULL)
		return ;
	display_move(solus->next);
	if (solus->n == -1)
		return ;
	ft_printf("L%d-%s ", solus->n, solus->next->name);
	solus->next->n = solus->n;
	solus->n = -1;
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

void	display_multi_solus(t_ways *ways, t_anthill a)
{
	int		i;
	t_ways	*tmp;

	i = 1;
	while (i <= a.nb_ant)
	{
		tmp = ways;
		while (tmp && i <= a.nb_ant)
		{
			display_move(tmp->solus);
			if (tmp->nb_ant > 0)
			{
				tmp->solus->n = i;
				ft_printf("L%d-%s ", i, tmp->solus->name);
				tmp->nb_ant--;
			}
			i++;
			tmp = tmp->next;
		}
		write(1, "\n", 1);
	}
	i = 1;
	while (i < room_len(tmp->solus))
	{
		tmp = ways;
		while (tmp)
		{
			display_move(tmp->solus);
			i++;
			tmp = tmp->next;
		}
		write(1, "\n", 1);
	}
}
