/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:11:46 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/09 21:58:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

Contact::Contact (void)
{
}

Contact::~Contact (void)
{
}

void Contact::Increasenbcontact(void)
{
	_nb_contact++;
}

void Contact::SetContact (std::string buf, int i) 
{
	if (i == 0)
		this->_prenom = buf;
	if (i == 1)
		this->_nom = buf;
	if (i == 2)
		this->_nickname = buf;
	if (i == 3)
		this->_login = buf;
	if (i == 4)
		this->_postaladress = buf;
	if (i == 5)
		this->_mail = buf;
	if (i == 6)
		this->_phone = buf;
	if (i == 7)
		this->_birthday = buf;
	if (i == 8)
		this->_meal = buf;
	if (i == 9)
		this->_underwearcolor = buf;
	if (i == 10)
		this->_secret = buf;
}

void Contact::printinfo()
{
	std::cout <<"=================================================================\n";
	std::cout <<"=                                                               =\n";
	std::cout <<"=                     CONTACT INFO                              =\n";
	std::cout <<"=                                                               =\n";
	std::cout <<"=================================================================\n\n";
	std::cout <<"Contact First Name ===> "<< this->_prenom << std::endl;	
	std::cout <<"\nContact Last Name ===> "<< this->_nom << std::endl;	
	std::cout <<"\nContact Nickname ===> "<< this->_nickname << std::endl;	
	std::cout <<"\nContact Login ===> "<< this->_login << std::endl;	
	std::cout <<"\nContact Postal Adress ===> "<< this->_postaladress << std::endl;	
	std::cout <<"\nContact Mail Adress ===> "<< this->_mail << std::endl;	
	std::cout <<"\nContact Phone Number ===> "<< this->_phone << std::endl;	
	std::cout <<"\nContact Birthday ===> "<< this->_birthday << std::endl;	
	std::cout <<"\nContact Favourite Meal ===> "<< this->_meal << std::endl;	
	std::cout <<"\nContact Underwear Color ===> "<< this->_underwearcolor << std::endl;	
	std::cout <<"\nContact Darkest Secret ===> "<< this->_secret << std::endl;	
	std::cout <<"\n\n\n" ;	
}
void Contact::infosearch(int i )
{
	std::cout << std::right << std::setw(10) << i << " | ";
	if (this->_prenom.length() > 10)
		std::cout << std::right << std::setw(10) << this->_prenom.substr(0, 9).append(".")<< " | ";	
	else
		std::cout << std::right << std::setw(10) << this->_prenom.substr(0, 10) << " | ";
	if (this->_nom.length() > 10)
		std::cout << std::right << std::setw(10) << this->_nom.substr(0, 9).append(".") <<" | ";
	else
		std::cout << std::right << std::setw(10) << this->_nom.substr(0, 10) << " | ";
	if (this->_nickname.length() > 10)
		std::cout << std::right << std::setw(10) << this->_nickname.substr(0, 9).append(".") << std::endl;
	else
		std::cout << std::right << std::setw(10) << this->_nickname.substr(0, 10) << std::endl;
}

int	Contact::getnbcontact(void)
{
	return(Contact::_nb_contact);
}

int 	Contact::_nb_contact = 0;
