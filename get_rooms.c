
#include "lem-in.h"
#include "libft/libft.h"

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

void	get_room(char *line, t_anthill *a)
{
	char	**s;

	s = ft_strsplit(line, ' ');
	if ((ft_strstrlen(s) != 3) || (!(is_a_number(s[1]))) || (!(is_a_number(s[2]))))
		exit(1);
	if (is_in_lst(s[0], a->room))
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

void	get_rooms(t_anthill *a)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strequ(line, "##start"))
			get_start(line, a);
		else if (ft_strequ(line, "##end"))
			get_end(line, a);
		else if (ft_strchr(line, '-'))
			break ;
		else if (line[0] == '#')
			;
		else
			get_room(line, a);
		free(line);
	}
	init_mat(a);
	get_links(line, a);
	free(line);
}
