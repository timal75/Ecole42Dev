/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 17:17:42 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/14 17:25:53 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*list;
	int		cpt;

	cpt = 0;
	list = begin_list;
	if (list)
	{
		cpt = 1;
		while (list->next)
		{
			list = list->next;
			cpt++;
		}
	}
	return (cpt);
}
