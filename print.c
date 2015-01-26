
#include "ft_ls.h"

void		print(t_lslist *list, t_opt option, char *str)
{
	int info;

	if (option == 0)
	{
		while (list->contenu.name[0] == '.')
			list = list->next;
		ft_print_list(list);
	}
	if (option == OPT_A)
		ft_print_list(list);
	if	(option == OPT_R)// Seg fault
		ft_print_list(list);

	if ((option == OPT_L) || (option == OPT_N))
	{	
		get_stat(list, str, option);

	}
}