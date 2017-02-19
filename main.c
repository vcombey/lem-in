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
#include <stdio.h>


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
		printf("n: %d, name: %s", r->n, r->name);
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
	}
	ft_putchar('\n');
	i++;
}

int		main(void)
{
	char		*line;
	t_anthill	a;

	line = NULL;
	a.room = NULL;
	get_nb(line, &a);
	get_rooms(&a);
	while (get_next_line(0, &line))
	{
		get_links(line, &a);
		free(line);
	}
	printf("nb_ant : %d\n nb_room : %d\n", a.nb_ant, a.nb_room);
	display_room(a.room);
	printf("start : %d\n end : %d\n", a.start, a.end);
	display_mat(a);
}
