#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ft_sqrt(int nb);
//int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
void ft_putstr(char *str);
char *ft_strdup(char *str);
int  *ft_range(int min, int max);
int main (void)
{
	char  dest[10]="tyer \0";
	char  s1[10]="aaaa\0";
	char  s2[10]="aaa\0";
	char  *dup1;
	char  *dup2;
	int		min;
	int		max;
	int		*tab;


//####### Exo 14
	//printf("racine carre %d\n",ft_sqrt(64));
	//printf("racine carre %d\n",ft_sqrt(64*64));
//#######
//####### Exo 15
    ft_putstr(dest);
	dest[0] = 'c';
	dest[1] = 's';
	dest[2] = 't';
	dest[3] = '\0';

    ft_putstr(dest);
//###########
//########Exo 16
	//printf("Longueur chaine %d\n",ft_strlen(dest));
//##########
//########Exo 17
	printf("strcomp  %d\n",ft_strcmp(s1, s2));
	printf("strcomp  %d\n",strcmp(s1, s2));
//##########
//########Exo 20 
	dup1 =strdup(s1);
	dup2 =ft_strdup(s1);
	printf("dest > %s\n",dest);
	printf("dup1 > %s\n",dup1);
	printf("dup2 > %s\n",dup2);
	free(dup1);
	free(dup2);
//##########
//########Exo 21 
	min = 5;
	max =  10;
    tab = ft_range(min, max);
	while (min <= max)
	{
		printf("tab  %d\n",*tab);
		tab++;
		min++;
	}
		printf("strcomp  %d\n",strcmp(s1, s2));
//##########
	return (0);
}
