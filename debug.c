/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:39:32 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/08 15:14:15 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

void	display_ways(t_ways *ways)
{
	t_ways	*tmp;

	tmp = ways;
	while (tmp)
	{
		ft_printf("nb_ant%d\n", tmp->nb_ant);
		display_room(tmp->solus);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

void	display_way(int *way, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(way[i]);
		i++;
	}
	ft_putchar('\n');
}

void	display_room(t_room *r)
{
	t_room *tmp;

	tmp = r;
	while (tmp)
	{
		ft_printf("n: %d, name: %s\n", tmp->n, tmp->name);
		tmp = tmp->next;
	}
}

void	display_mat(t_anthill a)
{
	int i;
	int j;
	int n;

	i = 0;
	n = a.nb_room;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			ft_putnbr(a.mat[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
