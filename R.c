

#include "ft_ls.h"


int		twl_isdir(char *path)
{
	struct stat st;

	lstat(path, &st);
	return (S_ISDIR(st.st_mode));
}

void R(t_lslist *list, char *way, t_type *option)
{
	t_lslist *new_lst;
	char *fullpath;
	struct stat *info;

	ft_print_list_without_point(list);
	ft_putchar('\n');
	way = ft_xstrjoin(way, "/"); 
	while (list)
	{
		fullpath = ft_xstrjoin(way, list->contenu.name);	
			if (twl_isdir(fullpath))
			{
				new_lst = opening(fullpath);
				if (!(list->contenu.name[0] == '.'))
				{	
				 	ft_putstr(fullpath);
				 	ft_putendl(":");
					R(new_lst, fullpath, option);
				}
			}
	
		list = list->next;
	}
}