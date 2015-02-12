
#include "ft_ls.h"

void ft_swap(void *tab, int i, int j)
{
	void *tmp;
	void **tabtemp;

	tabtemp = tab;
	tmp = tabtemp[i];
	tabtemp[i] = tabtemp[j];
	tabtemp[j] = tmp;
}