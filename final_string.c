#include "ft_ls.h"

int dossier(char *mode)
{
	if(mode[0] == 'd')
		return(1);
	return (0);
}

void final_string(t_getallign *len, t_statinfo *tab, int i)
{
	char *new;

	ft_putstr(tab[i].mode);
	ft_putstr(" ");
	create_space((len->len_link - 1), tab[i].link, 't');
	ft_putstr(" ");
	create_space(len->len_uid, tab[i].st_uid, 'a');
	ft_putstr(" ");
	create_space(len->len_gid, tab[i].st_gid, 'a');
	ft_putstr(" ");
	if (tab[i].mode[0] == 'c' || tab[i].mode[0] == 'b')
	{

		create_space(len->len_major, tab[i].d_major, 't');
		ft_putstr(", ");
		create_space(len->len_minor, tab[i].d_minor,  't');

	 }
	else
		if (len->len_major > 0 && len->len_minor > 0)
			create_space((len->len_major + len->len_minor + 3), tab[i].taille, 't');
		else
			create_space(len->len_taille, tab[i].taille, 't');
	ft_putstr(" ");
	ft_putstr(tab[i].date);
	ft_putstr(" ");
	ft_putendl(tab[i].name);
}