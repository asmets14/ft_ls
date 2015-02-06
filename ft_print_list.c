
#include "ft_ls.h"

void	ft_print_list(t_lslist *list)
{
	while(list)
	{
		printf("print-> : %s\n", list->contenu.name);
		list = list->next;
	}
}