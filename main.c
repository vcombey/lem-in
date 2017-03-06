/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:03:08 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/06 20:25:00 by vcombey          ###   ########.fr       */
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

void	get_nb(char *line, t_anthill *a, t_file f)
{
	if (!line || !(is_a_number(line)))
		ft_exit_err("bad number of ants", &f);
	a->nb_ant = ft_atoi(line);
}

void	read_file(t_file *f)
{
	char	*line;
	int		i;
	int		ret;

	i = 0;
	f->line = 1;
	f->column = 1;
	if (!(f->data = (char**)ft_memalloc(sizeof(char*) * (LINES + 1))))
		ft_exit_err("malloc error", f);
	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		f->data[i] = line;
		i++;
	}
	if (ret == -1)
		ft_exit_err("bad file", f);
}

int		main(void)
{
	t_file		f;
	t_anthill	a;
	t_ways		*ways;

	read_file(&f);
	a.room = NULL;
	a.start = -1;
	a.end = -1;
	//ft_putstrstr(f.data);
	get_nb(f.data[0], &a, f);
	f.line++;
	//printf("nb_ant : %d\n", a.nb_ant);
	get_rooms(&a, &f);
	init_mat(&a);
	//display_room(a.room);
	//printf("nb_room: %d\n", a.nb_room);
	while (f.data[f.line - 1] != NULL)
	{
		if (!(get_links(f.data[f.line - 1], &a)))
		{
			f.line--;
			break ;
		}
		f.line++;
	}
	//printf("start : %d\nend : %d\n", a.start, a.end);
	//display_mat(a);
	ways = find_best_ways(a);
	ft_putnstrstr(f.data, f.line);
	write(1, "\n", 1);
	display_multi_solus(ways, a);
	free_all_the_shit(ways, a, f);
	//display_room(solus);
}
