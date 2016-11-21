#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ft_strlen(char *str);
int main (void)
{
	char  dest[10]="tyer \0";
	char  s1[10]="aaaa\0";


//########Exo 16
	printf("Longueur chaine %d\n",ft_strlen(dest));
	printf("Longueur chaine %d\n",ft_strlen(s1));
//##########
//##########
	return (0);
}
