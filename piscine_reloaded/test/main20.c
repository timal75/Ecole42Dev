#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *ft_strdup(char *str);
int main (void)
{
	char  s1[10]="NtCOo\0";
	char  s2[100]="33iqWp9BGdiJ6pZ0ZKqCN6potlOrrUduXQ2XW2XG5BZ4z\0";
	char  *dup1;
	char  *dup2;


//##########
//########Exo 20 
	dup1 =strdup(s1);
	dup2 =strdup(s1);
	printf("dup1 > %s\n",dup1);
	printf("dup2 > %s\n",dup2);

	dup1 =strdup(s2);
	dup2 =strdup(s2);
	printf("dup1 > %s\n",dup1);
	printf("dup2 > %s\n",dup2);
	printf("dest > %s\n",s1);
	printf("dest > %s\n",s2);
	free(dup1);
	free(dup2);
//##########
	return (0);
}
