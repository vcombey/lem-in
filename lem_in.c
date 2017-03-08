/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:42:05 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/08 18:04:56 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	solus_room_add(int n, t_room **r, t_anthill a)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		ft_exit_err("malloc error", NULL);
	new->n = -1;
	if (!(new->name = ft_strdup(number_to_name(n, a.room))))
		ft_exit_err("malloc error", NULL);
	new->next = *r;
	*r = new;
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

t_room	*reform_solus(t_bfs bfs, t_anthill a)
{
	int		k;
	t_room	*solus;

	solus = NULL;
	k = a.end;
	if (bfs.way[a.end] == a.start)
	{
		a.mat[a.end][a.start] = 0;
		a.mat[a.start][a.end] = 0;
	}
	if ((bfs.way[a.end]) == -1)
	{
		free_bfs(bfs);
		return (NULL);
	}
	while (k != a.start)
	{
		solus_room_add(k, &solus, a);
		k = bfs.way[k];
		if (k != a.start)
			delete_room(k, a);
	}
	free_bfs(bfs);
	return (solus);
}

t_room	*find_best_way(t_anthill a)
{
	t_bfs	bfs;
	int		i;

	i = 0;
	bfs.already_seen = NULL;
	bfs.to_see = NULL;
	bfs.way = (int *)ft_memalloc(sizeof(int) * a.nb_room);
	while (i < a.nb_room)
	{
		bfs.way[i] = -1;
		i++;
	}
	ft_bfs(a, &bfs);
	return (reform_solus(bfs, a));
}
