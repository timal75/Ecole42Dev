/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:04:03 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/16 19:48:29 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name (""), _gradetosign(150), _gradetoex(150), _issigned(false) 
{
}

Form::Form(std::string name, int gradetosign , int gradetoex) : _name(name), _gradetosign(gradetosign), _gradetoex(gradetoex) , _issigned(false)
{
	if (gradetosign < 1 || gradetoex < 1)
		throw (Form::GradeTooHighException ());
	if (gradetosign > 150 || gradetoex > 150)
		throw (Form::GradeTooLowException ());
}

Form::~Form(void)
{
}

Form::Form(Form const &frt)
{
	*this = frt;
}

Form &Form::operator=(Form const &frt)
{
	this->_name = frt._name;
	this->_gradetosign = frt._gradetosign;
	this->_gradetoex = frt._gradetoex;
	this->_issigned = frt._issigned;
	return (*this);
}

int Form::getGradetosign(void) const
{
	return (this->_gradetosign);
}

int Form::getGradetoex(void) const
{
	return (this->_gradetoex);
}

bool Form::issigned(void) const
{
	return (this->_issigned);
}

void Form::beSigned(Bureaucrat const &bur)
{
	if (this->_issigned)
		throw (Form::AlreadySignedException ());
	if (bur.getGrade() <= this->_gradetosign)
		this->_issigned = true;
	else
		throw (Form::GradeTooLowException ());
}

void Form::execute(Bureaucrat const &bur)
{
	if (!this->_issigned)
		throw (Form::NotSignedException ());
	if (bur.getGrade() <= this->_gradetosign)
		this->action ();
	else
		throw (Form::GradeTooLowException ());
}

std::string Form::getName(void) const
{
	return (this->_name);
}

Form::GradeTooHighException::GradeTooHighException(void)  
{
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &Ex)  
{
	*this = Ex; 
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(GradeTooHighException const &)  
{
	return (*this); 
}

Form::GradeTooHighException::~GradeTooHighException(void) throw () 
{
}

Form::GradeTooLowException::GradeTooLowException(void)  
{
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &Ex)  
{
	*this = Ex; 
}

Form::GradeTooLowException::~GradeTooLowException(void) throw () 
{
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(GradeTooLowException const &)  
{
	return (*this); 
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form " << rhs.getName() << " Grade to sign " << rhs.getGradetosign() << " Grade to execute " << rhs.getGradetoex() << (rhs.issigned() ? " signed " : " not signed yet")<< std::endl;
	return o;
}

Form::AlreadySignedException::AlreadySignedException(void)  
{
}

Form::AlreadySignedException::AlreadySignedException(AlreadySignedException const &Ex)  
{
	*this = Ex; 
}

Form::AlreadySignedException &Form::AlreadySignedException::operator=(AlreadySignedException const &)  
{
	return (*this); 
}

Form::AlreadySignedException::~AlreadySignedException(void) throw () 
{
}

Form::NotSignedException::NotSignedException(void)  
{
}

Form::NotSignedException::NotSignedException(NotSignedException const &Ex)  
{
	*this = Ex; 
}

Form::NotSignedException &Form::NotSignedException::operator=(NotSignedException const &)  
{
	return (*this); 
}

Form::NotSignedException::~NotSignedException(void) throw () 
{
}
