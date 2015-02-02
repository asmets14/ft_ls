
#include "ft_ls.h"

void		print(t_lslist *list, t_opt option, char *str)
{
	int info;
	int pts;
	t_lslist *tmp;

	pts = 0;
	tmp = list;
	while (tmp->contenu.name[0] == '.')
	{
			pts++;
			tmp = tmp->next;
	}
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

	if ((option == OPT_L) || (option == OPT_N) || (option == OPT_L + OPT_A))
	{	
		get_stat(list, str, option, pts);

	}
}