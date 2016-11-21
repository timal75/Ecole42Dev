/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:49:16 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/08 21:31:11 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*stringheure(int amdebut)
{
	char	*stdebut;

	if (amdebut == 0)
		stdebut = "A.M.";
	else
		stdebut = "P.M.";
	return (stdebut);
}

void	ft_takes_place(int hour)
{
	int		heuredebut;
	int		heurefin;
	int		amdebut;
	int		amfin;

	heuredebut = hour % 12;
	amdebut = hour / 12;
	heurefin = heuredebut + 1;
	amfin = amdebut;
	if (heuredebut == 0)
		heuredebut = 12;
	if (heurefin == 12 && amfin == 1 && heuredebut == 11 && amdebut == 1)
		amfin = 0;
	if (heurefin == 12 && amfin == 0 && heuredebut == 11 && amdebut == 0)
		amfin = 1;
	printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %s AND %d.00 %s\n",
			heuredebut, stringheure(amdebut), heurefin, stringheure(amfin));
}
