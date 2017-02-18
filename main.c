/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:03:08 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/14 22:06:55 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft/libft.h"

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

void	get_room(char *line, t_ant *a)
{
	char	**s;

	s = ft_strsplit(line, ' ');
	if ((ft_strstrlen(s) != 3) || (!(is_a_number(s[1]))) || (!(is_a_number(s[2]))))
		exit(1);

}

int		main()
{
	char	*line;
	t_ant	*a;

	a = (t_ant*)ft_memalloc(sizeof(t_ant));
	secure_get_next_line(&line);
	if (!(is_a_number(line)))
		exit(1);
	a->nb = ft_atoi(line);
	while (get_next_line(0, &line))
	{
		if (ft_strequ(line, "##start"))
			get_start(line, a);
		if (ft_strequ(line, "##end"))
			get_end(line, a);
		if (ft_strchr(line, '-'))
			break;
		if (line[0] == '#')
			;
		else
			get_room(line, a);
		free(line);
	}
	get_liason(line, a);
	while (get_next_line(0, &line) > 0)
	{
		get_liason(line, a);
		free(line);
	}
}
