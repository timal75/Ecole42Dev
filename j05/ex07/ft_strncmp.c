/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:50:20 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/06 17:24:06 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				k;
	unsigned int	j;

	k = 0;
	j = 1;
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && j < n)
	{
		s1++;
		s2++;
		j++;
	}
	if ((*s1 > *s2) || (*s2 == '\0' && *s1 != '\0'))
	{
		k = 1;
	}
	if ((*s2 > *s1) || (*s1 == '\0' && *s2 != '\0'))
	{
		k = -1;
	}
	if ((*s1 == '\0' && *s2 == '\0') || (*s1 == *s2))
	{
		k = 0;
	}
	return (k);
}
