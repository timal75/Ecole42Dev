/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 18:46:53 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/14 23:13:48 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list				*list;
	unsigned int		cpt;

	cpt = 0;
	list = begin_list;
	if (!list)
		return (NULL);
	if (list)
	{
		while (list->next && cpt <= nbr)
		{
			list = list->next;
			cpt++;
		}
	}
	if (cpt == nbr)
		return (list);
	else
		return (NULL);
}
