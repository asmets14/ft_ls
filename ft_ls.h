#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include "libft/libft.h"
# include "liba/liba.h"

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
	char 			*d_minor;
	char 			*d_major;
}					t_statinfo;

typedef struct		s_type
{
	int		a;
	int		l;
	int		r;
	int		R;
	int		t;
	int 	n;
	int 	rien;
	int		error;
}					t_type;


typedef struct s_getallign
{
	int len_nom;
	int len_taille;
	int len_total;
	int len_name;
	int len_uid;
	int len_gid;
	int	len_link;
	int len_major;
	int len_minor;
	int index;
}				t_getallign;


void ft_no_major_exist(char caract, size_t len);
void	bubble_tri(char **tab, int size);
void ft_swap(void *tab, int i, int j);
char ** lst_to_tab(t_lst *list, char **tab);
t_lst *opening(char *str);
void create_list(t_lst *list, char *name);
t_type *init_opt(char **av, int rep);
int main(int ac, char **av);
void print(t_lst *list, t_type *option, char *str);
void get_stat(t_lst *list, char *way, t_type *option);
void get_alignement(t_statinfo *tab, int compteur, t_type *option);
void final_string(t_getallign *len, t_statinfo *tab, int i);
void ft_print_list(t_lst *list);
void ft_print_list_without_point(t_lst *list);
void R(t_lst *list, char *way, t_type *option);
char *get_mode(struct stat info);
char *split_date(char *str);
void create_space(int len, char *tab, char c);
int check_arg(int ac, char **av);

#endif
