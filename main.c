
#include "ft_ls.h"

int main(int ac, char **av)
{
	int rep;
	char *repository;
	t_type *option;
	t_lslist *list;
	
	list = NULL;
	rep = 0;
	if((rep = check_arg(ac, av)) != 0)
	{
		option = init_opt(av, rep);
		if(rep < ac)
		{
			while(rep < ac)
			{
				repository = av[rep];
				list = opening(repository);	
				rep++;
			}
		}
		else
		{
			repository = ".";
			list = opening(repository);
		}
	}
	print(list, option, repository);
//	}
	// Ajouter if ac == 1
	ft_putchar('\n');
	return (0);
}
