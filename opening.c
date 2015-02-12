#include "ft_ls.h"


static int list_len(t_lslist *list)
{
	size_t len;

	if (list == NULL)
		return (0);
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

	t_lslist *list;
	struct dirent *readfile;
	DIR *rep;
	size_t len;
	char **tab;
	int i = 0;

	list = NULL;
	readfile = NULL;

		rep = opendir(str);
		while ((readfile = readdir(rep)) != NULL)
			list = create_list(list, readfile->d_name);
		len = list_len(list);
		tab = malloc(len);
		tab = lst_to_tab(list, tab);
		bubble_tri(tab, len);
		// printf("%zu\n", len);
		// while (tab[i])
		// {	
		// 	printf("tab[%d] = %s\n", i, tab[i]);
		// 	i++;
		// }
		list = tab_to_list(tab, len);

	return(list);
}