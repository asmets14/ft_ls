
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
void register_info(char *way, t_opt option)
{
	struct stat info;
	t_statinfo	*stock;

	stock = malloc(sizeof(t_info));
	if(stat(way, &info) == 0)
	{
		stock->st_size = ft_itoa(info.st_size);
		stock->st_nlink = ft_itoa(info.st_nlink);
		if(option == OPT_L)
		{
			stock->st_uid = translate_name(info.st_uid);
			stock->st_gid = translate_group(info.st_gid);
		}
		ft_putendl(stock->st_gid);
	}
}

void get_stat(t_lslist *list, char *way, t_opt option)
{
	char *complet_way;

	while(list != NULL)
	{
		way = ft_strjoin(way, "/");
		complet_way = ft_strjoin(way, list->contenu.name);
		register_info(complet_way, option);
		list = list->next;

	}
}


