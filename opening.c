#include "ft_ls.h"

static t_lslist *create_list(t_lslist *list, char *name, t_opt option)
{
	t_lslist *tmp;
	t_lslist *new;

	new = malloc(sizeof(t_lslist));
	tmp = list;
	if(new && option != OPT_R)
	{
		new->contenu.name = name;
		new->next = NULL;
		if(!list)
			return (new);
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if(new && option == OPT_R)
	{
		tmp->contenu.name = name;
		tmp->next = new;
	}
	return (list);
}

t_lslist  *opening(char *str, t_opt option)
{
	t_lslist *l_maj;
	t_lslist *l_min;
	t_lslist *tmp;
	struct dirent *readfile;
	DIR *rep;

	l_maj = NULL;
	l_min = NULL;
	readfile = NULL;
	rep = opendir(str);
	while ((readfile = readdir(rep)) != NULL)
	{
		if (readfile->d_name[0] >= 33 && readfile->d_name[0] <= 90)
			l_maj = create_list(l_maj, readfile->d_name, option);
		else if (readfile->d_name[0] >= 97 && readfile->d_name[0] <= 122)
			l_min = create_list(l_min, readfile->d_name, option);
	}
	if (l_maj && l_min) // List final = l_maj
	{
		tmp = l_maj;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = l_min;
	}
	return(l_maj);
}