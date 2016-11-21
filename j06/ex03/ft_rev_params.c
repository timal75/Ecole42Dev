/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 15:44:05 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/07 23:29:29 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		k;

	k = argc -1;
	while (k > 0)
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

