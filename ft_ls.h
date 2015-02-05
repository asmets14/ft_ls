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
# include <time.h>
# include <stdio.h>

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
	char			*taille;
	char			*name;
	char			*st_uid;
	char			*st_gid;
	char			*link;
	char			*blksize;
	char			*date;
	int 			total;
	char			*mode;
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

typedef struct s_getallign
{
	int len_nom;
	int len_taille;
	int len_total;
	int len_name;
	int len_uid;
	int len_gid;
	int	len_link;
	int index;
}				t_getallign;


t_lslist *opening(char *str, int option);
t_lslist *create_list(t_lslist *list, char *name);
t_opt init_opt(char **av, t_opt option, int rep);
int main(int ac, char **av);
void print(t_lslist *list, t_opt option, char *str);
void get_stat(t_lslist *list, char *way, t_opt option);
void get_alignement(t_statinfo *tab, int compteur, t_opt option);
void final_string(t_getallign *len, t_statinfo *tab, int i, t_opt option);
void ft_print_list(t_lslist *list);
t_lslist *R(char *str, t_lslist *fichier, t_lslist *dossier, t_lslist *tmp);
char *get_mode(struct stat info);
char *split_date(char *str);
void create_space(int len, char *tab);
int check_arg(int ac, char **av);

#endif