
#include "ft_ls.h"

t_lslist *create_list(t_lslist *list, char *name)
{
	t_lslist *tmp;
	t_lslist *new;

	new = malloc(sizeof(t_lslist));
	tmp = list;
	if(new)
	{
		new->contenu.name = name;
		new->next = NULL;
		if(!list)
			return (new);
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (list);
}
