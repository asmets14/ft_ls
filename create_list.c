
#include "ft_ls.h"

t_lslist *create_new(char *name)
{
	t_lslist *new;

	new = (t_lslist *)ft_xmalloc(sizeof(t_lslist));
	new->contenu.name = ft_strdup(name);
	new->next = NULL;
	return (new);
}


t_lslist *create_list(t_lslist *list, char *name) /// del_list fin prog.
{
	t_lslist *tmp;
	t_lslist *new;

	printf("%s\n", name);
	new = create_new(name);
	tmp = list;
	if(!list)
	{
		// printf("(jambon)\n");
		return (new);
	}
	// printf("je passe pas par la bitch\n");
	while(tmp && tmp->next)
	{
		printf("next\n");
		tmp = tmp->next;
	}
	tmp->next = new;
	return (list);
}
