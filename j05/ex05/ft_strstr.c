/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 19:12:42 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/06 16:38:30 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_found(char *str, char *to_find, int idx_str)
{
	int		trouve;
	int		idx_str1;
	int		idx_tofind;

	trouve = 0;
	if (str[idx_str] == to_find[0])
	{
		idx_str1 = idx_str;
		idx_tofind = 0;
		while (str[idx_str1] != '\0' && to_find[idx_tofind] != '\0'
				&& str[idx_str1] == to_find[idx_tofind])
		{
			idx_str1++;
			idx_tofind++;
		}
		if (to_find[idx_tofind] == '\0')
		{
			trouve = 1;
		}
	}
	return (trouve);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		idx_str;
	int		trouve;

	idx_str = 0;
	trouve = 0;
	while (str[idx_str] != '\0' && trouve == 0)
	{
		trouve = is_found(str, to_find, idx_str);
		idx_str++;
	}
	if (trouve == 0)
	{
		return (NULL);
	}
	else
	{
		return (str + idx_str - 1);
	}
}
