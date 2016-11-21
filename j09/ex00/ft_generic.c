/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 17:59:44 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/08 18:13:19 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_generic(void)
{
	char	*tab;
	char	eol;

	eol = '\n';
	tab = "Tu tu tu tu ; Tu tu tu tu";
	while (*tab != '\0')
	{
		write(1, tab, 1);
		tab++;
	}
	write(1, &eol, 1);
}
