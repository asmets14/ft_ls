#include "ft_ls.h"

char *get_mode(struct stat info)
{
	char *mode;

	mode = ft_memalloc(12);
	if (S_ISLNK(info.st_mode))
		mode[0] = 'l';
	else if (S_ISDIR(info.st_mode))
		mode[0] = 'd';
	else if (S_ISSOCK(info.st_mode))
		mode[0] = 's';
	else if (S_ISFIFO(info.st_mode))
		mode[0] = 'p';
	else if (S_ISCHR(info.st_mode))
		mode[0] = 'c';
	else if (S_ISBLK(info.st_mode))
		mode[0] = 'b';
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
	mode[10] = ' ';
	mode[11] = '\0';

	return (mode);
}