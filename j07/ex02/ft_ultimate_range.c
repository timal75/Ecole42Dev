/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 20:45:31 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/09 16:08:49 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	int			j;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
	}
	else
	{		*range = malloc(sizeof(int) * (max - min));
		if ( *range )
		{	
			j = min;
			i = 0;
			while (j < max)
			{	
				*(*range+i) = j;
				i++;
				j++;
			}
		}
	}	
	return (i);
}
int  main ()
{
	int		*tab;
	int		j;
	int		i;

	j = ft_ultimate_range(&tab,5,15);

	//j = 0;
	printf("Le resultat est : %d\n", j);
	i =0;
	while ( i < j)
	{
		printf("l'indeice i %d est %d\n", i, tab[i]);
		i++;
	}
	return(0);
}

