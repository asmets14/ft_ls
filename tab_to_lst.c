
#include "ft_ls.h"

t_lslist *tab_to_list(char **tab, int size)
{
	t_lslist *list;
	
	list = (t_lslist *)malloc(sizeof(t_lslist));

	size -= 1;
	while (size > 0)
	{		
		printf("XXX\n");
		list = create_list(list, tab[size]);
		size--;

	}
	return(list);

}