#include <stdio.h>
int ft_iterative_factorial(int nb);
int main(void)
{
	int	nb;

	nb = ft_iterative_factorial(8);
	printf("tt : %d\n",nb);
	nb = ft_iterative_factorial(7);
	printf("tt : %d\n",nb);
	nb = ft_iterative_factorial(17);
	printf("tt : %d\n",nb);
	nb = ft_iterative_factorial(0);
	printf("tt : %d\n",nb);
	nb = ft_iterative_factorial(-5);
	printf("tt : %d\n",nb);
}
