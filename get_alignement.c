

#include "ft_ls.h"

void	get_alignement(t_statinfo *tab, int compteur)
{
	int len_nom;
	int len_taille;
	int len_total;
	int len_name;
	int len_uid;
	int len_gid;
	int	len_link;
	int index;

	len_nom = 0;
	len_taille = 0;
	len_mode = 0;
	len_name = 0;
	len_uid = 0;
	len_gid = 0;
	len_link = 0;
	index = 0;


	while(index < compteur)
	{	
		len_nom = len_nom < ft_strlen(tab[index].name) ? ft_strlen(tab[index].name) : len_nom;
		len_total = len_total < ft_strlen(tab[index].blksize) ? ft_strlen(tab[index].blksize) : len_total;
		len_uid = len_uid < ft_strlen(tab[index].st_uid) ? ft_strlen(tab[index].st_uid) : len_uid;
		len_gid = len_gid < ft_strlen(tab[index].st_gid) ? ft_strlen(tab[index].st_gid) : len_gid;
		len_taille = len_taille < ft_strlen(tab[index].taille) ? ft_strlen(tab[index].taille) : len_taille;
		len_link = len_link < ft_strlen(tab[index].link) ? ft_strlen(tab[index].link) : len_link;
		index++;
	}

}