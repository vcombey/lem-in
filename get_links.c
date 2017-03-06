/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:51:38 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/06 19:13:48 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft/libft.h"

void	init_mat(t_anthill *a)
{
	int		n;
	int		i;

	i = 0;
	n = a->nb_room;
	if (!(a->mat = (int **)malloc(sizeof(int *) * (n + 1))))
		ft_exit_err("malloc error", NULL);
	a->mat[n] = NULL;
	while (i < n)
	{
		if (!(a->mat[i] = (int *)ft_memalloc(sizeof (int) * (n + 1))))
			ft_exit_err("malloc error", NULL);
		i++;
	}
}

int		name_to_number(char *name, t_room *r)
{
	t_room	*tmp;

	tmp = r;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (tmp->n);
		tmp = tmp->next;
	}
	return (-1);
}

char	*number_to_name(int n, t_room *r)
{
	t_room	*tmp;

	tmp = r;
	while (tmp)
	{
		if (n == tmp->n)
			return (tmp->name);
		tmp = tmp->next;
	}
	return ("lol");
}

int		get_links(char *line, t_anthill *a)
{
	int	i;
	int	k;
	int	l;

	if (line[0] == '#' && line[1] == '#')
		return (0);
	else if (line[0] == '#')
		return (1);
	if ((i = ft_strchri(line, '-')) == -1)
		return (0);
	line[i] = '\0';
	if ((k = name_to_number(line, a->room)) == -1)
		return (0);
	if ((l = name_to_number(line + i + 1, a->room)) == -1)
		return (0);
	line[i] = '-';
	a->mat[k][l] = 1;
	a->mat[l][k] = 1;
	return (1);
}
