#include "ft_ls.h"

char *split_date(char *str)
{
	char *mois;
	char *date;
	char *heure;
	char *new;
	int i;
	int j;

	mois = ft_strsub(str, 4, 3);
	date = ft_strsub(str, 9, 1);
	heure = ft_strsub (str, 11, 5);
	new = ft_xstrjoin(mois, "  ");
	new = ft_xstrjoin_free(new, date, 'g');
	new = ft_xstrjoin_free (new , " ", 'g');
 	new = ft_xstrjoin_free(new, heure, 'g');
	return (new);
}