/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 23:01:38 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/15 23:01:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdio.h"

void	ft_put_filename(int ac, char *avi, int *cpt)
{
	if (*cpt != 0)
		ft_putstr("\n");
	if (ac > 4)
	{
		ft_putstr("==> ");
		ft_putstr(avi);
		ft_putstr(" <==\n");
	}
}
