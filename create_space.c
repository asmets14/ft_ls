
#include "ft_ls.h"

void create_space(int len, char *tab)
{
	int j;
	char *new;
	j = ft_strlen(tab);

	new = (char *)malloc(sizeof(char) * len);
	ft_memset(new, ' ', ((len - j) + 1));
	new = ft_strjoin(new, tab);
	ft_putstr(new);
}