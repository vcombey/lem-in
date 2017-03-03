/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:51:23 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/02 15:26:02 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft/libft.h"
#include <stdio.h>

void	room_add(char *name, t_anthill *a)
{
	t_room	*new;

	new = (t_room*)malloc(sizeof(t_room));
	new->name = name;
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

	s = ft_strsplit(line, ' ');
	if ((ft_strstrlen(s) != 3) || (!(is_a_number(s[1]))) || (!(is_a_number(s[2]))))
		ft_exit_err("bad definition of a room", f);
	if (is_in_lst(s[0], a->room))
		ft_exit_err("same room is defined twice", f);
	room_add(s[0], a);
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
			;
		else if (ft_strchr(line, '-') != NULL)
			break ;
		else
			get_room(line, a, f);
		f->line++;
	}
	init_mat(a, f);
	get_links(line, a, f);
	f->line++;
	if (a->start == -1)
		ft_exit_err("no start room", f);
	if (a->end == -1)
		ft_exit_err("no end room", f);
}
