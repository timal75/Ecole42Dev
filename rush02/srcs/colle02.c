/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikacumi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 16:04:18 by ikacumi           #+#    #+#             */
/*   Updated: 2016/09/17 22:03:00 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print(int h, int v, int x, int y)
{
	if ((h == 0 && v == 0) || (h == x - 1 && v == y))
		ft_putchar('A');
	else if ((h == x - 1 && v == 0) || (h == x && v == y - 1))
		ft_putchar('A');
	else if (v == y - 1 && h == 0)
		ft_putchar('C');
	else if (h == x - 1 && v == y - 1)
		ft_putchar('C');
	else if (h == 0 || v == 0 || h == x - 1 || v == y - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	colle(int x, int y)
{
	int h;
	int v;

	v = 0;
	while (v < y)
	{
		while (h < x)
		{
			print(h, v, x, y);
			h++;
		}
		ft_putchar('\n');
		h = 0;
		v++;
	}
}
