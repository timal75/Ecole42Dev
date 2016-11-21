#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		controleparam(int argc, char **argv);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		linecheck(int c, char **grille, int x)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (grille[x][j] == c)
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int		columncheck(int c, char **grille, int y)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (grille[j][y] == c)
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int		blockcheck(int c, char **grille, int x, int y)
{
	int y2;
	int x2;

	//printf("coord  function  x %d y %d\n",x,y);
	y2 = y -  (y % 3);
	x2 = x - (x % 3);
	//printf("x2  %d  y2  %d\n", x2,y2);
	y = y2;
	x = x2;
	while (x < x2 + 3)
	{
		while (y < y2+3)
		{
			if (grille[x][y] == c)
			{
				if (x == 0 && y == 2)
				{
				printf("erreur  x %d, y %d  (2,1) %c  (0,2)  %c\n",x,y,grille[2][1], grille[0][2] );
				}
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int		ft_validity(char **grille, int position)
{
	int x = position / 9;
	int y = position % 9;
	char c;

	c = '1';
	if (position == 81)
	{
		return (1);
	}


	if (grille[x][y] != '.')
	{
		return ft_validity(grille, position+1);
	}

	while (c <= '9')
	{
		if (linecheck(c, grille, x) && columncheck(c, grille, y) && blockcheck(c, grille, x, y) )
		{
			grille[x][y] = c;
		
			if (ft_validity(grille, position+1) )
			{
				return (1);
			}
		}
		c++;
	}
	grille[x][y] = '.';
	return (0);
}

void	ft_makearray(int argc, char **argv)
{
	int y;
	int x;

	y = 0;
	while (y < argc-1)
	{
		x = 0;
		while (argv[y][x] != '\0')
		{
			ft_putchar(argv[y][x]);
			if (x < 8)
			{
				ft_putchar(' ');
			}
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	copygrille(char **grille, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while(i <= 9)
	{
		grille[j] =  argv[i];
		i++;
		j++;
	}
}

int		main(int argc, char **argv)
{

	if ((argc != 10) || controleparam(argc, argv) != 0)
	{
		write(1, "Error\n", 6);
	}
	else
	{
		int position;
		char	**grille;
		int		error;

		grille = (char**)malloc(sizeof(91));
		copygrille (grille, argv);
		position = 0;
		error  = ft_validity(grille, position);
		printf("==============================================================================\n");
		if (error == 0)
			write(1, "Error\n", 6);
		position = 0;
		error =0;
		ft_makearray(argc, grille);
	free (grille);
	}
	return (0);
}
