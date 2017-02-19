*t_list		ft_sort_ascii(t_list *lst, int reverse)
{
	t_list *tmp;

	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_ascii(lst->next);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_ascii(lst->next);
	}
	if (reverse)
	{
		a = NULL;
		b = lst;
		c = lst->next;
		while (lst && lst->next)
		{
			b->next = a;
			a = b;
			b = c;
			c = c->next;
		}
	}
	return (lst);
}
