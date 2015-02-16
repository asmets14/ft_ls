
#include "ft_ls.h"

void	bubble_tri(char **tab, int size)
{
	int i;
	int j;
	
	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - j - 1)
		{	
			if (ft_strcmp(tab[i], tab[i+1]) > 0)
				ft_swap(tab ,i, (i + 1));
			i++;
		}
		j++;
	}
}
