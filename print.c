
#include "ft_ls.h"

void		print(t_lslist *list, t_type *option, char *str)
{
	int info;
	t_lslist *tmp;

	tmp = list;
	while (tmp->contenu.name[0] == '.')
	{
			tmp = tmp->next;
	}
	
	if (option->rien == 1)
	{
		ft_print_list(tmp);
	}
	if (option->a == 1)
		ft_print_list(list);
	if	(option->r == 1)// Seg fault
		ft_print_list(list);

	if ((option->l == 1) || (option->n == 1))
	{	
		if (option->a == 1) // fct pas 
			get_stat(list, str, option);
		get_stat(tmp, str, option);

	}
	if (option->R == 1)
		R(tmp, str, option);
}