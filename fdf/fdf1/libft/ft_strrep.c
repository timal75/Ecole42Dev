/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 17:55:42 by jblancha          #+#    #+#             */
/*   Updated: 2017/09/13 18:45:13 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrep(char *src, char to_find, char to_replace)
{
	char	*dest1;

	dest1 = src;
	while (*src != '\0')
	{
		if (*src == to_find)
			*src = to_replace;
		src++;
	}
	return (dest1);
}
