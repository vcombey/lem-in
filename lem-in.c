/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:01:27 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/19 21:17:27 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdlib.h>
#include "libft/libft.h"

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
	if (!(tmp))
		*r = new;
	new = (t_room*)malloc(sizeof(t_room));
	new->n = n;
	while (tmp)
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
		while (a.mat[r][i])
		{
			if (a.mat[r][i] && (!(int_is_in_lst(i, bfs->already_seen))))
				file_add(i, &(bfs->to_see));
				file_add(i, &(bfs->already_seen));
		}
	}
}

t_room	*find_best_way(t_anthill a)
{
	t_bfs	bfs;

	bfs.already_seen = NULL;
	bfs.to_see = NULL;
	bfs.way = (int *)malloc(sizeof(int) * a.nb_room);
	ft_bfs(a, &bfs);
}
