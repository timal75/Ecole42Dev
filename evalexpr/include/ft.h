#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

t_opp g_optab0[] =
{
		{'+', &ft_add},
			{'\0', &ft_add},
};
t_opp g_optab1[] =
{
		{'*', &ft_mul},
			{'/', &ft_div},
				{'%', &ft_mod},
					{'\0', &ft_add},
};
t_opp *(g_optab[]) = {g_optab0, g_optab1};

#endif
