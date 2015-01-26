#include "ft_ls.h"

char *split_date(char *str)
{
	char mois[4];
	char date[3];
	char heure[6];
	char *new;
	int i;
	int j;

	j = 0;
	i = 4;
	while(str[i])
		str[j++] = str[i++];
	str[j + 1] = '\0';

	i = 0;
	while(i < 3)
	{
		mois[i] = str[i];
		i++;
	}
	mois[i++] = '\0';

	j = 0;
	while (i < 7)
		date[j++] = str[i++];
	date[j++] = '\0';  

	j = 0;
	while (i < 12)
		heure[j++] = str[i++];
	heure[j++] = '\0';

	new = ft_xstrjoin(date, mois);
	new = ft_xstrjoin_free(new, " ", 'g');
	new = ft_xstrjoin_free(new, heure, 'g');
	
	return (new);
}