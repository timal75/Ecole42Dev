/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 23:23:12 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/07 15:27:09 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		k;

	k = 1;
	while (k <= argc - 1)
	{
		while (*argv[k] != '\0')
		{
			ft_putchar(*argv[k]);
			argv[k]++;
		}
		k++;
		ft_putchar('\n');
	}
	return (0);
}
