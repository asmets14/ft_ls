

#include "ft_ls.h"


int		twl_isdir(char *path)
{
	struct stat st;

	lstat(path, &st);
	return (S_ISDIR(st.st_mode));
}

void R(t_lst *list, char *way, t_type *option)
{
	t_lst *new_lst;
	t_elem *elem;
	char *fullpath;
	struct stat *info;

	elem = list->head;
	ft_print_list_without_point(list);
	ft_putchar('\n');
	way = ft_xstrjoin(way, "/"); 
	while (elem)
	{
		fullpath = ft_xstrjoin(way, elem->data);	
			if (twl_isdir(fullpath))
			{
				new_lst = opening(fullpath);
				if (!ft_strnequ(elem->data, ".", 1));
				{	
				 	ft_putstr(fullpath);
				 	ft_putendl(":");
					R(new_lst, fullpath, option);
				}
			}
	
		elem = elem->next;
	}
}