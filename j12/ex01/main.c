/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:58:34 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/15 22:15:54 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#define BUF_SIZE 10

void	affiche_error(char *str, char *str2)
{
	write(2, "cat: ", 5);
	write(2, str2, ft_strlen(str2));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int		ft_error(int ac)
{
	if (ac == 1)
	{
		write(2, "File name mising.\n", 19);
		return (1);
	}
	return (0);
}

void	ft_bad_name(char *str)
{
	write(2, "cat: ", 5);
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory\n", 28);
}

int		traitement_fichier(char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*str;

	errno = 0;
	fd = open(*av, O_RDONLY);
	if (fd == -1)
		ft_bad_name(*av);
	else
	{
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			if (ret == -1)
			{
				str = strerror(errno);
				affiche_error(str, *av);
				return (errno);
			}
			buf[ret] = '\0';
			write(1, buf, ret);
		}
		close(fd);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		x;

	if (ft_error(ac))
		return (1);
	av++;
	while (*av)
	{
		x = traitement_fichier(av);
		av++;
	}
	return (errno);
}
