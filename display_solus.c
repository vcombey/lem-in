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

	i = 1;
	while (i <= a.nb_ant)
	{
		ft_printf("L%d-%s ", i, solus->name);
		display_move(solus);
		solus->n = i;
		write(1, "\n", 1);
		i++;
	}
}
