#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
#include <fcntl.h>
# define BUF_SIZE 1
# include <stdio.h>

typedef	int	(*t_function)(int, int);

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int 			ft_strcmp(char *s1, char *s2);
char			*ft_strrev(char *str);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
char			*ft_itoa(int nbr);
char			*ft_strcat(char *dest, char *src);
char			*ft_strdup(char *src);
char			*ft_strcpy(char *dest, char *src);
int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);
int     		etendrecarre(char **tab, int *carre, int taille, int *val);
int 			taillecarre(char **tab, int *carre, int nbLig, int nbCol);
void    		lancer_traitement(char **tab, int nb_lignes, int nb_col, char *carac);
void			init(char *file, int nb_lignes, int nb_col, char *carac);
char        	**initialiser(char **tab);
void    		imprimer_tableau(char **tab, int nb_lignes, int nb_col);
char        	**remplir_tableau(char **tab, int *carre, char plein);
void    		remp_carac(char **tab, int nb_lignes, char vide, char obstacle);
void    		remettre_carac(char **tab, int nb_lignes, char vide, char obstacle);
int				feed_file(int fd, char *file, char *carac);
void			operate_tab(char **tab, int x);
void			operate2_tab(char **tab2,int nb_lignes, char *chartab);
int				char_ok(char **tab);
int				char_ok2(char *chartab);
void			ft_display(char *colle, int x, int y);
void			test_file(char *file);
void			disp_file(int fd);
char  			*char_feed(char **tab, int x);
void			lirefichier (char *file, char **tab, int nb_lignes, char *carac);


#define NEG(x) (((x) < 0) ? 1 : 0)
#define ABS(x) (((x) < 0) ? -(x) : x)

#endif
