#include "ft_ls.h"

int dossier(char *mode)
{
	if(mode[0] == 'd')
		return(1);
	return (0);
}

void final_string(t_getallign *len, t_statinfo *tab, int i, t_opt option, int pts)
{
	char *new;
	ft_putstr(tab[i].mode);
	ft_putstr(" ");
	create_space(len->len_link, tab[i].link);
	create_space(len->len_uid, tab[i].st_uid);
	ft_putstr(" ");
	create_space(len->len_gid, tab[i].st_gid);
	ft_putstr(" ");
	create_space(len->len_taille, tab[i].taille);
	ft_putstr(" ");
	ft_putstr(tab[i].date);
		ft_putstr(" ");
	if(dossier(tab[i].mode) == 1)
	{
		ft_putstr(tab[i].name);
		ft_putendl("/");
	}
	else
		ft_putendl(tab[i].name);


}