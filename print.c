
#include "ft_ls.h"

void	ft_print_list(t_lslist *list)
{
	while(list)
	{
		ft_putendl(list->contenu.name);
		list = list->next;
	}
}

void		print(t_lslist *list, t_opt option, char *str)
{
	int info;
	struct stat stats;


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