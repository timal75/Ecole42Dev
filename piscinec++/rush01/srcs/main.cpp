/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:52:27 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/21 21:44:19 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_gkrellm.hpp>

int		main (int argc, char **argv)
{
	Options			option;
	
	option = getOptions(argc, argv);
	if (option['h'])
	{
		printHelp();
		return (0);
	}

	ModuleList						modules = fillModules(option);
	GTKDisplay						gdk(modules);

	if (option['g'])
	{
		gtk_init(&argc, &argv);
		gdk.ShowWindow();
	}
	else
	{
		NcursesDisplay 	*display = new NcursesDisplay();
		display->init();
		display->initWindows(modules);

	}
	return EXIT_SUCCESS;
}

