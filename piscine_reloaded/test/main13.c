#include <stdio.h>
int ft_recursive_factorial(int nb);

int 	main(void)
{

	printf("factoriel 5 : %d\n",ft_recursive_factorial(5));
	printf("factoriel -2 : %d\n",ft_recursive_factorial(-2));
	printf("factoriel 0 : %d\n",ft_recursive_factorial(0));
	printf("factoriel 25: %d\n",ft_recursive_factorial(25));
	printf("factoriel 12 : %d\n",ft_recursive_factorial(12));
	return (0);
}
