# include "ft_ls.h"

void create_list(t_lst *list, char *name)
{
	t_elem *elem;

	elem = lst_newelem(ft_strdup(name));
	lst_put_end(list, elem);
}
