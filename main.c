/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:40:42 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/08 16:52:54 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
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
	int		result;

	result = 0;
	if (!line || !(ft_atoi_safe(line, &result)))
		ft_exit_err("bad number of ants", &f);
	if ((a->nb_ant = result) == 0)
		ft_exit_err("there is no ants you newbie", &f);
}

void	realoc_file(t_file *f, int i)
{
	char	**new;

	f->data_len = f->data_len + LINES;
	if (!(new = ft_memalloc(sizeof(char *) * (f->data_len + LINES))))
		ft_exit_err("malloc error", NULL);
	ft_memcpy(new, f->data, i * sizeof(char *));
	free(f->data);
	f->data = new;
}

void	read_file(t_file *f)
{
	char	*line;
	int		i;
	int		ret;

	i = 0;
	f->line = 1;
	f->data_len = LINES + 1;
	if (!(f->data = (char**)ft_memalloc(sizeof(char*) * (LINES + 1))))
		ft_exit_err("malloc error", f);
	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (i >= f->data_len)
			realoc_file(f, i);
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
	get_nb(f.data[0], &a, f);
	f.line++;
	get_rooms(&a, &f);
	init_mat(&a);
	while (f.data[f.line - 1] != NULL)
	{
		if (!(get_links(f.data[f.line - 1], &a)))
		{
			f.line--;
			break ;
		}
		f.line++;
	}
	ways = find_best_ways(a);
	ft_putnstrstr(f.data, f.line);
	write(1, "\n", 1);
	display_multi_solus(ways, a);
	free_all_the_shit(ways, a, f);
}
