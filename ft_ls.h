#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <time.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>


# define OPT1(x) (x == 'l' || x == 'n' || x == 'a' || x == 't') 
# define OPT2(x) (x == 'r' || x == 'R' )
# define OPT(x) (OPT1(x) || OPT2(x)) 

typedef int			t_opt;

# define OPT0R 0x20
# define OPT_R 0x10
# define OPT_T 0x08
# define OPT_A 0x04
# define OPT_N 0x02
# define OPT_L 0x01

typedef struct		s_statinfo
{
	size_t			*name;
	size_t			*date;
	char			*st_uid;
	char			*st_gid;
	char			*st_nlink;
	size_t			*file_name;
	char			*st_size;
	size_t			*file_mode;
}					t_statinfo;


typedef struct		s_info
{
		char *name;
}					t_info;

typedef struct		s_lslist
{
	t_info		contenu;
	char *str;
	struct s_lslist	*next;
}					t_lslist;


int main(int ac, char **av);
t_lslist *opening(char *str, int option);
t_opt init_opt(char **av, t_opt option, int rep);
void	print(t_lslist *list, t_opt option, char *str);
void get_stat(t_lslist *list, char *way, t_opt option);

#endif