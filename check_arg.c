
#include "ft_ls.h"

int check_arg(int ac, char **av)
{
	int i;
	int j;
	
	i = 1;
	j = 1;
	while(av[i] && av[i][0] == '-') // !! NON Gestion plusieur mm arg !!!
	{								//av[i] != av[i-1]
		while (av[i][j])
		{	
			if(!OPT(av[i][j]))
			{
				ft_putendl("ERROR"); // check_error 
				return(0);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (i); // posi dossier
}