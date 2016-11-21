/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 23:02:18 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/15 23:02:21 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_get_size(char *filename)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		size_file;

	size_file = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		size_file += ret;
	}
	close(fd);
	return (size_file);
}
