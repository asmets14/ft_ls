
# include "ft_ls.h"


char *translate_name(uid_t st_uid)
{
	struct passwd *translate;
	char *name;

	translate = getpwuid(st_uid);
	name = translate->pw_name;
	return (name);

}

char *translate_group(gid_t st_gid)
{
	struct group *translate;
	char *group;

	translate = getgrgid(st_gid);
	group = translate->gr_name;

	return(group);

}



void register_info(char *way, t_type *option, int len_list, t_lst *list)
{
	struct stat info;
	t_statinfo	*tab;
	char *complet_way;
	int j;
	int total;
	t_elem *elem;
	
	elem = list->head;
	total = 0; 
	j = 0;
	tab = (t_statinfo *)malloc(sizeof(t_statinfo) * (len_list +1));
	while(elem)
	{		
		complet_way = ft_xstrjoin(way, elem->data);
		if(lstat(complet_way, &info) == 0)
		{
			tab[j].name = elem->data;
			tab[j].taille = ft_itoa(info.st_size);
			tab[j].link = ft_itoa(info.st_nlink);
			tab[j].blksize = ft_itoa(info.st_blocks);
			tab[j].date = split_date(ctime(&(info.st_mtime)));
			if(option->l == 1)
			{
				tab[j].st_uid = translate_name(info.st_uid);
				tab[j].st_gid = translate_group(info.st_gid);
			}
			else
			{
				tab[j].st_uid = ft_itoa(info.st_uid);
				tab[j].st_gid = ft_itoa(info.st_gid);
			}
			tab[j].mode = get_mode(info);
			tab[j].d_major = ft_itoa(major(info.st_rdev));
			tab[j].d_minor = ft_itoa(minor(info.st_rdev));
			j++;
		}
		total += info.st_blocks;
		elem = elem->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	get_alignement(tab, len_list, option);
}

void get_stat(t_lst *list, char *way, t_type *option)
{
	char *complet_way;
	t_statinfo stock;
	int i;
	t_elem *elem;

	i = 0;
	elem = list->head;
	while(elem)
	{
		elem = elem->next;
		i++;
	}
	way = ft_strjoin(way, "/");
	register_info(way, option,  i, list);

	//ft_putendl(stock[0].name);
}	
