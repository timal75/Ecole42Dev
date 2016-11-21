/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 16:31:30 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/02 16:36:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
void 	ft_ultimate_ft(int *a, int *b)
{
	int		c;
	int		d;
	c = *a;
	d = *b;
	*a = c / d;
	*b = c % d;
}

int 	main(void)
{
	int		var1;
	int     var2;
	int		*a;
	int		*b;

	a=&var1;
	b=&var2;
	*a=28;
	*b=10;
	printf("La variable a vaut : %d\n", var1);
	printf("La variable b vaut : %d\n", var2);
	printf("Appel a la function\n");
	ft_ultimate_ft (a,b);
	printf("La variable a vaut : %d\n", var1);
	printf("La variable b vaut : %d\n", var2);

}
