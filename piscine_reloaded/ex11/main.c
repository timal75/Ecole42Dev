#include <stdio.h>
void ft_div_mod(int a, int b, int *div, int *mod);
int main (void)
{
	int	a;
	int b;
	int div;
	int mod;

	a = 15;
	b = 2;
	div = 0;
	mod = 0;
	ft_div_mod(a, b, &div, &mod);
	printf("tt : %d\n", a);
	printf("tt : %d\n", b);
	printf("tt : %d\n", div);
	printf("tt : %d\n", mod);
	return (0);
}
