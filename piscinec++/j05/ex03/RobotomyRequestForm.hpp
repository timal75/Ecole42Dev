/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:57:45 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 17:43:07 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include "Form.hpp" 

class RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &frt);
		~RobotomyRequestForm (void);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &frt);
		void action (void) const;


	private :
		std::string _target;

	protected :
};
#endif
