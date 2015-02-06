
#include "ft_ls.h"

void	ft_print_list_without_point(t_lslist *list)
{
	while(list)
	{
		if(list->contenu.name[0] == '.') 
		{
			list = list->next; 
			continue;
		}
		ft_putendl(list->contenu.name);
		list = list->next;
	}
}