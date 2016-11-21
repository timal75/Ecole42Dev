#include "ft_base_func.h"
#include "ft_base_func2.h"
#include "ft_sudoku.h"
#include <stdio.h>

void	main2(char **grille, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i <= 9)
	{
		grille[j] = argv[i];
		i++;
		j++;
	}
}

int		main(int argc, char **argv)
{
	char	**grille;
	t_bool	not_enough;

	if (argc != 10 )
	{
		ft_putstr("Erreur");
		ft_putchar('\n');
		return (0);
	}
	not_enough = TRUE;
	grille = (char**)malloc(sizeof(91));
	if (check(argc, argv) == FALSE)
		return (0);
	main2(grille, argv);
	not_enough = ft_is_args_valide(grille);
	if (argc != 10 || (check_args(grille)) < 17 || not_enough == TRUE)
	{
		ft_putstr("Erreur");
		ft_putchar('\n');
		return (0);
	}
	sudoku_solver(grille, 0);
	ft_print_sud(grille);
	return (0);
}
