#include <stdio.h>
void ft_swap(int *a, int *b);
int	main (void)
{
	int	a;
	int	b;

	a = -5892;
	b = -465;
	printf("tt : %d\n",a);
	printf("tt : %d\n",b);
	ft_swap(&a, &b);
	printf("tt : %d\n",a);
	printf("tt : %d\n",b);
}
