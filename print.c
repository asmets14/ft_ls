
#include "ft_ls.h"

void		print(t_lslist *list, t_opt option, char *str)
{
	int info;
	t_lslist *tmp;

	tmp = list;
	while (tmp->contenu.name[0] == '.')
	{
			tmp = tmp->next;
	}
	if (option == 0)
	{
		ft_print_list(tmp);
	}
	if (option == OPT_A)
		ft_print_list(list);
	if	(option == OPT_R)// Seg fault
		ft_print_list(list);

	if ((option == OPT_L) || (option == OPT_N))
	{	
		if (option == OPT_A) // fct pas 
			get_stat(list, str, option);
		get_stat(tmp, str, option);

	}
	if (option == OPT0R)
		R(tmp, str, option);
}