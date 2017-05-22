/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:00:58 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/21 22:01:30 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMonitorModule_H
# define IMonitorModule_H

#include <ft_gkrellm.hpp>

class IMonitorModule {

		public :

					virtual ~IMonitorModule ();
					virtual std::string const &getTitle(void) const = 0;
					virtual int const &getDisplayType (void) const = 0;
					virtual const StringList &getContent (void) const = 0;
					virtual const StringList &getHeight (void) const =0;

					virtual void	setTitle(std::string title) = 0;
					virtual void	setType(int type) = 0;
					virtual void	setContent(StringList content) = 0;
					virtual void	setHeight(int height) = 0;
					virtual std::string	 toString(void) const = 0;

		private :

		protected :

					StringList _content;
					int		   _height;
					int		   _display;

};

#endif
