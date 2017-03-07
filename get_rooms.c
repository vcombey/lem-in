/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:51:23 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/07 18:01:05 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft/libft.h"
#include <stdio.h>

void	room_add(char *name, t_anthill *a)
{
	t_room	*new;

	new = (t_room*)malloc(sizeof(t_room));
	if (!(new->name = ft_strdup(name)))
		ft_exit_err("malloc error", NULL);
	new->n = a->nb_room;
	new->next = a->room;
	a->room = new;
	a->nb_room++;
}

int		is_in_lst(char *name, t_room *r)
{
	t_room	*tmp;

	tmp = r;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	get_room(char *line, t_anthill *a, t_file *f)
{
	char	**s;
	int		result;

	s = ft_strsplit(line, ' ');
	if ((ft_strstrlen(s) != 3) || (!(ft_atoi_safe(s[1], &result))) || (!(ft_atoi_safe(s[2], &result))))
		ft_exit_err("bad definition of a room", f);
	if (s[0][0] == 'L')
		ft_exit_err("name can't start with a L", f);
	if (is_in_lst(s[0], a->room))
		ft_exit_err("same room is defined twice", f);
	room_add(s[0], a);
	ft_tab_free(s);
}

void	get_start(t_file *f, t_anthill *a)
{
	char	*line;

	f->line++;
	if ((line = f->data[f->line - 1]) == NULL)
		ft_exit_err("no start", f);
	if (a->start != -1)
		ft_exit_err("redefinition of start", f);
	a->start = a->nb_room;
	get_room(line, a, f);
}

void	get_end(t_file *f, t_anthill *a)
{
	char	*line;

	f->line++;
	if ((line = f->data[f->line - 1]) == NULL)
		ft_exit_err("no end", f);
	if (a->end != -1)
		ft_exit_err("redefinition of end", f);
	a->end = a->nb_room;
	get_room(line, a, f);
}

void	get_rooms(t_anthill *a, t_file *f)
{
	char	*line;

	while ((line = f->data[f->line - 1]) != NULL)
	{
		if (ft_strequ(line, "##start"))
			get_start(f, a);
		else if (ft_strequ(line, "##end"))
			get_end(f, a);
		else if (line[0] == '#')
		{
			;
		}
		else if (ft_strchr(line, '-') != NULL)
			break ;
		else
			get_room(line, a, f);
		f->line++;
	}
	if (a->start == -1)
		ft_exit_err("no start room", f);
	if (a->end == -1)
		ft_exit_err("no end room", f);
}
