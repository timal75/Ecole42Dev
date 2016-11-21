#include <unistd.h>

int		dejapresent(char *str, char c)
{
	int		retour;
	int		nb;

	retour = 0;
	nb = 0;
	while (*str != '\0')
	{
		if (*str == c)
			nb++;
		str++;
	}
	if (nb > 1)
		retour = 1;
	if (c == '.')
		retour = 0;
	return (retour);
}

int		caractdouble(char *str)
{
	int		retour;
	char	*str1;

	str1 = str;
	retour = 0;
	while (*str != '\0' && retour == 0)
	{
		if (dejapresent(str1, *str) == 1)
			retour = 1;
		str++;
	}
	return (retour);
}

int		caractautho(char *str)
{
	int		retour;

	retour = 0;
	while (*str != '\0' && retour == 0)
	{
		if ((*str < '0' || *str > '9') && *str != '.')
			retour = 1;
		str++;
	}
	return (retour);
}

int		longueurcorrecte(char *str)
{
	int		i;
	int		retour;

	retour = 0;
	i = 1;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	if (i != 10)
		retour = 1;
	return (retour);
}

int		pointpresent(char *str)
{
	int		retour;

	retour = 1;
	while (*str != '\0')
	{
		if (*str == '.')
		{
			retour = 0;
		}
		str++;
	}
	return (retour);
}

int		controleparam(int argc, char **argv)
{
	int		i;
	int		nb_param;
	int		retour;

	retour = 1;
	i = 1;
	while (i <= argc - 1 && retour == 1)
	{
		retour = pointpresent(argv[i]);
		i++;
	}
	if (retour == 0)
	{
		nb_param = argc - 1;
		i = 1;
		while (i <= nb_param && longueurcorrecte(argv[i]) == 0
			&& caractautho(argv[i]) == 0 && caractdouble(argv[i]) == 0)
			i++;
		if (i != nb_param + 1)
			retour = 1;
	}
	return (retour);
}
