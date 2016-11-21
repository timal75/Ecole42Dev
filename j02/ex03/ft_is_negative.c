/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:27:21 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/01 21:24:02 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	char reponse;
	char findeligne;

	reponse = 'Y';
	findeligne = '\n';
	if (n >= 0)
	{
		reponse = 'N';
	}
	ft_putchar(reponse);
	ft_putchar(findeligne);
}
