
#include "ft_ls.h"

void		print(t_lst *list, t_type *option, char *str)
{
	int info;
	t_elem *tmp;
	t_lst *lst2;

	tmp = list->head;

	lst2 = lst_newlist();
	
	while (ft_strnequ(tmp->data, ".", 1))
			tmp = tmp->next;
	t_elem *next;
	while (tmp)
	{
		
		next = tmp->next;
		lst_put_end(lst2, lst_newelem(ft_strdup(tmp->data)));
		tmp = next;

	}
	// ft_print_list(lst2);
	if (option->rien == 1)
	{
		ft_print_list(lst2);
	}
	if (option->a == 1)
	{
		ft_print_list(list);
	}
	if	(option->r == 1)// faire l affichage
		//ft_print_list(list);

	if ((option->l == 1) || (option->n == 1))
	{	
		if (option->a == 1) 
			get_stat(list, str, option);
		get_stat(lst2, str, option);

	}
	if (option->R == 1)
		R(lst2, str, option);
}