
#include "ft_ls.h"

void	ft_print_list_without_point(t_lst *list)
{
	t_elem *elem;
	elem = list->head;

	while(elem)
	{
		if(ft_strnequ(elem->data, ".", 1)) 
		{
			elem = elem->next; 
			continue;
		}
		ft_putendl(elem->data);
		elem = elem->next;
	}
}