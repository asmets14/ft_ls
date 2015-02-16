
#include "ft_ls.h"

void	ft_print_list(t_lst *list)
{
	t_elem *elem;

	elem = list->head;
	while(elem)
	{
		ft_putendl(elem->data);
		elem = elem->next;
	}
}