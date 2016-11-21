#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	int	(*t_function)(int, int);

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);

char			*ft_strrev(char *str);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
char			*ft_itoa(int nbr);
char			*ft_strcat(char *dest, char *src);
char			*ft_strdup(char *src);

int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);

int				ft_do_op(char *str);
int				eval_expr(char *str);

typedef struct	s_opp
{
		char		c;
			t_function	func;
}				t_opp;

#define NEG(x) (((x) < 0) ? 1 : 0)
#define ABS(x) (((x) < 0) ? -(x) : x)

#endif
