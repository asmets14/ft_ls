#include "ft_ls.h"

char *get_mode(struct stat info)
{
	char *mode;

	mode = ft_memalloc(11);
	if(info.st_mode & S_IFDIR)
		mode[0] = 'd';
	else
		mode[0] = '-';
	mode[1] = ((info.st_mode & S_IRUSR) ? 'r' : '-');
	mode[2] = ((info.st_mode & S_IWUSR) ? 'w' : '-');
	mode[3] = ((info.st_mode & S_IXUSR) ? 'x' : '-');
	mode[4] = ((info.st_mode & S_IRGRP) ? 'r' : '-');
	mode[5] = ((info.st_mode & S_IWGRP) ? 'w' : '-');
	mode[6] = ((info.st_mode & S_IXGRP) ? 'x' : '-');
	mode[7] = ((info.st_mode & S_IROTH) ? 'r' : '-');
	mode[8] = ((info.st_mode & S_IWOTH) ? 'w' : '-');
	mode[9] = ((info.st_mode & S_IXOTH) ? 'x' : '-');
	mode[10] = '\0';

	return (mode);
}