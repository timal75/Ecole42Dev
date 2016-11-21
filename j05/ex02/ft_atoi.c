/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:25:05 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/06 16:04:10 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		resultat;
	int		k;

	k = 0;
	resultat = 0;
	while (*str == '\n' || *str == '\r' || *str == '\t' || *str == '\a'
		|| *str == '\f' || *str == '\v' || *str == ' ' || *str == '\b')
		str++;
	if (*str == '-')
	{
		str++;
		k = 1;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		resultat = resultat + *str - '0';
		resultat = resultat * 10;
		str++;
	}
	if (k == 1)
	{
		resultat = resultat * -1;
	}
	return (resultat / 10);
}
