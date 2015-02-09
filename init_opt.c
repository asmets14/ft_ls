#include "ft_ls.h"

void	*xmalloc(size_t size)
{
	void *cerise;

	cerise = malloc(size);
	if(!cerise)
		exit (1);
	else
		return(cerise);
}

t_type *option_new();
{
	t_type *option;

	option = (t_type *)xmalloc(sizeof(t_type))
	option->a = 0;
	option->l = 0;
	option->r = 0;
	option->R = 0;
	option->t = 0;
	option->n = 0;
	return (option);
}

t_type *init_opt(char **av, int rep)
{
	int i;
	int j;
	t_type	*option;
	i = 1;
	option = option_new();
	while(i < rep)
	{
		j = 0;
		while(av[i][j])
		{
			if (av[i][j] == 'l')
				option->l = 1; 
			if (av[i][j] == 'n')
				option->n = 1;
			if (av[i][j] == 'a')
				option->a = 1;
			if (av[i][j] == 't')
				option->t = 1;
			if (av[i][j] == 'r')
				option->r = 1;
			if (av[i][j] == 'R')
				option->R = 1;
			j++;
		}
		i++;
	}
	return(option);
}
