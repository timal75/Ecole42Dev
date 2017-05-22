/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.Class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:39:31 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/21 22:39:39 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMonitorDisplay_H
# define IMonitorDisplay_H

#include <ft_gkrellm.hpp>

class IMonitorDisplay {

			public :
                        IMonitorDisplay(void) {};
						virtual ~IMonitorDisplay(void) {}

    					// virtual void    init(void) = 0;
    					// virtual void    restore(void) = 0;

    					// virtual void    displayWindow(Position p, IMonitorModule *module, int h, int w, int color) = 0;
    					// virtual void    displayText(Position p, std::string const &text, int color) = 0;
    					// virtual void    displayUnit(Position p, std::string const &text, std::string const &unit, int color) = 0;
    					// virtual void    displayBarChart(GraphList graphs) = 0;
    					// virtual void    displaySprite(Position p, StringList list, int h, int w, int color) = 0;

    					// virtual void    updateWindow(IMonitorModule *module) = 0;
    					// virtual void    deleteWindow(std::string const &title) = 0;

    					// virtual void    initWindows(std::list<IMonitorModule *> const &windows) = 0;

            private :

            protected :
                        StringList _content;

};

#endif
