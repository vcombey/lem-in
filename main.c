/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:03:08 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/18 18:31:21 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft/libft.h"

void	init_mat(t_anthill *a)
{
	if (!(a->mat = (int **)malloc(sizeof(int *) * (a->nb_room + 1))))
		exit(1);

}

int		is_a_number(char *line)
{
	while (*line)
	{
		if ((*line > 57) || (*line < 48))
			return (0);
	}
	return (1);
}

void	secure_get_next_line(char **line)
{
	if (get_next_line(0, line) == -1)
		exit(1);
}

void	get_liason(char *line, t_anthill *a)
{
}

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

void	get_room(char *line, t_anthill *a)
{
	char	**s;

	s = ft_strsplit(line, ' ');
	if ((ft_strstrlen(s) != 3) || (!(is_a_number(s[1]))) || (!(is_a_number(s[2]))))
		exit(1);
	room_add(s[0], a);
}

void	get_start(char *line, t_anthill *a)
{
	get_next_line(0, &line);
	a->start = a->nb_room;
	get_room(line, a);
}

void	get_end(char *line, t_anthill *a)
{
	get_next_line(0, &line);
	a->end = a->nb_room;
	get_room(line, a);
}

void	get_nb(char *line, t_anthill *a)
{
	get_next_line(0, &line);
	if (!(is_a_number(line)))
		exit(1);
	a->nb_ant = ft_atoi(line);
}

void	get_rooms(t_anthill *a)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strequ(line, "##start"))
			get_start(line, a);
		if (ft_strequ(line, "##end"))
			get_end(line, a);
		if (ft_strchr(line, '-'))
			break ;
		if (line[0] == '#')
			;
		else
			get_room(line, a);
		free(line);
	}
	init_mat(a);
	get_liason(line, a);
	free(line);
}

int		main(void)
{
	char		*line;
	t_anthill	*a;

	a = (t_anthill*)ft_memalloc(sizeof(t_anthill));
	get_nb(line, a);
	get_rooms(a);
	while (get_next_line(0, &line))
	{
		get_liason(line, a);
		free(line);
	}
}











