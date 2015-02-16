
#include "ft_ls.h"

void	list_del(t_lslist *list)
{
	t_lslist *tmp;
	t_lslist *next;

	tmp = list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->contenu.name);
		free(tmp->next = NULL);
		free(tmp);
		tmp = next;
	}
}


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
	list_del(list);
	list = NULL;
	return (tab);
	
}