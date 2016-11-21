/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:39:48 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/05 19:58:36 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	main(int argc, char **argv)
{
	int		fc;
	char	c;
	int		ret;

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fc = open(argv[1], O_RDONLY);
		if (fc)
		{
			while ((ret = read(fc, &c, 1)) > 0)
				write(1, &c, 1);
			close(fc);
		}
		else
			write(2, "File can not be read\n", 21);
	}
	return (0);
}
