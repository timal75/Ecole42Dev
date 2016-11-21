/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:51:37 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/19 18:56:59 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list	*next;
	t_list	*lst;

	if ((alst) && (new))
	{
		lst = (*alst)->next;
		next = (*alst)->next;
		while (next)
		{
			lst = next;
			next = lst->next;
		}
		lst->next = new;
		new->next = NULL;
	}
}
