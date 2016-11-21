/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 20:48:50 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/06 21:10:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_numeric(char ctr)
{
	if ((ctr >= 'a' && ctr <= 'z') || (ctr >= 'A' && ctr <= 'Z'))
		return (1);
	else
		return (0);
}

int		ft_str_is_alpha(char *str)
{
	int		k;

	k = 1;
	while (*str != '\0' && k == 1)
	{
		k = is_numeric(*str);
		str++;
	}
	return (k);
}
