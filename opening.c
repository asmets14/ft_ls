#include "ft_ls.h"



static int list_len(t_lst *list)
{
	size_t len;
	t_elem *elem;

	elem = list->head;
	len = 0;
	while (elem)
	{
		len++;
		elem = elem->next;
	}
	return (len);
}

t_lst  *opening(char *str)
{

	t_lst 		*list;
	char 			**tab;
	DIR 			*rep;
	struct dirent 	*readfile;
	size_t 			len;
	int i = 0;

	list = lst_newlist();
	readfile = NULL;

		rep = opendir(str);
		while ((readfile = readdir(rep)) != NULL)
			create_list(list, readfile->d_name);


		len = list_len(list);
		tab = malloc(sizeof(char *) * len + 1);
		tab = lst_to_tab(list, tab);
		bubble_tri(tab, len);
		list = tab_to_lst(tab);


	return(list);
}