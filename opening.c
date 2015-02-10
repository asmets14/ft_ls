#include "ft_ls.h"

t_lslist  *opening(char *str)
{
	t_lslist *l_maj;
	t_lslist *l_min;
	t_lslist *tmp;
	struct dirent *readfile;
	DIR *rep;

	l_maj = NULL;
	l_min = NULL;
	readfile = NULL;

		rep = opendir(str);
		while ((readfile = readdir(rep)) != NULL)
		{
			if (readfile->d_name[0] >= 33 && readfile->d_name[0] <= 90)
				l_maj = create_list(l_maj, readfile->d_name);
			else if (readfile->d_name[0] >= 97 && readfile->d_name[0] <= 122)
				l_min = create_list(l_min, readfile->d_name);
		}
		// printf("\033[32m MAJ =\n");
		// printf("XXXX\033[0m\n");
		if (l_maj && l_min) // List final = l_maj
		{
			tmp = l_maj;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = l_min;
		}
	return(l_maj);
}