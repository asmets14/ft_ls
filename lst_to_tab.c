
#include "ft_ls.h"

void	list_del(t_lst *list)
{
	t_elem *tmp;
	t_elem *next;

	tmp = list->head;
	while (tmp)
	{
		next = tmp->next;
		// free(tmp->data);
		tmp->next = NULL;
		free(tmp);
		tmp = next;
	}
}


char **lst_to_tab(t_lst *list,  char **tab)
{
	int i;
	t_elem *elem;

	elem = list->head;
	i = 0;
	while(elem)
	{	
		tab[i] = elem->data;
		elem = elem->next;
		i++;
	}
	tab[i] = NULL;
	list_del(list);
	list = NULL;
	return (tab);
	
}