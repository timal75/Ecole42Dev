#include "libft.h"

int		main (void)
{
	char	*tab;
	char	c;
	char	d;

	tab = (char *)malloc(sizeof(char)*20);
	ft_strcpy(tab, "ici \nc'est \n42");

	printf("%s\n", tab);
	printf("%s\n", ft_strrep(tab, '\n', '.'));

	return (0);

}
