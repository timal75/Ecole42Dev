/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 18:02:36 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/08 13:28:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(char *src)
{
	char		*dest;
	int			size;
	int			i;

	i = 0;
	size = 0;
	while (src[i] != '\0')
	{
		i++;
		size++;
	}
	dest = (char *)malloc(sizeof(*src) * size + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
int	main()
{
	char		*tab;
	char		*tab1;

	tab="o3q2iw0xYJulQrRLUA1LH70S2Ob0WYiMdLTXe7qRF8ay";
	tab1 = ft_strdup( tab);	
	while ( *tab1 != '\0')
	{
	 	write(1,tab1,1);
		tab1++;
	}
	return(0);
}
