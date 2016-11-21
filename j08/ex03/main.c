#include "ft_abs.h"
#include <unistd.h>

void ft_putchar(char c)
{
		write(1, &c, 1);
}

void	ft_putnbr(int n)
{
		if (n < 0)
				{
							ft_putchar('-');
									ft_putnbr(-n);
										}
			else if (n > 9)
					{
								ft_putnbr(n / 10);
										ft_putchar((n % 10) + '0');
											}
				else if ( n <= 9)
							ft_putchar((n % 10) + '0');
}

int	main(void)
{
		int n;

			n = 15;
				n= ABS(n);
					ft_putnbr(n);
						return (0);
}
