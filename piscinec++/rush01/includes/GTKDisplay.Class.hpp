/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GTKDisplay.Class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:48:30 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/22 16:48:33 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GTKDisplay_H
# define GTKDisplay_H

#include <ft_gkrellm.hpp>

class GTKDisplay : public IMonitorDisplay {

			public :
						GTKDisplay(ModuleList module);
						~GTKDisplay(void);
						void 	ShowWindow(void);

            private :
            			GTKDisplay(void);
            			GTKDisplay(GTKDisplay const &gtk);
            			GTKDisplay &operator=(GTKDisplay const &gtk);

            protected :

};

#endif