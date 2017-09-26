/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:30:22 by jblancha          #+#    #+#             */
/*   Updated: 2017/06/29 01:25:26 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		ft_read_next_line(const int fd, char **buf, char **pos)
{
	int		count;
	char	*lec;
	char	*temp;

	if (!(lec = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	count = 1;
	while ((!(*pos = ft_strchr(*buf, '\n')) && (count > 0)))
	{
		count = read(fd, lec, BUFF_SIZE);
		lec[count] = '\0';
		if (!(temp = ft_strjoin(*buf, lec)))
		{
			ft_memdel((void **)&lec);
			return (-1);
		}
		ft_memdel((void **)buf);
		*buf = temp;
	}
	ft_memdel((void **)&lec);
	return (count);
}

int		ft_treat_file(const int fd, char **line, char **buf)
{
	char			*pos;
	int				ret;
	char			*temp;

	ret = ft_read_next_line(fd, buf, &pos);
	if (ret == -1)
	{
		ft_memdel((void **)buf);
		return (-1);
	}
	if (pos)
	{
		temp = ft_strsub(*buf, (unsigned int)(pos - *buf + 1), *buf +
				ft_strlen(*buf) - pos + 1);
		*line = ft_strsub(*buf, 0, pos - *buf);
		ft_memdel((void **)buf);
		*buf = temp;
		return (1);
	}
	ret = 0;
	*line = ft_strdup(*buf);
	if (ft_strlen(*buf) > 0)
		ret = 1;
	**buf = '\0';
	return (ret);
}

t_file	*getfile(t_list **lst, const int fd)
{
	t_list		*lst1;
	t_list		*lst2;
	t_file		*fl1;

	lst1 = *lst;
	while (lst1)
	{
		fl1 = (t_file *)(lst1->content);
		if (fl1->fd == fd)
			return ((t_file *)fl1);
		lst1 = lst1->next;
	}
	fl1 = (t_file *)ft_memalloc(sizeof(t_file));
	fl1->fd = fd;
	fl1->buf = ft_strnew(BUFF_SIZE + 1);
	lst1 = ft_lstnew(fl1, sizeof(t_file));
	ft_lstadd(lst, lst1);
	ft_memdel((void **)&fl1);
	return ((t_file *)lst1->content);
}

void	ft_delfile(t_list **lst, const int fd)
{
	t_list		*lst1;
	t_list		*lst2;
	t_file		*fl1;
	int			trouve;

	lst1 = *lst;
	trouve = 0;
	while (lst1 && !(trouve))
	{
		fl1 = (t_file *)(lst1->content);
		if (fl1->fd == fd)
		{
			ft_memdel((void **)(&fl1->buf));
			ft_lstdelmaillon(lst, lst1);
			trouve = 1;
		}
		if (!trouve)
			lst1 = lst1->next;
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_file			*file;
	int				ret;

	if ((fd < 0) || (!line) || (BUFF_SIZE <= 0))
		return (-1);
	file = getfile(&lst, fd);
	ret = ft_treat_file(fd, line, &(file->buf));
	if (ret != 1)
		ft_delfile(&lst, fd);
	return (ret);
}
