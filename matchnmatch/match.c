/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 22:27:33 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/11 23:38:58 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	match(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s1 == *s2 && *s1 != '*')
		return (match(s1 + 1, s2 + 1));
	else if (*s2 == '*' && *s1)
		return (match(s1 + 1, s2));
	else
		return (0);
}
int 	main (void)
{
	char		*tab1;
	char		*tab2;

	tab1 = "abutgu";
	tab2 = "ab*u";
	printf("retour : %d\n",match(tab1,tab2));
}

