#include "ft_ls.h"
#include <liba.h>


static int list_len(t_lslist *list)
{
	size_t len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

t_lslist  *opening(char *str)
{

	t_lslist 		*list;
	t_lst 			*new;
	char 			**tab;
	DIR 			*rep;
	struct dirent 	*readfile;
	size_t 			len;
	int i = 0;

	list = NULL;
	readfile = NULL;

		rep = opendir(str);
		while ((readfile = readdir(rep)) != NULL)
			list = create_list(list, readfile->d_name);
		len = list_len(list);
		tab = malloc(sizeof(char *) * len + 1);
		tab = lst_to_tab(list, tab);
		bubble_tri(tab, len);
		new = tab_to_lst(tab);
		printf("et ici ca commence ?\n");
		ft_print_list(list);

	return(list);
}