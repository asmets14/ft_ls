
#include "ft_ls.h"

void	ft_print_list(t_lslist *list)
{
	while(list)
	{
		ft_putendl(list->contenu.name);
		list = list->next;
	}
}