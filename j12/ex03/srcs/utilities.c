#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_bad_name(char *str)
{
	ft_putstr("hexdump: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
}

void	ft_bad_fd(char *str)
{
	ft_putstr("hexdump: ");
	ft_putstr(str);
	ft_putstr(": Bad file descriptor\n");
}
