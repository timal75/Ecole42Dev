/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 15:38:00 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/21 01:41:27 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <header.h>

char	*ft_itoa(int num)
{
	int		i;
	int		neg;
	char	*str;

	i = 0;
	str = (char *)malloc(10000);
	neg = 0;
	if (num < 0)
		neg = 1;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (num)
	{
		str[i++] = ABS(num % 10) + '0';
		num = num / 10;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
