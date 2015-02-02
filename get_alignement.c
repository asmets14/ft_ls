

#include "ft_ls.h"

void	get_alignement(t_statinfo *tab, int compteur, t_opt option, int pts)
{
	t_getallign len;
	int i;

	i = 0;
	len.len_nom = 0;
	len.len_taille = 0;
	len.len_name = 0;
	len.len_uid = 0;
	len.len_gid = 0;
	len.len_link = 0;
	len.index = 0;


	while(len.index < compteur)
	{	
		len.len_nom = len.len_nom < ft_strlen(tab[len.index].name) ? ft_strlen(tab[len.index].name) : len.len_nom;
		len.len_total = len.len_total < ft_strlen(tab[len.index].blksize) ? ft_strlen(tab[len.index].blksize) : len.len_total;
		len.len_uid = len.len_uid < ft_strlen(tab[len.index].st_uid) ? ft_strlen(tab[len.index].st_uid) : len.len_uid;
		len.len_gid = len.len_gid < ft_strlen(tab[len.index].st_gid) ? ft_strlen(tab[len.index].st_gid) : len.len_gid;
		len.len_taille = len.len_taille < ft_strlen(tab[len.index].taille) ? ft_strlen(tab[len.index].taille) : len.len_taille;
		len.len_link = len.len_link < ft_strlen(tab[len.index].link) ? ft_strlen(tab[len.index].link) : len.len_link;
		len.index++;
	}
	if (option == (OPT_L + OPT_A)) // gere avec le nbr de dossier cacher
		i = 0;
	i = pts;


	while(i < compteur)
	{
		final_string(&len,tab, i, option, pts);
		i++;
	}
}