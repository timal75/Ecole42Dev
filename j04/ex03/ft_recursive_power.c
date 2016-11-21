/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:37:26 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/03 17:58:15 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_recursive_power(int nb, int power)
{
	int			resultat;

	resultat = 1;
	if (power > 1)
	{
		resultat = resultat * ft_recursive_power(nb, poweri-1);
	}
	return (resultat);
}
int		main(void)
{
	int			nb;
	int			power;
	int			resultat;

	nb = 2;
	power = 5;

	ft_recursive_power(nb, power);
	printf ("le resultat de la fonction factorielle est : %d\n", resultat);
	return (0);
}

