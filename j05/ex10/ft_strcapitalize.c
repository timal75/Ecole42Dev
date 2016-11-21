/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 19:13:18 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/06 20:34:03 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_numeric(char ctr)
{
	if ((ctr >= 'a' && ctr <= 'z') || (ctr >= 'A' && ctr <= 'Z')
		|| (ctr >= '0' && ctr <= '9'))
		return (1);
	else
		return (0);
}

char	capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

char	*ft_strcapitalize(char *str)
{
	int		j;

	str[0] = capitalize(str[0]);
	j = 1;
	while (str[j] != '\0')
	{
		if (is_numeric(str[j - 1]) == 0)
		{
			str[j] = capitalize(str[j]);
		}
		j++;
	}
	return (str);
}
