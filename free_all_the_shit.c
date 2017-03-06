/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_the_shit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:18:04 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/06 23:15:43 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft/libft.h"

void	free_bfs(t_bfs bfs)
{
	free_room(bfs.already_seen);
	free_room(bfs.to_see);
	free(bfs.way);
}

void	free_room(t_room *r)
{
	t_room	*tmp;

	while (r)
	{
		tmp = r;
		if (r->name != NULL)
			free(r->name);
		r = r->next;
		free(tmp);
	}
}

void	free_all_the_shit(t_ways *ways, t_anthill a, t_file f)
{
	t_ways *tmp;

	while (ways)
	{
		tmp = ways;
		free_room(ways->solus);
		ways = ways->next;
		free(tmp);
	}
	free_room(a.room);
	ft_tab_int_free(a.mat);
	ft_tab_free(f.data);
}
