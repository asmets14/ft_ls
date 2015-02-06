

#include "ft_ls.h"

#include <sys/stat.h>

int		twl_isdir(char *path)
{
	struct stat st;

	lstat(path, &st);
	// printf("[{%s}]\n", path);
	return (S_ISDIR(st.st_mode));
}

void R(t_lslist *list, char *way, t_opt option)
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
		if (ft_strcmp(list->contenu.name, ".") && ft_strcmp(list->contenu.name, ".."))
		{		
			if (twl_isdir(fullpath))
			{
				new_lst = opening(fullpath, option);
				if (!(list->contenu.name[0] == '.'))
				{	
					ft_putstr("\033[32m");
				 	ft_putstr(fullpath);
				 	ft_putendl(":");
				 		ft_putstr("\033[0m");
					R(new_lst, fullpath, option);
				}

			}
		}
		list = list->next;
	}
}