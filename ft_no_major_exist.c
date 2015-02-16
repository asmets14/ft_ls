#include "ft_ls.h"

void ft_no_major_exist(char caract, size_t len)
{
	char *str;

	str = ft_strnew(len + 1);
	str = ft_memset(str, caract, len);
	ft_putstr(str);
}