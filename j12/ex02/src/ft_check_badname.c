/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_badname.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 23:02:48 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/15 23:02:51 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdio.h"

int		ft_check_badname(char *avi)
{
	int fd;

	fd = open(avi, O_RDONLY);
	if (fd == -1)
	{
		write(2, "tail: ", 6);
		write(2, avi, ft_strlen(avi));
		write(2, ": No such file or directory\n", 27);
		return (0);
	}
	close(fd);
	return (1);
}
