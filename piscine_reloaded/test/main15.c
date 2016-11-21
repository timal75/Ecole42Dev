#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ft_putstr(char *str);
int main (void)
{
	char  dest[10]="tyer \0";
//####### Exo 15
    ft_putstr(dest);
	dest[0] = 'c';
	dest[1] = 's';
	dest[2] = 't';
	dest[3] = '\0';

    ft_putstr(dest);
//###########
	return (0);
}
