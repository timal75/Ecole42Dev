/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 19:44:49 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/14 23:17:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*nouvelle_liste;
	t_list	*tmp;

	nouvelle_liste = NULL;
	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		(*begin_list)->next = nouvelle_liste;
		nouvelle_liste = *begin_list;
		*begin_list = tmp;
	}
	*begin_list = nouvelle_liste;
}
