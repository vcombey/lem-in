void	display_room(t_room *r)
{
	t_room *tmp;
	
	tmp = r;
	while (tmp)
	{
		printf("n: %d\nname: %s\n", tmp->n, tmp->name);
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

