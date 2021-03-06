/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:55:14 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/20 20:56:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str)
{
	int		i;
	char	*dest;

	dest = str;
	i = 0;
	while (*dest != '\0')
	{
		i++;
		dest++;
	}
	return (i);
}
