
#include "ft_ls.h"

void create_space(int len, char *tab, char c)
{
	int j;
	char *new;
	char *tmp;
	j = ft_strlen(tab);

	if (c == 'a')
	{
		new = tab;
		new = ft_xstrjoin(new, " ");		
		while(j < len)
		{
			new = ft_xstrjoin_free(new, " ", 'g');
			j++;
		}
		tmp = new;
	}
	if (c == 't') 
	{
		new = ft_strnew(len);
	 	ft_memset(new, ' ', ((len - j) + 1));
	 	
		new = ft_strjoin(new, tab);
		tmp = new;
		// printf("\n======{%s}=====\n", new);
	}
	free(new);
	ft_putstr(tmp);
}