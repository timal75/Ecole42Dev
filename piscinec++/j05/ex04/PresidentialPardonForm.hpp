/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:57:45 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 20:13:56 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include "Form.hpp" 

class PresidentialPardonForm : public Form
{

	public:

		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &frt);
		~PresidentialPardonForm (void);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &frt);
		void action (void) const;


	private :
		std::string _target;

	protected :
};
#endif
