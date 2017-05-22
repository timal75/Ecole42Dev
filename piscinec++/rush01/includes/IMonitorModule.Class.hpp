/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.Class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:39:54 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/22 02:04:23 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMonitorModule_H
# define IMonitorModule_H

#include <ft_gkrellm.hpp>

class IMonitorModule {

		public :

					virtual ~IMonitorModule (void) {};
					virtual const std::string  &getTitle (void) const = 0;
					virtual const int &getType (void) const = 0;
					virtual const StringList &getContent (void) const = 0;
					virtual const int &getHeight (void) const =0;

					virtual void	setTitle(std::string title) = 0;
					virtual void	setType(int type) = 0;
					virtual void	setContent(StringList content) = 0;
					virtual void	setHeight(int height) = 0;
					virtual std::string	 toString(void) const = 0;

		private :

		protected :

					std::string 	_title;
					StringList 		_content;
					int		   		_height;
					int		   		_type;

};

#endif
