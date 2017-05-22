/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:57:45 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 17:39:38 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include "Form.hpp" 

class ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &frt);
		~ShrubberyCreationForm (void);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &frt);
		void action (void) const;


	private :
		std::string _target;

	protected :
};
#endif
