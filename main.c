
#include "ft_ls.h"

int main(int ac, char **av)
{
	int rep;
	char *repository;
	t_opt option;
	t_lslist *list;
	
	list = NULL;
	option = 0x0	;
	rep = 0;
	if(ac > 1)
	{
		if((rep = check_arg(ac, av)) != 0)
		{
			option = init_opt(av, option, rep);
			if(rep < ac)
			{
				while(rep < ac)
				{
					repository = av[rep];
					list = opening(repository, option);	
					rep++;
				}
			}
			else
			{
				repository = ".";
				list = opening(repository, option);
			}
		}
		print(list, option, repository);
	}
	// Ajouter if ac == 1
	ft_putchar('\n');
	return (0);
}
