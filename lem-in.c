/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:01:27 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/19 23:26:30 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdlib.h>
#include "libft/libft.h"

void	int_room_add(int n, t_room **r)
{
	t_room	*new;

	new = (t_room*)malloc(sizeof(t_room));
	new->n = n;
	new->next = *r;
	*r = new;
}

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


void	file_add(int n, t_room **r)
{
	t_room	*tmp;
	t_room	*new;

	tmp = *r;
	new = (t_room*)malloc(sizeof(t_room));
	new->n = n;
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

int		file_take(t_room **r)
{
	t_room		*tmp;

	tmp = *r;
	*r = (*r)->next;
	free(tmp);
	return (tmp->n);
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

void	ft_bfs(t_anthill a, t_bfs *bfs)
{
	int i;
	int r;

	file_add(a.start, &(bfs->to_see));
	file_add(a.start, &(bfs->already_seen));
	while (bfs->to_see)
	{
		r = file_take(&(bfs->to_see));
		i = 0;
		ft_putnbr(r);
		ft_putchar('\n');
		display_way(bfs->way, a.nb_room);
		while (i < a.nb_room)
		{
			if (a.mat[r][i] && (!(int_is_in_lst(i, bfs->already_seen))))
			{
				file_add(i, &(bfs->to_see));
				file_add(i, &(bfs->already_seen));
				bfs->way[i] = r;
			}
			i++;
		}
	}
}

t_room	*find_best_way(t_anthill a)
{
	t_bfs	bfs;
	int		i;
	int		k;
	t_room	*solus;

	i = 0;
	solus = NULL;
	bfs.already_seen = NULL;
	bfs.to_see = NULL;
	bfs.way = (int *)ft_memalloc(sizeof(int) * a.nb_room);
	while (i < a.nb_room)
	{
		bfs.way[i] = -1;
		i++;
	}
	ft_bfs(a, &bfs);
	k = a.end;
	while (k != a.start)
	{
		int_room_add(k, &solus);
		k = bfs.way[k];
		ft_putnbr(k);
		ft_putchar('\n');
	}
	return (solus);
}
