/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 15:59:27 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/03 16:00:11 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		x;

	if (nb > 1)
	{
		nb--;
		x = (nb + 1) * ft_iterative_factorial(nb);
	}
	else
	{
		x = 1;
	}
	return (x);
}
