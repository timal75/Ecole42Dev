/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 14:08:28 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/01 23:29:08 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_a_imprimer(char a, char b, char c)
{
	if (a < b && b < c)
	{
		ft_putchar(',');
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(c);
	}
}

void	ft_print_comb(void)
{
	char n1;
	char n2;
	char n3;

	n1 = '0';
	n2 = '0';
	n3 = '0';
	while (n1 <= '9')
	{
		while (n2 <= '9')
		{
			while (n3 <= '9')
			{
				ft_a_imprimer(n1, n2, n3);
				n3 = n3 + 1;
			}
			n3 = '0';
			n2 = n2 + 1;
		}
		n2 = '0';
		n1 = n1 + 1;
	}
	ft_putchar('\n');
}
