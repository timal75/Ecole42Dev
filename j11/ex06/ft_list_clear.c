/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 18:30:34 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/14 23:08:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_size(t_list **begin_list)
{
	t_list	*list;
	t_list	*next;

	list = *begin_list;
	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	*begin_list = NULL;
}
