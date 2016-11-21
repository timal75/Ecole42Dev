/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 23:31:40 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/07 23:44:14 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		k;
	int		k;

	k = 1;
	j = 1;
	while (k <= argc )
	{
		while (j <= argc)
		{
			while (*argv[k] != '\0')
		{
			ft_putchar(*argv[k]);
			argv[k]++;
		}
		k--;
		ft_putchar('\n');
	}
	return (0);
}

