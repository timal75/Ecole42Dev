/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 15:19:35 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/02 15:42:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void 	ft_swap(int *a, int *b)
{
	int		c;
	c=*a;
	*a=*b;
	*b=c;
}

int 	main(void)
{
	int		var1;
	int     var2;
	int		*a;
	int		*b;

	a=&var1;
	b=&var2;
	*a=9;
	*b=10;
	printf("La variable a vaut : %d\n", var1);
	printf("La variable b vaut : %d\n", var2);
	printf("Appel a la function\n");
	ft_swap(a,b);
	printf("La variable a vaut : %d\n", var1);
	printf("La variable b vaut : %d\n", var2);

}
