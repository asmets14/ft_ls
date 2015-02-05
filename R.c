#include "ft_ls.h"

t_lslist *R(char *str, t_lslist *fichier, t_lslist *dossier, t_lslist *tmp)
{
	struct dirent *readfile;
	struct stat info;
	DIR *rep;
	char *way;

	way = ft_xstrjoin(str, "/");
	rep = opendir(str);
	while ((readfile = readdir(rep)) != NULL)
	{
		way = ft_xstrjoin_free(way, readfile->d_name, 'g');
		lstat(way, &info);
	 	if (S_ISDIR(info.st_mode))
	 	{
	 		// printf("coucuo\n");	
	 		dossier = create_list(dossier, readfile->d_name);
	 	}
	 	else
	 		fichier = create_list(fichier, readfile->d_name);
	}
	printf("fichier \n");
	ft_print_list(fichier);
	printf("DOSSIER\n");
	ft_print_list(dossier);
	if (dossier && fichier)
	{
		tmp = fichier;
		while (tmp->next)
				tmp = tmp->next;
		tmp->next = dossier;
	}
	
	return (fichier);
}