/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:50:58 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/09 21:53:48 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact {

public : 

	Contact(void);
	~Contact(void);
	void Increasenbcontact();
	void SetContact (std::string buf, int i); 
	void infosearch (int i);
	void printinfo (void) ;
	static int	getnbcontact(void);
private :

	std::string	_prenom;
	std::string _nom;
	std::string _nickname;
	std::string _login;
	std::string _postaladress;
	std::string _mail;
	std::string _phone;
	std::string _birthday;
	std::string _meal;
	std::string _underwearcolor;
	std::string _secret;
	static 	int	_nb_contact;
};

#endif
