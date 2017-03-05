/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:01:27 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/02 16:37:48 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdlib.h>
#include "libft/libft.h"

void	solus_room_add(int n, t_room **r, t_anthill a)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		ft_exit_err("malloc error", NULL);
	new->n = -1;
	new->name = number_to_name(n, a.room);
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
		//ft_putnbr(r);
		//ft_putchar('\n');
		//display_way(bfs->way, a.nb_room);
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

void	delete_room(int k, t_anthill a)
{
	int		i;

	i = 0;
	while (i < a.nb_room)
	{
		a.mat[k][i] = 0;
		i++;
	}
	i = 0;
	while (i < a.nb_room)
	{
		a.mat[i][k] = 0;
		i++;
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
	if (bfs.way[a.end] == a.start)
	{
		a.mat[a.end][a.start] = 0;
		a.mat[a.start][a.end] = 0;
	}
	while (k != a.start)
	{
		solus_room_add(k, &solus, a);
		if ((k = bfs.way[k]) == -1)
			return (NULL);
		if (k != a.start)
			delete_room(k, a);
		//ft_putnbr(k);
		//ft_putchar('\n');
	}
	return (solus);
}

void	add_ways(t_ways **ways, t_room *solus, int nb_ant)
{
	t_ways	*new;

	new = (t_ways*)malloc(sizeof(t_ways));
	new->solus = solus;
	new->nb_ant = nb_ant;
	new->next = *ways;
	*ways = new;
}

void	supress_ant_in_the_first_solutions(t_ways *ways, int del)
{
	t_ways	*tmp;

	tmp = ways;
	while (tmp && del > 0)
	{
		tmp->nb_ant--;
		del--;
		tmp = tmp->next;
	}
	if (del > 0)
		supress_ant_in_the_first_solutions(ways, del);
}

int		ways_len(t_ways *ways)
{
	return ((ways == NULL) ? 0 : 1 + ways_len(ways->next));
}

t_ways	*find_best_ways(t_anthill a)
{
	t_ways	*ways;
	t_room	*solus;
	int		b;
	int		ant_per_solus;

	ways = NULL;
	if (!(solus = find_best_way(a)))
		ft_exit_err("the ants say: \"there is no fucking way to the end\"", NULL);
	add_ways(&ways, solus, a.nb_ant);
	display_solus(ways->solus, a);
	display_mat(a);
	while ((solus = find_best_way(a)) != NULL)
	{
		b = ((room_len(ways->solus) - room_len(solus) + a.nb_ant) / 2);
		ant_per_solus = b / ways_len(ways);
		if ((b < 1) || (ant_per_solus < 1))
			return (ways);
		add_ways(&ways, solus, b);
		supress_ant_in_the_first_solutions(ways, b);
		display_solus(ways->solus, a);
		display_mat(a);
	}
	return (ways);
}
