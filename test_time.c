#include <stdio.h>
#include <time.h>
int main(void)
{
	char *date;

  	date = ctime(time());
  	ft_putstr(date);
    return 0;
}