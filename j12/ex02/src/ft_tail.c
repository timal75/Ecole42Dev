/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 23:02:31 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/15 23:02:34 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdio.h"

void	ft_tail(int ac, char *avi, int size, int *cpt)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		ret;
	char	*buf_temp;
	int		size_file;

	if (ft_check_badname(avi))
	{
		size_file = ft_get_size(avi);
		fd = open(avi, O_RDONLY);
		if (size < size_file)
		{
			buf_temp = (char*)malloc(sizeof(char) * (size_file - size + 1));
			read(fd, buf_temp, size_file - size);
			free(buf_temp);
		}
		ft_put_filename(ac, avi, cpt);
		while ((ret = read(fd, buf, BUF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		(*cpt)++;
	}
}
