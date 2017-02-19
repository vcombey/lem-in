
#include "lem-in.h"
#include "libft/libft.h"

void	init_mat(t_anthill *a)
{
	int		n;
	int		i;

	i = 0;
	n = a->nb_room;
	if (!(a->mat = (int **)malloc(sizeof(int *) * (n + 1))))
		exit(1);
	a->mat[n] = NULL;
	while (i < n)
	{
		if (!(a->mat[i] = (int *)ft_memalloc(sizeof (int) * (n + 1))))
			exit(1);
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

void	get_links(char *line, t_anthill *a)
{
	int	i;

	i = ft_strchri(line, '-');
	line[i] = '\0';
	a->mat[name_to_number(line, a->room)][name_to_number(line + i + 1, a->room)] = 1;
}
