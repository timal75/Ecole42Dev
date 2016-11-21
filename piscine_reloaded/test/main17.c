#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ft_strcmp(char *s1, char *s2);
int main (void)
{
	char  s1[10]="aaaa\0";
	char  s2[10]="aaa\0";
	char  s3[10]="aaa\0";
	char  s4[10]="aaa\0";
	char  s5[10]="aa\0";
	char  s6[10]="aaa\0";


//##########
//########Exo 17
	printf("strcomp  %d\n",ft_strcmp(s1, s2));
	printf("strcomp  %d\n",strcmp(s1, s1));
	printf("strcomp  %d\n",ft_strcmp(s3, s4));
	printf("strcomp  %d\n",ft_strcmp(s5, s6));
	return (0);
}
