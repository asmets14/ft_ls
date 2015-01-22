#include "ft_ls.h"

t_opt init_opt(char **av, t_opt option, int rep)
{
	int i;
	int j;

	i = 1;
	while(i < rep)
	{
		j = 0;
		while(av[i][j])
		{
			if (av[i][j] == 'l')
				option |= OPT_L;
			if (av[i][j] == 'n')
				option |= OPT_N;
			if (av[i][j] == 'a')
				option |= OPT_A;
			if (av[i][j] == 't')
				option |= OPT_T;
			if (av[i][j] == 'r')
				option |= OPT_R;
			if (av[i][j] == 'R')
				option |= OPT0R;
			j++;
		}
		i++;
	}
	return(option);
}
