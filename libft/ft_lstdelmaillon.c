/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelmaillon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:00:10 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/28 16:34:40 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelmaillon(t_list **begin_list, t_list *lst)
{
	t_list	*prev;
	t_list	*next;

	if (begin_list && *begin_list)
	{
		prev = *begin_list;
		next = prev->next;
		if (prev == lst)
		{
			*begin_list = next;
			free(prev->content);
			free(lst);
			return;
		}
		while (next)
		{
			if (next == lst)
			{
				prev->next = next->next;
				free(next->content);
				free(next);
				return;
			}
			prev = next;
			next = prev->next;
		}
	}
}
