#include <stddef.h>
void ft_is_negative(int n);
int	main(void)
{
	int	c;
	c=NULL;
	ft_is_negative(5);
	ft_is_negative(-5);
	ft_is_negative(0);
	ft_is_negative(25);
	ft_is_negative(c);
}
