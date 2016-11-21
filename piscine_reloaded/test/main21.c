#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  *ft_range(int min, int max);
int main (void)
{
	int		min;
	int		max;
	int		*tab;


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
//##########
//########Exo 21 
	min = 15;
	max =  10;
    tab = ft_range(min, max);
	while (min <= max)
	{
		printf("tab  %d\n",*tab);
		tab++;
		min++;
	}
//##########
//########Exo 21 
	min = 5;
	max =  5;
    tab = ft_range(min, max);
	if (tab){
	while (min <= max)
	{
		printf("tab  %d\n",*tab);
		tab++;
		min++;
	}}
//##########0
//########Exo 21 
	min = 5;
	max =  25;
    tab = ft_range(min, max);
	while (min <= max)
	{
		printf("tab  %d\n",*tab);
		tab++;
		min++;
	}
//##########0
	return (0);
}
