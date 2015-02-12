
#include "ft_ls.h"

char **lst_to_tab(t_lslist *list,  char **tab)
{
	int i;

	i = 0;
	while(list)
	{	
		tab[i] = list->contenu.name;
		list = list->next;
		i++;
	}
	tab[i] = NULL;
	free(list);
	return (&tab[0]);
	
}