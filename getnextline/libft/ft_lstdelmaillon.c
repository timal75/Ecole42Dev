/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelmaillon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:00:10 by jblancha          #+#    #+#             */
/*   Updated: 2017/04/20 20:08:45 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_delfirst(t_list **begin_list, t_list *lst)
{
	t_list	*prev;
	t_list	*next;

	prev = *begin_list;
	next = prev->next;
	if (prev == lst)
	{
		*begin_list = next;
		free(prev->content);
		free(lst);
		return (0);
	}
	return (1);
}

void	ft_lstdelmaillon(t_list **begin_list, t_list *lst)
{
	t_list	*prev;
	t_list	*next;

	if (begin_list && *begin_list)
	{
		if (ft_delfirst(begin_list, lst))
		{
			prev = *begin_list;
			next = prev->next;
			while (next)
			{
				if (next == lst)
				{
					prev->next = next->next;
					free(next->content);
					free(next);
					return ;
				}
				prev = next;
				next = prev->next;
			}
		}
	}
}
