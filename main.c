/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:03:08 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/19 19:24:14 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft/libft.h"
#include <stdio.h>


int		is_a_number(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] > 57) || (line[i] < 48))
			return (0);
		i++;
	}
	return (1);
}

void	secure_get_next_line(char **line)
{
	if (get_next_line(0, line) == -1)
		exit(1);
}

void	get_nb(char *line, t_anthill *a)
{
	get_next_line(0, &line);
	if (!(is_a_number(line)))
		exit(1);
	a->nb_ant = ft_atoi(line);
}

void	display_room(t_room *r)
{
	t_room *tmp;
	
	tmp = r;
	while (tmp)
	{
		printf("n: %d, name: %s\n", tmp->n, tmp->name);
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
}

int		main(void)
{
	char		*line;
	t_anthill	a;

	line = NULL;
	a.room = NULL;
	get_nb(line, &a);
	printf("nb_ant : %d\n", a.nb_ant);
	get_rooms(&a);
	display_room(a.room);
	printf("nb_room: %d\n", a.nb_room);
	while (get_next_line(0, &line) > 0)
	{
		get_links(line, &a);
		free(line);
	}
	printf("start : %d\nend : %d\n", a.start, a.end);
	display_mat(a);
}
